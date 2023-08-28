package Lab4;
import java.util.Scanner;
public class switchCase {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        switch(name){
            case "Nahid":
                System.out.println("First Name");
            break;

            case "Hasan":
                System.out.println("Middle Name");
            break;

            case "Arif":
                System.out.println("Last Name");
            break;
            
            case "Nahid Hasan Arif":
                System.out.println("Full Name");
            break;
            
            default :
                System.out.println("Not my name");
            break;
        }
        sc.close();
    }
}
