import java.util.Scanner;

public class L2 {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        System.out.println("Enter first interger: ");
        int num1 = cin.nextInt();
        System.out.println("Enter second interger: ");
        int num2 = cin.nextInt();
        System.out.println("Enter a string: ");
        String str = cin.next();
        System.out.println("Enter another string");
        String str2 = cin.next();
        System.out.println("Sum: "+(num1+num2)+"\nDifference: "+(num1-num2)+"\nProduct: "+(num1*num2)+"\nIs equal: "+(num1==num2)+"\nIs not equal: "+(num1!=num2)+"\nIs greater: "+(num1>num2
        )+"\nIs lesser: "+(num1<num2)+"\nAND result: "+((num1<0)&(num2>0))+"\nOR result: "+((num1<0)|(num2>0))+"\nConcated string is: "+str+" "+str2+"\nAND result: "+((num1<0)&&(num2>0))+"\n" + //
                "OR result: \"+((num1<0)|(num2>0))+");
        cin.close();
    }
}
