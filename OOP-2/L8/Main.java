package L8;
interface new1 {
    void fun();
}
interface new2 extends new1{
    void fun1();
}

public class Main {
    new1 n = new new1();
}
