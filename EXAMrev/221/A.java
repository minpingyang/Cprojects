/**print out b is false 
javac A.java
java A
**/
public class A{
    public static boolean b;
     public static void main(String []args){
       assert b;
       System.out.println("b is "+b);
        
     }
}


/**java.lang.AssertionError
javac A.java
java A
**/

/*if no assertion erro then,print out b is true */
public class A{
    public static boolean b;
     public static void main(String []args){
       assert b;   //java.lang.AssertionError
       System.out.println("b is "+b);
        
     }
}
/*java A **/
/**print out b is null **/
public class HelloWorld{
    public static Boolean b;
     public static void main(String []args){
       assert b;
       System.out.println("b is "+b);
        
     }
}
/*java -ea A **/
/**java.lang.NullPointerException **/
public class Exercise{
    public static Boolean b;
     public static void main(String []args){
       assert b;
       System.out.println("b is "+b);
        
     }
}


/**print out b is true **/
public class Exercise{
    public static Boolean b=true;
     public static void main(String []args){
       assert b;
       System.out.println("b is "+b);
        
     }
}