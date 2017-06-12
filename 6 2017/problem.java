/**
* Problem L: Problem with a ridiculously long name but with a ridiculously short description (lol)
* Status: YES
* Issue: Maths, Big Number, Modular Arithmetic
*/

import java.math.BigInteger;
import java.util.Scanner;

public class problem {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		String toPrint = "";
		while (t-- > 0) {
			String s = sc.nextLine();
			if (s.equals("0"))
				System.out.println(1);
			else if (s.equals("1"))
				System.out.println("66");
			else
				switch (s.charAt(s.length() - 1)) {
				case '0':
					System.out.println(76);
					break;
				case '1':
					System.out.println(16);
					break;
				case '2':
					System.out.println(56);
					break;
				case '3':
					System.out.println(96);
					break;
				case '4':
					System.out.println(36);
					break;
				case '5':
					System.out.println(76);
					break;
				case '6':
					System.out.println(16);
					break;
				case '7':
					System.out.println(56);
					break;
				case '8':
					System.out.println(96);
					break;
				case '9':
					System.out.println(36);
					break;
				}
		}

	}

}