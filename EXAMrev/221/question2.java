/**Exception**/
public class HelloWorld{
    public static void b(){
        throw new NullPointerException();
    }
    public static void a(){
        try{b();}
        catch(IndexOutOfBoundsException e){
            System.out.println("a");
        }
    }
     public static void main(String []args){
        try{
            a();   //print out main
        }catch(NullPointerException e){
            System.out.println("main");
        }
     }
}



public class HelloWorld{
    
     public static void main(String []args){
        try{
            throw new NullPointerException();
        }catch(NullPointerException e){
            System.out.println("Problem");
        }
             System.out.println("final");
        /**same finally*/
     }
}

public static void main(String []args){
        try{
            throw new NullPointerException();
        }catch(NullPointerException e){
            throw e;
        } finally{
            System.out.println("final");
        }
        /**no finally then unreach*/     
        
     }


public class HelloWorld{
    
     public static void main(String []args){
        try{
            throw new NullPointerException();
        }catch(IndexOutOfBoundsException e){
            System.out.println("Problem");
        }finally{
            System.out.println("final");
        }
             
        /**different without finally*/
     }
}