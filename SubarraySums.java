import java.util.Scanner;
import java.util.HashMap;

public class SubarraySums {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int size = scanner.nextInt();
		int target = scanner.nextInt();
		long ans = 0;
		long[] arr = new long[size];
		long[] psum = new long[size + 1];
		HashMap<Long, Long> map = new HashMap<>();
		psum[0] = 0;
		map.put((long)0, (long)1);
		int pos = 0;
		while (pos < size) {
			arr[pos] = scanner.nextLong();
			psum[pos + 1] = arr[pos] + psum[pos];
			if (map.containsKey(psum[pos+1] - target)) {
				ans += map.get(psum[pos+1] - target);
			}
			if (map.get(psum[pos+1]) != null) {
				map.put(psum[pos+1], map.get(psum[pos+1])+1);
			} else {
				map.put(psum[pos+1], (long)1);
			}
			pos++;
		}
		scanner.close();
		System.out.println(ans);
	}
	
}
