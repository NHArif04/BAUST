abstract class A {
    abstract void a();
    void b() {
        System.out.println("Non-abstract method in A");
    }
    static void c() {
        System.out.println("Static method in A");
    }
    final void d() {
        System.out.println("Final method in A");
    }
}

class B extends A {
    void a() {
        System.out.println("Abstract method a implemented in B");
    }
}

interface X {
    void e();
    default void f() {
        System.out.println("Default method f in X");
    }
    static void g() {
        System.out.println("Static method g in X");
    }
}

interface Y extends X {
    void h();
    default void f() {
        System.out.println("Default method f in Y");
    }
}

class Z implements Y {
    public void e() {
        System.out.println("Method e implemented in Z");
    }
    public void h() {
        System.out.println("Method h implemented in Z");
    }
}

public class Main {
    public static void main(String[] args) {
        A.c();
        B b = new B();
        b.a();
        b.b();
        b.d();

        Z z = new Z();
        z.e();
        z.h();
        z.f(); 
        X.g();
    }
}