## **Lab Report:** *Abstracts, Interfaces, and Methods*
## Objectives:
1. Understand abstract classes and their role in Java.
2. Explore interfaces and how they define contracts.
3. Implement abstract methods and interface methods.
4. Observe method behavior in abstract classes and interfaces.

## Introduction:
This lab report delves into abstract classes, interfaces, and method usage in Java. Abstract classes allow us to create class blueprints with abstract and non-abstract methods. Interfaces define contracts for classes to implement, including abstract and default methods. We'll explore these concepts and see how different types of methods behave.

## Description:
### Abstract Classes:
- Abstract classes are declared with the `abstract` keyword.
- They can contain abstract and non-abstract methods.
- Static and final methods can exist in abstract classes.
- Constructors can't create instances but can be present.

### Interfaces:
- Interfaces start with `interface`.
- They define a contract for implementing classes.
- Interfaces have abstract methods to be implemented.
- Default and static methods are supported.
- A class can implement multiple interfaces.

## Source Code:
```java
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
```

## Output:

```
Static method in A
Abstract method a implemented in B
Non-abstract method in A
Final method in A
Method e implemented in Z
Method h implemented in Z
Default method f in Y
Static method g in X
```

## Discussion:
This lab report explored the usage of abstract classes and interfaces in Java. It demonstrated abstract and non-abstract methods in abstract classes, as well as abstract, default, and static methods in interfaces. We observed the behavior of these methods in different contexts.

## Conclusion:
Understanding abstract classes and interfaces is essential for Java developers. These features enable code abstraction, reuse, and defining contracts for implementing classes. Different types of methods in both abstract classes and interfaces provide flexibility and code organization options.
```