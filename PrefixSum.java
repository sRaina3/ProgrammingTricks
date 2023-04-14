import java.util.Scanner;

public class PrefixSum {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testCount = scanner.nextInt();
		int lineCount = 0;
		while (lineCount < testCount) {
			lineCount++;
			String s = scanner.next();
			int pos = 0;
			int onePos = -1;
			int twoPos = -1;
			int threePos = -1;
			int min = Integer.MAX_VALUE;
			while (pos < s.length()) {
				char cur = s.charAt(pos);
				if (cur == '1') {
					onePos = pos;
				} else if (cur == '2') {
					twoPos = pos;
				} else {
					threePos = pos;
				}
				if (onePos > -1 && twoPos > -1 && threePos > -1) {
					min = Math.min(min, Math.max(onePos, Math.max(twoPos, threePos)) - Math.min(onePos, Math.min(twoPos, threePos)) + 1);
				}
				pos++;
			}
			if (min != Integer.MAX_VALUE) {
				System.out.println(min);
			} else {
				System.out.println(0);
			}
		}
		scanner.close();

	}

}