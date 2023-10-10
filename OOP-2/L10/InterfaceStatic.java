class A {
    static void show() {
        System.out.println("Static method of A");
    }
}

class B extends A {
    void show2() {
        System.out.println("Normal method of B");
    }
}

public class InterfaceStatic{
    public static void main(String[] args) {
        B b = new B();
        b.show();
        b.show2();
    }
}
