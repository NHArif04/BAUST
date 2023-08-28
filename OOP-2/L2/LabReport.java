import java.util.Scanner;

public class LabReport {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first integer: ");
        int num1 = scanner.nextInt();
        System.out.print("Enter second integer: ");
        int num2 = scanner.nextInt();
        System.out.print("Enter a string: ");
        String str = scanner.next();
        System.out.print("Enter another string: ");
        String str2 = scanner.next();
        System.out.println("Sum: " + (num1 + num2));                      // Arithmetic operations
        System.out.println("Difference: " + (num1 - num2));
        System.out.println("Product: " + (num1 * num2));
        System.out.println("Quotient: " + (num1 / num2));
        System.out.println("Remainder: " + (num1 % num2));
        System.out.println("Is equal: " + (num1 == num2));                 // Relational operations
        System.out.println("Is not equal: " + (num1 != num2));
        System.out.println("Is greater: " + (num1 > num2));
        System.out.println("Is lesser: " + (num1 < num2));
        System.out.println("AND result: " + ((num1 > 0) && (num2 > 0)));   // Logical operations
        System.out.println("OR result: " + ((num1 > 0) || (num2 > 0)));
        System.out.println("Concatenated String is: " + str+" "+str2);         // String operations
        scanner.close();
    }
}