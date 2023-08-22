class A {
        public void show() {
            System.out.println("Class A");
        }
    }
    
    class overriding extends A {
        @Override
        public void show() {
            System.out.println("override");
        }
    }
public class Inheritance {
    public static void main(String[] args) {
        overriding obj = new overriding();
        obj.show();
    }
}
