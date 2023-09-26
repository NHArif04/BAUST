class Rectangle {
    double length;
    double width;

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() {
        return length * width;
    }
}

public class calcArea {
    public static void main(String[] args) {
        Rectangle myRectangle = new Rectangle(5.0, 3.0);
        myRectangle.length=58;
        double rectangleArea = myRectangle.calculateArea();
        System.out.println("Rectangle area : " + rectangleArea);
    }
}