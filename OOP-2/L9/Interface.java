interface A{
    public static final int x=0;

    // A(){}; interface does't have a body

    public abstract void a();
    abstract void b();
    // static b2();     //static method cannot be abstract
    // default b3();    //default method cannot be abstract 
    default void show(){
        System.out.println("implemented using default keyword in interface");
    }

    static void show2(){
        System.out.println("implemented using static keyword in interface");
    }

    /* final void show3(){          //interface can not have final method
        System.out.println("implemented using final keyword in interface");
    } */
}

interface B{
    // public void a();         //it will work but => since A, B holds same method then it will perform same task
    // public void b();         //since it is from another
    public void c();
    public void d();
}

class C implements A, B{
    public void a(){
        System.out.println("implemented interface A->a() in C");
    }
    public void b(){
        System.out.println("implemented interface A->b() in C");
    }

    public void c(){
        System.out.println("implemented interface B->c() in C");
    }
    public void d(){
        System.out.println("implemented interface B->d() in C");
    }

    /* static void show2(){         //static method can be overridden by only by static methods
        System.out.println("implemented using static keyword in interface");
    } */
    // static b2(){}
}

public class Interface {
    public static void main(String[] args) {
        // A objA = new A();  //since interface is incomplete so it cannot create any instance/object 
        // B objB = new B();  //since interface is incomplete so it cannot create any instance/object 
        C objC = new C();
        objC.a();
        objC.b();
        objC.c();
        objC.d();
        objC.show();
        // objC.show2();   //static method is unable to inherit
        A.show2();          //static can be directly access by using class name
    }
}
