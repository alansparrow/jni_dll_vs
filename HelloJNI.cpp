// Save as "HelloJNI.c"
#include <iostream>
#include "HelloJNI.h"   // Generated
 
using namespace std;

// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
    cout << "std: Hello World, JNI!" << endl;
    return;
}