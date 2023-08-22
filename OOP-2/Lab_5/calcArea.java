//package Lab4;
class calc {
    int areaRectangle(int height, int width) {
        return height * width;
    }
}

public class calcArea{

    public static void main(String[] args) {
        // ClassObject object = new ClassObject();

        calc obj = new calc();

        System.out.println("Area is: " + obj.areaRectangle(40, 50));

    }
}
