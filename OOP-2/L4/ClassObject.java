//package Lab4;
class calc{
    int area(int height, int width){
        return height*width;
    }
}

public class ClassObject {
    public static void main(String[] args) {
        //ClassObject object = new ClassObject();
        
        calc obj = new calc();
        
        System.out.println("Area is: "+obj.area(40,50));
        
    }
}
