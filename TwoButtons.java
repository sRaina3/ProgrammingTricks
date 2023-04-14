import java.util.Scanner;

public class TwoButtons {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int start = scanner.nextInt();
		int end = scanner.nextInt();
		scanner.close();
		if (start >= end) {
			System.out.println(start-end);
		} else {
			int steps = 0;
			while (end > start) {
				if (end % 2 != 0) {
					end += 1;
				} else {
					end /= 2;
				}
				steps += 1;
			}
			System.out.println(steps + start-end);
		}
		
	}

}