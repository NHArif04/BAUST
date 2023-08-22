### Objective:

- To demonstrate different loop constructs, switch-case statements, continue, and break in Java programming.
- To illustrate the concept of efficient binary manipulation using bitwise left and right shift operations.
- To explain the purpose and significance of using the static keyword in the main function.

### Introduction:

Control structures and bitwise operations are fundamental elements in programming, dictating program flow and optimizing binary manipulations. This lab report showcases the implementation of loops, switch-case statements, continue, and break, along with the efficiency of bitwise shifts. Additionally, it provides a concise explanation of the static keyword's purpose in the context of the main function.

### Source Code:

```java
import java.util.Scanner;

public class ControlBitwiseLab {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer: ");
        int n = scanner.nextInt(), sum = 0, num = 1;
        System.out.println("Odd numbers from 1 to 10 using for loop and continue:");
        for (int i = 1; i <= 10; i++) {
            if (i % 2 == 0) {
                continue;
            }
            System.out.print(i + " ");
        }

        while (num <= n) {
            sum += num;
            num++;
        }
        System.out.println("\nUsing while loop sum of numbers from 1 to " + n + ": " + sum);

        System.out.print("Enter a number between 1 and 3: ");
        num = scanner.nextInt();
        switch (num) {
            case 1:
                System.out.println("One");
                break;
            case 2:
                System.out.println("Two");
                break;
            case 3:
                System.out.println("Three");
                break;
            default:
                System.out.println("Other");
        }

        System.out.println("Do While Loop:");
        int i = 1;
        do {
            System.out.println(i);
            i++;
        } while (i <= 5);

        System.out.println("Bitwise shift operations");
        int numForShift = 10;
        int leftShift = numForShift << 1, rightShift = numForShift >> 1;
        System.out.println("Left shift by 1: " + leftShift + ", Right shift by 1: " + rightShift);
        scanner.close();
    }
}
```

### Output:

```Python
Enter a positive integer: 4
Odd numbers from 1 to 10 using for loop and continue: 1 3 5 7 9
Using while loop sum of numbers from 1 to 4: 10
Enter a number between 1 and 3: 2
Two
Do While Loop:
1
2
3
4
5
Bitwise shift operations
Left shift by 1: 20, Right shift by 1: 5
```

### Discussion:

The program demonstrates several control structures in Java, including for loops, while loops, do-while loops, and switch-case statements. Additionally, it showcases bitwise shift operations. The continue statement is used to skip even numbers in the loop, and the static keyword is used to define the main method as the entry point for program execution.

### Conclusion:

Through this lab experiment, we gained practical experience in using various control structures and bitwise operations in Java programming. We observed the effectiveness of loops and switch statements in managing program flow and decision-making. Furthermore, we understood how bitwise shift operations can efficiently manipulate binary values. This knowledge is crucial for building well-structured and efficient programs.
