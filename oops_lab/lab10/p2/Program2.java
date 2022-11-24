import java.util.*;

public class Program2 {
	public static int area(int a) {
		return a * a;
	}

	public static int area(int a, int b) {
		return a * b;
	}

	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			System.out.print("Enter the edge length of square: ");
			int a = sc.nextInt();
			System.out.println("Square Area: " + area(a));
			System.out.print("Enter length and breadth of rectangle: ");
			int b = sc.nextInt();
			int c = sc.nextInt();
			System.out.println("Area of rectangle: " + area(b, c));
			sc.close();
		} catch (InputMismatchException b) {
			System.out.println("Input message mismatch exception occured");
		} finally {
			System.out.println("Code cleaned up");
		}
	}
}
