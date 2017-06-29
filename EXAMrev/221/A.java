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

/***final */

public class Final{
    public Final(){ trickster();}
    void trickster(){
        System.out.println("1111111");
    }
    public static class Inner extends Final{
    	public int x,y = 123;   //x = 0 y =123 if static
    	public final int z = 456;
    	public void Inner(){ x+= 10;}
    	void trickster(){
            System.out.println("x: "+x);  //0
            System.out.println("y: "+y+"  z: "+z);
            x+=y+z;
        }
    }
    
    
     public static void main(String []args){
       System.out.println(new Inner().x);
        
     }
}
