# Lab Report: Object-Oriented Java Concepts

## Experiment Name: Exploring Core Object-Oriented Concepts

**Objective:**
- To understand essential object-oriented programming (OOP) concepts in Java.
- To learn about the `this` pointer, function overloading, function overriding, inheritance, constructors, and polymorphism.
- To apply these concepts through practical code and output.

## Introduction:
This lab report explores the core concepts of object-oriented programming using Java. We will learn about the `this` pointer, function overloading, function overriding, inheritance, constructors, and polymorphism.

## Description:

- ### The `this` Pointer:
  The `this` pointer in Java refers to the current object. It allows objects to access their own attributes and distinguish them from local variables or parameters.

- ### Function Overloading:
  Function overloading allows multiple methods with the same name to be defined in a class, with different parameter lists. Java distinguishes between these methods based on the types and order of parameters.

- ### Function Overriding:
  Function overriding occurs when a subclass provides its own implementation of a method already in its superclass. The overridden method has the same name, return type, and parameters as the superclass method.

- ### Inheritance:
  Inheritance allows a subclass to inherit attributes and methods from a superclass. It encourages code reuse and the formation of class hierarchies.

- ### Constructors:
  Constructors in Java are special methods that create objects. They have the same name as the class and initialize the object's state.

- ### Polymorphism:
  Polymorphism allows objects of different classes to be treated as instances of the same class through a shared interface. This enables code flexibility and the use of diverse object types interchangeably.

## Source Code:

```java
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
```

## Sample Output:
```shell
Parent Class
Child Class -> inherited
Override
Overload
```

## Discussion:
This experiment introduced us to the core concepts of object-oriented programming in Java. The `this` pointer, method overloading, method overriding, inheritance, constructors, and polymorphism are important tools for creating dynamic and efficient code.

## Conclusion:
Object-oriented programming offers many possibilities for code reuse and flexibility. By understanding these core concepts, developers can create powerful Java applications.