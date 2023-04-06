import java.util.Scanner;

public class Oil {

	static int size;
	static int k;
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		size = scanner.nextInt();
		k = scanner.nextInt();
		int start = 0;
		int end = size;
		while (start < end) {
			int mid = (start + end) / 2;
			if (possible(mid)) {
				end = mid;
			} else {
				start = mid + 1;
			}
		}
		System.out.println(start);
		
		scanner.close();

	}
	
	public static boolean possible(int num) {
		int exp = 0;
		int total = 0;
		while (num / (int)Math.pow(k, exp) != 0) {
			total += num / (int)(Math.pow(k,exp));
			exp++;
		}
		if (total >= size) {
			return true;
		}
		return false;
	}

}
