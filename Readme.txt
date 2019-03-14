Step 1: Write a Java Class HelloJNI.java that uses C Codes

public class HelloJNI {  // Save as HelloJNI.java
   static {
      System.loadLibrary("HelloJNI"); 
   }
 
   // Declare an instance native method sayHello() which receives no parameter and returns void
   private native void sayHello();
 
   // Test Driver
   public static void main(String[] args) {
      new HelloJNI().sayHello();  // Create an instance and invoke the native method
   }
}


Step 2: Compile the Java Program HelloJNI.java & Generate the C/C++ Header File HelloJNI.h

javac -h . HelloJNI.java


Step 3: Implementing the C Program HelloJNI.cpp

// Save as "HelloJNI.c"
#include <iostream>
#include "HelloJNI.h"   // Generated
 
using namespace std;

// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
    cout << "std: Hello World, JNI!" << endl;
    return;
}


Step 4: Compile the C program HelloJNI.cpp

Create Project in VS
Set config:
    Output to .dll
    Include jni headers: C:\Program Files\Java\jdk-10.0.2\include\win32;C:\Program Files\Java\jdk-10.0.2\include;%(AdditionalIncludeDirectories)
    Compile


Step 5: Run the Java Program

Open windows cmd (not in VS Code)

java -Djava.library.path=./HelloJNI/x64/Debug HelloJNI

java -Djava.library.path=./TestJNIPrimitive/x64/Debug TestJNIPrimitive

java -Djava.library.path=./TestJNIString/x64/Debug TestJNIString

java -Djava.library.path=./TestJNIPrimitiveArray/x64/Debug TestJNIPrimitiveArray

java -Djava.library.path=./TestJNIInstanceVariable/x64/Debug TestJNIInstanceVariable

java -Djava.library.path=./TestJNIStaticVariable/x64/Debug TestJNIStaticVariable

java -Djava.library.path=./TestJNICallBackMethod/x64/Debug TestJNICallBackMethod

java -Djava.library.path=./TestJavaConstructor/x64/Debug TestJavaConstructor

java -Djava.library.path=./TestJNIObjectArray/x64/Debug TestJNIObjectArray

java -Djava.library.path=./TestJNIReference/x64/Debug TestJNIReference




Tips:
1. Get Signature:
javap --help
javap -s -p TestJNICallBackMethod
.......
private void callback();
   Signature: ()V

private void callback(java.lang.String);
   Signature: (Ljava/lang/String;)V

private double callbackAverage(int, int);
   Signature: (II)D

private static java.lang.String callbackStatic();
   Signature: ()Ljava/lang/String;