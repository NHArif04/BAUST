# Lab Report: Access Modifiers in Java

## Objectives:

1. Understand access modifiers in Java.
2. Explore access modifier usage.
3. Examine class member accessibility with access modifiers.
4. Demonstrate practical application through Java code.

## Introduction:

This lab report explores access modifiers in Java, which control the visibility and accessibility of class members. Classes with different access modifiers are implemented and demonstrated in various packages to emphasize the significance of access modifiers in Java.

## Description:

### Access Modifiers:

- Private, protected, and public access modifiers determine class member visibility.
- Private members are accessible only within the same class.
- Protected members are accessible within the same class and subclasses.
- Public members are accessible from any class.

### Access Modifier Table:

| Accessibility | Same Class | Same package but different class | different package and sub class | outside package |
| ------------- | ---------- | -------------------------------- | ------------------------------- | --------------- |
| Private       | Yes        | No                               | No                              | No              |
| Default       | Yes        | Yes                              | No                              | No              |
| Protected     | Yes        | Yes                              | Yes                             | No              |
| Public        | Yes        | Yes                              | Yes                             | Yes             |

## Source Code:

### Different.java (Package: different)

```java
package different;

public class Different {
    private void dShow1() {
        System.out.println("Private Different");
    }

    protected void dShow2() {
        System.out.println("Protected Different");
    }

    public void dShow3() {
        System.out.println("Public Different");
    }
}
```

### Same.java (Package: same)

```java
package same;

public class Same extends Different {
    private void sShow1() {
        System.out.println("Private Same");
    }

    protected void sShow2() {
        System.out.println("Protected Same");
    }

    public void sShow3() {
        System.out.println("Public Same");
    }
}
```

### Sub.java (Package: same)

```java
package same;

import different.Different;

public class Sub extends Different {
    //kicu akhane na likhleo hobe jodi issa hoy likhte paren
}
```

### Main.java (Package: main)

```java
package main;

import same.Sub;

public class Main {
    public static void main(String[] args) {
        Sub obj = new Sub();
        obj.sShow3();
        obj.dShow3();
    }
}
```

## Output:

```
Public Same
Public Different
```

## Discussion:

This lab effectively demonstrates the utilization of access modifiers in Java. By creating classes with distinct access levels and extending them, we observed how private, protected, and public members behave. Access modifiers are crucial for encapsulation and controlling class member visibility, facilitating the development of well-structured and secure Java applications.

## Conclusion:

Understanding access modifiers is essential in Java programming. It empowers developers to manage class member visibility and accessibility, contributing to the creation of secure and well-structured Java applications.
