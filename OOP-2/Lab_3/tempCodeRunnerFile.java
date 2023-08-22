import java.util.Scanner;
public class Fundamentals {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Enter Name: ");
        String name = scanner.nextLine();
        System.out.print("Enter CGPA: ");
        double cgpa = scanner.nextDouble();
        scanner.nextLine();
        System.out.println("ID: " + id + ", Name: " + name + ", CGPA: " + cgpa);
        System.out.print("\nEnter a word using next(): ");
        String word = scanner.next();
        System.out.print("Enter a line using nextLine(): ");
        scanner.nextLine();
        String line = scanner.nextLine();
        System.out.println("Word entered using next(): " + word);
        System.out.println("Line entered using nextLine(): " + line);
        int[] numbers = {10, 20, 30, 40, 50};
        int[][] unevenArray = new int[4][];
        for (int i = 0; i < unevenArray.length; i++) {
            unevenArray[i] = new int[i+1];
            for (int j = 0; j < i+1 ; j++) {
                unevenArray[i][j] = i+1;
            }
        }
        System.out.println("\nSingle-dimensional array:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println("\n\nUneven multidimensional array:");
        for (int i = 0; i < unevenArray.length; i++) {
            for (int j = 0; j < unevenArray[i].length; j++) {
                System.out.print(unevenArray[i][j] + " ");
            }
            System.out.println();
        }
        int a = 5;
        int b = 3;
        int c = 2;
        int d = 4;
        System.out.println("\nBitwise AND: " + (a & b));
        System.out.println("Bitwise OR: " + (c | d));
        System.out.println("Logical AND: " + (a > b && c > d));
        System.out.println("Logical OR: " + (a > b || c > d));
        scanner.close();
    }
}
