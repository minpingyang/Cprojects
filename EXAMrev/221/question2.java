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

/**java Puzzle*/
public class Exercise{
    
    static Integer t2 = new Integer(1);//add
    static Exercise t1 = new Exercise(); //run constructor  ---> i1 =null = t2
     Integer i1; //add null
    public Exercise(){
        i1 = t2;

    }
    int f(){return i1;}
    
     public static void main(String []args){
       System.out.println(t1.f());
        
     }
}


import java.lang.String;
public class Final{
    public static void main(String[] a){
        final String pig = "length: 10";
       
        final String dog = "length: "+pig.length(); 
        boolean t = dog == pig;
        System.out.println("dd"+(dog == pig)); //ddfalse
        System.out.println("dd"+dog == pig); //false
    }
}
