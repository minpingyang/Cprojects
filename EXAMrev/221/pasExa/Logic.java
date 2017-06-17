// A variable holding a logic (i.e. boolean) value
class LogicVar {
  private boolean value;
	
  public LogicVar(boolean value) { this.value = value; }
	
  public boolean get() { return value; }

  public void set(boolean value) { this.value = value; }
} 

// A logic gate reads two inputs and writes one output
abstract class LogicGate {
  private LogicVar[] variables = new LogicVar[3];

  public LogicGate(LogicVar in1, LogicVar in2, LogicVar out) {
    variables[0] = in1;
    variables[1] = in2;
    variables[2] = out;
  }
  public void evaluate() {
    boolean in1 = variables[0].get();
    boolean in2 = variables[1].get();
    variables[2].set(evaluate(in1,in2));
  }
  public abstract boolean evaluate(boolean in1, boolean in2);
}

// If both inputs true, out is true; othewise, out is false.
class AndGate extends LogicGate {
  public AndGate(LogicVar v1, LogicVar v2, LogicVar v3) {
      super(v1,v2,v3);
  }
  public boolean evaluate(boolean in1, boolean in2) {
      return in1 && in2;
} }

// If either input is true, out is true; othewise, out is false.
class OrGate extends LogicGate {
  public OrGate(LogicVar v1, LogicVar v2, LogicVar v3) {
      super(v1,v2,v3);
  }    
  public boolean evaluate(boolean in1, boolean in2) {
      return in1 || in2;
} }

public class Logic {

    public static void question1() {
	LogicVar v1 = new LogicVar(true);
	System.out.println(v1.get());
    }
    
    public static void question2() {
	LogicVar v1 = new LogicVar(false);
	LogicVar v2 = new LogicVar(true);
	LogicVar v3 = new LogicVar(true);
	LogicGate gate = new AndGate(v1,v2,v3);
	gate.evaluate();	
	System.out.println(v1.get() + " " + v2.get() + " " + v3.get());
    }
    
    public static void question3() {
	LogicVar v1 = new LogicVar(true);
	LogicVar v2 = new LogicVar(false);
	LogicGate gate = new OrGate(v1,v2,v2);
	gate.evaluate();
	System.out.println(v1.get() + " " + v2.get());
    }
    
    public static void question4() {
	LogicVar v1 = new LogicVar(true);
	LogicVar v2 = new LogicVar(false);
	LogicVar v3 = new LogicVar(false);
	LogicGate gate1 = new OrGate(v1,v2,v3);
	LogicGate gate2 = new AndGate(v3,v2,v1);
	gate1.evaluate();
	gate2.evaluate();
	System.out.println(v1.get() + " " + v2.get() + " " + v3.get());	
    }
    
    public static void question5() {
	LogicVar v1 = new LogicVar(false);
	LogicVar v2 = new LogicVar(true);
	LogicVar v3 = new LogicVar(true);
	LogicGate gate = new AndGate(v1,v2,v3);
    }
    
    public static void main(String[] args) {
	question1();
	question2();
	question3();
	question4();	
    }
}
    
