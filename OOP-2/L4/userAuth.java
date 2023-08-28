package Lab4;
import java.util.Scanner;
public class userAuth{
    public static void main(String[] args) {
        String user, pass;
        Scanner sc = new Scanner(System.in);
        System.out.println("Registration:");
        System.out.print("Enter Your User Name: ");
        user = sc.next();
        System.out.print("Enter Password: ");
        pass = sc.next();
        System.out.println("Login:");
        String userLog, passLog;
        System.out.flush();
        System.out.print("Enter Your User Name: ");
        userLog = sc.next();
        System.out.print("Enter Password: ");
        passLog = sc.next();
        System.out.flush();
        if((userLog.equals(user)) && (passLog.equals(pass))){
            System.out.println("Welcome");
        }
        else{
            System.out.println("You are not registered");
        }
        sc.close();
    }
}
