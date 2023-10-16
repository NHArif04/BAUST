# Lab Report: Access Modifiers in Java

## Objectives:
1. To comprehend the role of access modifiers in Java.
2. To explore how access modifiers influence class member accessibility.
3. To create classes with distinct access levels and observe their behavior.
4. To understand the importance of access modifiers in Java programming.

## Introduction:
This lab report delves into the concept of access modifiers in Java, an essential aspect of controlling class member visibility. Access modifiers determine how classes and their members can be accessed and manipulated. By implementing classes with different access modifiers and observing their behavior in various packages, we aim to grasp the significance of access modifiers in Java programming.

## Description:

### Understanding Access Modifiers:
Access modifiers in Java are keywords that define the visibility and accessibility of class members. We examine three primary access modifiers:

- **Private**: Limits member access to the same class.
- **Protected**: Allows access within the same class and its subclasses.
- **Public**: Permits access from any class.

### Implementation:
We've created distinct classes with various access modifiers and observed their behavior in different packages. This practical implementation will help us understand how access modifiers affect class member access.

## Source Code:

### Different.java (Package: different)
```java
package different;

public class Different {
    private void privateMethod() {
        System.out.println("Private Method in Different");
    }

    protected void protectedMethod() {
        System.out.println("Protected Method in Different");
    }

    public void publicMethod() {
        System.out.println("Public Method in Different");
    }
}
```

### Same.java (Package: same)
```java
package same;

public class Same extends Different {
    private void privateMethod() {
        System.out.println("Private Method in Same");
    }

    protected void protectedMethod() {
        System.out.println("Protected Method in Same");
    }

    public void publicMethod() {
        System.out.println("Public Method in Same");
    }
}
```

### Sub.java (Package: same)
```java
package same;

import different.Different;

public class Sub extends Different {
    // Subclass code here
}
```

### Main.java (Package: main)
```java
package main;

import same.Sub;

public class Main {
    public static void main(String[] args) {
        Sub obj = new Sub();
        obj.publicMethod();
        obj.protectedMethod();
    }
}
```

## Output:
```
Public Method in Same
Protected Method in Different
```

## Discussion:
This lab effectively demonstrates the utilization of access modifiers in Java. By creating classes with distinct access levels and extending them, we observed how private, protected, and public members behave. Access modifiers are crucial for encapsulation and controlling class member visibility, facilitating the development of well-structured and secure Java applications.

## Conclusion:
Understanding access modifiers is essential in Java programming. It empowers developers to manage class member visibility and accessibility, contributing to the creation of secure and well-structured Java applications.