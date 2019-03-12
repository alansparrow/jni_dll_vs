#include "TestJNIPrimitiveArray.h"
 
JNIEXPORT jdoubleArray JNICALL Java_TestJNIPrimitiveArray_sumAndAverage
          (JNIEnv *env, jobject thisObj, jintArray inJNIArray) {
   // Step 1: Convert the incoming JNI jintarray to C's jint[]
   jint *inCArray = env->GetIntArrayElements(inJNIArray, NULL);
   if (NULL == inCArray) return NULL;
   jsize length = env->GetArrayLength(inJNIArray);
 
   // Step 2: Perform its intended operations
   jint sum = 0;
   int i;
   for (i = 0; i < length; i++) {
      sum += inCArray[i];
   }
   jdouble average = (jdouble) sum / length;
   env->ReleaseIntArrayElements(inJNIArray, inCArray, 0); // release resources
 
   jdouble outCArray[] = { (jdouble) sum, (jdouble) average};
 
   // Step 3: Convert the C's Native jdouble[] to JNI jdoublearray, and return
   jdoubleArray outJNIArray = env->NewDoubleArray(2);  // allocate
   if (NULL == outJNIArray) return NULL;
   env->SetDoubleArrayRegion(outJNIArray, 0 , 2, outCArray);  // copy
   return outJNIArray;
}