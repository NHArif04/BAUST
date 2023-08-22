import java.util.Scanner;

public class studentInformation {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter You ID: ");
        int ID = scan.nextInt();
        scan.nextLine(); // consume the newline character
        System.out.println("Enter You Name: ");
        String Name =  scan.nextLine();
        System.out.println("Enter You CGPA: ");
        Float CGPA = scan.nextFloat();
        System.out.println("ID: "+ID+"\nName: "+Name+"\nCGPA: "+CGPA);
        scan.close();
    }
}
