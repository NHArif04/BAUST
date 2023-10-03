class A{
    int nonFinal = 99;
    final int final_ = 199;

    final void finalMethod(){
        //this.Final_ = 200;      //the final field cannot be assigned
        System.out.println("Super: Final Method\nVariable: "+final_);
    }

    void finalMethod(String val){
        System.out.println(val+" Final Overload");
    }

    void nonFinalMethod(){
        nonFinal = 100;
        System.out.println("Super: Non-Final Method\nVariable: "+nonFinal);
    }

    void display(){
        System.out.println("\nFrom Paren Class:");
        System.out.println("------------------------------------------");
        finalMethod();
    }
}

class B extends A{
    int nonFinal = 399;
    final int final_ = 299;         //different scope || final variable able can be overridden but value remains constant

    final void finalMethod(int a){        //method can be overridden if the parameter type 
        //this.Final_ = 300;      //the final field cannot be assigned
        System.out.println("Child: Final Method\nVariable: "+final_);
    }

    void nonFinalMethod(){
        nonFinal = 400;
        System.out.println("Super: Non-Final Method\nVariable: "+nonFinal);
    }

    void display(){
        super.display();        //super can be used when method already overridden
        super.finalMethod("Super:");        //final method can be overload but cannot be overridden
        super.nonFinalMethod();
        System.out.println("\n\n========================================");
        System.out.println("========================================\n");
        System.out.println("\nFrom Child Class:");
        System.out.println("Access Parent variable from child: "+super.final_);
        System.out.println("------------------------------------------");
        // this.finalMethod();       //cannot access a member of class 'B'
        this.finalMethod();         //this method is from parent class
        this.finalMethod(5);         //this method is from child class
        this.nonFinalMethod();
    }
}


public class superFinal{
    public static void main(String[] arg){
        B obj=new B();
        obj.display();
    }
}