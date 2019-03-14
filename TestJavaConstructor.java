public class TestJavaConstructor {
    static {
       System.loadLibrary("TestJavaConstructor");
    }
  
    // Native method that calls back the constructor and return the constructed object.
    // Return an Integer object with the given int.
    private native Integer getIntegerObject(int number);
  
    public static void main(String args[]) {
        TestJavaConstructor obj = new TestJavaConstructor();
        System.out.println("In Java, the number is :" + obj.getIntegerObject(9999));
    }
 }