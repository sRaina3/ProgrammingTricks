import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class GravityFlip {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		int cols = Integer.valueOf(s);
		ArrayList<Integer> vals = new ArrayList<Integer>(cols);
		for (int i = 0; i < cols; i++) {
			String next = scanner.next();
			vals.add(Integer.valueOf(next));
		}
		scanner.close();
		Collections.sort(vals);
		for (Integer x : vals) {
			System.out.print(x + " ");
		}

	}

}
