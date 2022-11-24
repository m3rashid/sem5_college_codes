class Base {
	Base() {
		System.out.println("Base class constructor called");
	}
}

class Inherited {
	Inherited() {
		System.out.println("Inherited class constructor called");
	}

	void run(String n) {
		System.out.println(n);
	}
}

public class Program1 {
	public static void main(String[] args) {
		Inherited inherited = new Inherited();
		String a = "I am running";
		inherited.run(a);
	}
}
