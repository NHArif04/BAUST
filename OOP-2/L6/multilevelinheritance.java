class Grandparent {
    Grandparent() {
        System.out.println("Grandparent");
    }
}

class Parent extends Grandparent {
    Parent() {
        System.out.println("Parent");
    }
}

class Child extends Parent {
    Child() {
        System.out.println("Child");
    }
}

public class multilevelinheritance {
    public static void main(String[] args) {
        Child childObj = new Child();
    }
}