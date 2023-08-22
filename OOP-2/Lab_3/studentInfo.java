import java.util.Scanner;

public class studentInfo {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter You ID: ");
        int ID = scan.nextInt();
        System.out.println("Enter You Name: ");
        String Name =  scan.next();             //next() function to take separately string with "\n"
        System.out.println("Enter You CGPA: ");
        Float CGPA = scan.nextFloat();
        System.out.println("ID: "+ID+"\nName: "+Name+"\nCGPA: "+CGPA);
        scan.close();
    }
}
