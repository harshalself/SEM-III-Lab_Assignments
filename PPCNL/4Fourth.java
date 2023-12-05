// NAME : HARSHAL PATIL
// ROLL NO : 44 

import java.util.Scanner;

class Figure {
    double dimension1;
    double dimension2;

    public Figure(double dimension1, double dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }

    public double area() {
        System.out.println("Area method in the Figure class.");
        return 0.0;
    }
}

class Rectangle extends Figure {
    public Rectangle(double length, double width) {
        super(length, width);
    }

    @Override
    public double area() {
        return dimension1 * dimension2;
    }
}

class Triangle extends Figure {
    public Triangle(double base, double height) {
        super(base, height);
    }

    @Override
    public double area() {
        return 0.5 * dimension1 * dimension2;
    }
}

public class Fourth {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter length of rectangle: ");
        double length = scanner.nextDouble();

        System.out.print("Enter width of rectangle: ");
        double width = scanner.nextDouble();

        Rectangle rectangle = new Rectangle(length, width);
        System.out.println("Area of Rectangle: " + rectangle.area());

        System.out.print("\nEnter base of triangle: ");
        double base = scanner.nextDouble();

        System.out.print("Enter height of triangle: ");
        double height = scanner.nextDouble();

        Triangle triangle = new Triangle(base, height);
        System.out.println("Area of Triangle: " + triangle.area());
    }
}
