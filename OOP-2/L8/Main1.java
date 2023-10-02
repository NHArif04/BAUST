package L8;
class A{
    int x = 30;
    final String y = "Final will not";

    A(){
        System.out.println("Constructor A");
    }

    A(String s){
        System.out.println("Constructor A : "+s);
    }

    /* final void show(){
        System.out.println(y+" be overridden by other method");
    } */
}

/* class B extends A {
    B(){
        super();
    }

    B(String S){
        super(S);
    }
} */

public class main2 {
    public static void main() {
        System.out.println("Hello World");

        A objA = new A();
        //objA.show();

        A objA2 = new A("Overload");
        //objA2.show();

    }
}



