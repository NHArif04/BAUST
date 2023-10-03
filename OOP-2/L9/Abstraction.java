abstract class A{
    static int x=0;
    int y=10;

    A(){
        System.out.println("Class a constructor");
    }
    
    abstract void call1();
    
    void callMe(){
        System.out.println("Call me");
    }

    static void show(){
        System.out.println("show");
    }

    final void msg(){
        System.out.println("msg");
    }

    void set(int a){
        this.x = a;
    }
}

abstract class B extends A{
    abstract void call1(); // {System.out.println("call1 implement");}   //don't implement in abstract class. not preferable
}

class C extends B{
    void call1(){
        System.out.println("call1 implemented");
    } 

    void show(){
        System.out.println();
    }
}


public class Abstraction {
    public static void main(String[] arg){
        // A a = new A(); incomplete class cannot create object/instance
        A.show();       //static method/variable can be accessed without creating instances
        //A.x = 40;

        /* B obB = new B();     //since a is abstract instance cannot be created
        obB.set(50);
        obB.y= 90;
        obB.call1();
        obB.callMe();
        // B.callMe();  //non static method cannot be call without creating instances

        B obB2 = new B();
        obB2.y= 90;
        obB2.call1();
        obB2.callMe(); */

        C ob = new C();
        ob.y= 90;
        ob.call1();
        ob.callMe();
    }
}
