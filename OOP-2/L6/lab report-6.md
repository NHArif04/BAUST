# Lab Report: Multilevel Inheritance and Constructor Sequences in Java

## Objectives:
1. To comprehend multilevel inheritance.
2. To investigate the sequence of constructor calls in multilevel inheritance.
3. To observe multilevel inheritance through code execution.
4. To assess the significance of constructor sequences in object-oriented programming.

## Introduction:
This lab delves into multilevel inheritance and the ordered execution of constructors in Java. Multilevel inheritance facilitates the creation of class hierarchies, while constructor sequences ensure proper object initialization.

## Description:

**Multilevel Inheritance:** Java supports multilevel inheritance, allowing a class to inherit from a base class, which in turn can be the base for another class. This establishes a hierarchical chain of inheritance.

**Constructor Calling Sequence:** In multilevel inheritance, constructors are invoked in a specific order: starting from the base class and moving to the derived classes. This meticulous sequence guarantees the correct initialization of objects.

## Source Code:
```java
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
```

**Combined Output:**
```
Grandparent
Parent
Child
```

## Discussion:
Multilevel inheritance facilitates the creation of intricate class hierarchies, enhancing code reusability. Constructor sequences play a pivotal role in ensuring proper object initialization, contributing to the robustness of object-oriented programs.

## Conclusion:
This lab provided concise insights into multilevel inheritance and constructor sequences. Multilevel inheritance empowers the creation of class hierarchies, and constructor sequences guarantee precise object initialization, fundamental for designing efficient and organized code.

---
