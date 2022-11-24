class A {
	void run() {
		System.out.println("Base class method called");
	}
}

class B extends A {
	void run() {
		System.out.println("Inherited class method called");
	}
}

public class Program3 {
	public static void main(String[] args) {
		A a = new B();
		a.run();
	}
}
