class Parent {
    public final String finalVar = "final variable";

    Parent(String val){
        System.out.println(val + " constructor");
    }

    public final void finalMethod() {
        System.out.println("Parent: final method");
    }

    public void nonFinalMethod() {
        System.out.println("Parent: non-final method");
    }
}

class Child extends Parent {
    public String nonFinalVar = "non-final variable";
    
    Child(String val){
        super(val);
    }
    public void nonFinalMethod() {
        System.out.println("Child: non-final method");
    }

    public void show() {
        nonFinalVar += " value";
        System.out.println("Parent: " + super.finalVar);
        System.out.println("Child: " + nonFinalVar);
        super.finalMethod();
        super.nonFinalMethod();
        nonFinalMethod();
    }
}

public class Main {
    public static void main(String[] args) {
        Child obj = new Child("Parent:");
        obj.show();
    }
}