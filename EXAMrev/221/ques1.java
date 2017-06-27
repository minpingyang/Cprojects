public class HelloWorld{
    
    public static void moveBy(Point p, int dx, int dy){
        p.xpos += dx;
        p.ypos +=dy;
    }

     public static void main(String []args){
        ColouredPoint cp = new ColouredPoint();
        moveBy(cp,1,1);
        System.out.println("cp.xpos:  "+cp.xpos);
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