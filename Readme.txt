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