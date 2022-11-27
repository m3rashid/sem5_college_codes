abstract class Shape {
  int x, y;

  abstract void printArea();
}

class Rectangle extends Shape {
  Rectangle(int x, int y) {
    this.x = x;
    this.y = y;
  }

  void printArea() {
    System.out.println("Area of Rectangle: " + (x * y));
  }
}

class Triangle extends Shape {
  Triangle(int x, int y) {
    this.x = x;
    this.y = y;
  }

  void printArea() {
    System.out.println("Area of Triangle: " + (0.5 * x * y));
  }
}

class Circle extends Shape {
  Circle(int x) {
    this.x = x;
  }

  void printArea() {
    System.out.println("Area of Circle: " + (3.14 * x * x));
  }
}

class lab9 {
  public static void main(String[] args) {
    Shape s1 = new Rectangle(10, 20);
    Shape s2 = new Triangle(10, 20);
    Shape s3 = new Circle(10);
    s1.printArea();
    s2.printArea();
    s3.printArea();
  }
}