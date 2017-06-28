public class HelloWorld{
    
    public static void moveBy(Point p, int dx, int dy){
        p.xpos += dx;
        p.ypos +=dy;
    }

     public static void main(String []args){
        ColouredPoint cp = new ColouredPoint();
        moveBy(cp,1,1);
        System.out.println("cp.xpos:  "+cp.xpos);//1
     }
}

class Point{
    int xpos;
    int ypos;
}
class ColouredPoint extends Point{int colour;}

// – Here, parameter p has static type Point
// – But, p refers to object with dynamic type ColouredPoint
// – Can only access fields/methods exposed by static type of p
// – Behaviour is determined by the dynamic type of p, though

public class HelloWorld{
    
    public static void move(Point p){
       System.out.println("sdfsd");
    }
    public static void paint(ColouredPoint p){
      System.out.println("sdfsd");
    }

     public static void main(String []args){
        Coloured3DPoint c3p = new Coloured3DPoint();
        D3Point p3 = new D3Point();//work
        Point point = new Point(); //work
        paint(point); //doesnot work
        
     }
}

class Point{
    int xpos;
    int ypos;
}
class D3Point extends Point{int i;}
class ColouredPoint extends Point{int j;}
class Coloured3DPoint extends ColouredPoint{int x;}

/*
inheritance    
*/


/**overload metho**/
public class HelloWorld{

     public static void main(String []args){
        A x = new A();
        B y = new B();
        x.ame(); //print aa
        y.ame(); //print bb
    
     }
}
class A{
    void ame(){
        System.out.println("aa");
    }
}
class B{
     void ame(){
       System.out.println("bb");
    }
}




/**instanceof with heritance */

public class HelloWorld{

     public static void main(String []args){
        B x = new B();
        if(x instanceof A){  //print out
            System.out.println("1111");
        }
        //only  A not instanceof B
    
     }
}
class A{
    private int a;
    void ame(int x){
        int y = x+a;
        System.out.println("aa "+y);
    }
}
class B extends A{
    private int a;
     void ameT(int x){
         int y = x+a;
       System.out.println("bb "+y);
    }
}

/**parent ancenstor**/

public class HelloWorld{

     public static void main(String []args){
        A x = new C();
       
        System.out.println("A "+x.ame()); // print bbb
    
     }
}
class A{
 
    String ame(){
        return "aaa";
    }
}
class B extends A{
     String ame(){
        return "bbbb";
    }
}
class C extends B{
     String isAme(B b){
        return "ccccc";
    }
}

/**only method overload (same name & parameter)could be, A x =new B()   , for different method **/

public class HelloWorld{

     public static void main(String []args){
        A x = new B();
        String s = x.ame("1");//cant not the ame method in B
        System.out.println("A "+s);
    
     }
}
class A{
 
    String ame(String x){
        return "aaa"+x;
    }
}
class B extends A{
     String ame(int x){
        return "bbbb"+x;
    }
    String iSAme(){
        return "b2222";
    }
}
class C extends B{
    String isAme(){
        return "ccccc";
    }
}

/**slide7 14****/
public class HelloWorld{

     public static void main(String []args){
        A x = new A();
        A y = new B();
        x.ame(); //aa222
        y.ame();//bbbb
    
     }
}
class A{
    String ame2(){
        return "aaa222";
    }
    void ame(){
        System.out.println(ame2());
    }
}
class B extends A{
    String ame2(){
        return "bbbb";
    }
   
}

/**a is static parameter**/
public class HelloWorld{

     public static void main(String []args){
        A x = new A();
        A y = new B();
        B z = new B();
        x.ame(x);//aa1
        y.ame(y);//aa1
        z.ame(z);//bb1
    
     }
}
class A{
    void ame(A a){
        System.out.println("aa1");
    }
    void ame(B b){
        System.out.println("bb1");
    }
}
class B extends A{
  
}


/****static type decide class type**/
public class HelloWorld{

     public static void main(String []args){
        A x = new A();
        A y = new B();
        B z = new B();
        x.ame(z); //aa1
        y.ame(z); //aa1
        z.ame(z);//bb1
    
     }
}
class A{
    public void ame(A a){
        System.out.println("aa1");
    }
    
}
class B extends A{
    public void ame(B b){
        System.out.println("bb1");
    }
}