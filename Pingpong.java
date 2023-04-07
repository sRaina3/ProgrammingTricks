import java.util.Scanner;
import java.util.ArrayList;

public class Pingpong {
	
	static ArrayList<Integer> startVals;
	static ArrayList<Integer> endVals;
    
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int queryCount = scanner.nextInt();     
        startVals = new ArrayList<Integer>();
        endVals = new ArrayList<Integer>();
        
        for (int i = 0; i < queryCount; ++i) {
        	int type = scanner.nextInt();
            if (type == 1) {
                int start = scanner.nextInt();
                startVals.add(start);
                int end = scanner.nextInt();
                endVals.add(end);
            } else {
                int startInterval = scanner.nextInt();
                int goalInterval = scanner.nextInt();
                int[] reached = new int[100];
                getAllReachable(startInterval - 1, reached);
                
                if(reached[goalInterval - 1] == 1) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
        scanner.close();
    }
 
    public static void getAllReachable(int begin, int[] reached) {
    	int start = startVals.get(begin);
    	int end = endVals.get(begin);
    	
        if(reached[begin] == 0) {
        	reached[begin] = 1;
            for(int i = 0; i < startVals.size(); ++i) {
                if (startVals.get(i) < start && start < endVals.get(i) || startVals.get(i) < end && end < endVals.get(i)) {
                	getAllReachable(i, reached);
                }
            }
        }
    }
}