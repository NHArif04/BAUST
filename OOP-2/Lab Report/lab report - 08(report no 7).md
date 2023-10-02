## <mark>Lab Report: Understanding `final` and `super()` in Java</mark>

## Objectives:
1. Understand the purpose of `final` for variables and methods.
2. Explore how the `final` keyword is used in Java programming.
3. Investigate the role of the `super()` keyword in Java.
4. Analyze the practical applications of `super()` in Java code.

## Introduction:
This lab report delves into the concepts of `final` and `super()` in Java. The `final` keyword is used for declaring constants and unchangeable methods, while `super()` allows interaction with superclass elements.

## Description:

### `final` Keyword:
- **final Variables:** Declaring constants using `final`.
- **Final Methods:** Creating unalterable methods with `final`.

### `super()` Keyword:
- **Constructor:** Using `super()` to invoke superclass constructors.
- **Variable Access:** Accessing superclass variables with `super.variable`.
- **Method Invocation:** Invoking superclass methods, even if overridden, using `super.method()`.

## Source Code:
```java
class Parent {
    public final String finalVar = "final variable";

    Parent(String val){
        System.out.println(val + " constructor");
    }

    public final void finalMethod() {
        System.out.println("Parent: final method");
    }

    public void nonFinalMethod() {
        System.out.println("Parent: non-final method");
    }
}

class Child extends Parent {
    public String nonFinalVar = "non-final variable";
    
    Child(String val){
        super(val);
    }
    public void nonFinalMethod() {
        System.out.println("Child: non-final method");
    }

    public void show() {
        nonFinalVar += " value";
        System.out.println("Parent: " + super.finalVar);
        System.out.println("Child: " + nonFinalVar);
        super.finalMethod();
        super.nonFinalMethod();
        nonFinalMethod();
    }
}

public class Main {
    public static void main(String[] args) {
        Child obj = new Child("Parent:");
        obj.show();
    }
}
```

## Output:
```
Parent: constructor
Parent: final variable
Child: non-final variable value
Parent: final method
Parent: non-final method
Child: non-final method
```

## Discussion:
In this experiment, we explored the use of `final` for variables and methods, as well as the `super()` keyword for constructors, variable access, and method invocation. Understanding these concepts is crucial for developing robust Java applications.

## Conclusion:
This lab report provided insights into the usage of `final` and `super()` in Java. `final` ensures immutability, while `super()` facilitates interaction with the superclass, contributing to the creation of secure and well-structured code.
