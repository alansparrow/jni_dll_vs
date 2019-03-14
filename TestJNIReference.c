#include <stdio.h>
#include "TestJNIReference.h"

// Global Reference to the Java class "java.lang.Integer"
static jclass classInteger;
static jmethodID midIntegerInit;

jobject getInteger(JNIEnv *env, jobject thisObj, jint number) {
    //printf("%s - env[%p]\n", __func__, env);

    // Get a class reference for java.lang.Integer if missing
   if (NULL == classInteger) {
      printf("Find java.lang.Integer\n");
      // FindClass returns a local reference
      jclass classIntegerLocal = (*env)->FindClass(env, "java/lang/Integer");
      // Create a global reference from the local reference
      classInteger = (*env)->NewGlobalRef(env, classIntegerLocal);
      // No longer need the local reference, free it!
      (*env)->DeleteLocalRef(env, classIntegerLocal);
   }
    if (NULL == classInteger) return NULL;

    // Get the Method ID of the Integer's constructor if missing
    if (NULL == midIntegerInit) {
        printf("Get Method ID for java.lang.Integer's constructor\n");
        midIntegerInit = (*env)->GetMethodID(env, classInteger, "<init>", "(I)V");
    }
    if (NULL == midIntegerInit) return NULL;

    //printf("%s - classInteger[%p] midIntegerInit[%p]\n", __func__, classInteger, midIntegerInit);
    // Call back constructor to allocate a new instance, with an int argument
    jobject newObj = (*env)->NewObject(env, classInteger, midIntegerInit, number);
    printf("In C, constructed java.lang.Integer with number %d\n", number);
    return newObj;
}

JNIEXPORT jobject JNICALL Java_TestJNIReference_getIntegerObject
(JNIEnv *env, jobject thisObj, jint number) {
    return getInteger(env, thisObj, number);
}

JNIEXPORT jobject JNICALL Java_TestJNIReference_anotherGetIntegerObject
(JNIEnv *env, jobject thisObj, jint number) {
    return getInteger(env, thisObj, number);
}