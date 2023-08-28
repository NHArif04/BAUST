class Parent {
    String str = "Parent Class";
    public void show() {
            System.out.println(this.str);
        }
}
class Child extends Parent {
    Child() {
        System.out.println("Child Class -> inherited");
    }

    @Override
    public void show() {
        System.out.println("Override");
    }

    public void show(String str) {
        System.out.println(str);
    }
}

public class OOP {
    public static void main(String[] args) {
        Parent obj1 = new Parent();
        obj1.show();
        Child obj = new Child();
        obj.show();
        obj.show("Overload");
    }
}

/* 
## Lab report for Lab 5

- This pointer
- function overloading
- function overriding
- inheritance
- constructor

Theory: 
what is polymorphism
This pointer
function overloading
function overriding
inheritance
constructor
 */