#include <jni.h>
#include <iostream>
#include <string>
#include "TestJNIString.h"
using namespace std;
 
JNIEXPORT jstring JNICALL Java_TestJNIString_sayHello(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   // Step 1: Convert the JNI String (jstring) into C-String (char*)
   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
   if (NULL == inCStr) return NULL;
 
   // Step 2: Perform its intended operations
   cout << "In C++, the received string is: " << inCStr << endl;
   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources
 
   // Prompt user for a C++ string
   string outCppStr;
   cout << "Enter a String: ";
   cin >> outCppStr;
 
   // Step 3: Convert the C++ string to C-string, then to JNI String (jstring) and return
   return env->NewStringUTF(outCppStr.c_str());
}