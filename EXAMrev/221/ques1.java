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