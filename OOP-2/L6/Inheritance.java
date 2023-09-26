class Bangladesh{
    Bangladesh(int val){
        System.out.println("Bangladesh :"+val);
    }
}

class Dhaka extends Bangladesh{
    Dhaka(int val){
        super(val);
        System.out.println("Dhaka :"+val);
    }
}

class Mirpur extends Dhaka{
    Mirpur(int val){
        super(val);
        System.out.println("Mirpur: "+val);
    }
}
public class Inheritance{
    public static void main(String[] args){
        Mirpur obj(2000) = new Mirpur();

    }
}