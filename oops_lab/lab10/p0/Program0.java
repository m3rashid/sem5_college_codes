import java.io.*;

class Program0 {
	public static void main(String[] args) throws IOException {
		BufferedReader obj = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter your name: ");
		String val = obj.readLine();
		System.out.println("Your name is " + val);
	}
}
