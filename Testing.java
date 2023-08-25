import java.util.ArrayList;
import java.util.Collections;

public class Testing {

	public static void main(String[] args) {
    int a = 20;
    int b = a;
    a += 5;
    System.out.println("a: " + a + "   b: " + b);
    Shape aa = new Shape(5, 3);
    Shape bb = new Shape(4, 4);
    //bb = aa;
    bb.setHeight(12);
    System.out.println("aa: " + aa.getHeight() + "   bb: " + bb.getHeight());


    ArrayList<Integer> arr = new ArrayList<>();
    arr.add(12);
    ArrayList<Integer> arr2 = new ArrayList<>();
    arr2 = arr;
    arr2.add(4);
    System.out.println(arr.toString());
	}

}

class Shape {
  private int width;
  private int height;

  public Shape(int w, int h) {
    width = w;
    height = h;
  }

  public int getWidth() {
    return width;
  }

  public void setWidth(int w) {
    width = w;
  }

  public int getHeight() {
    return height;
  }

  public void setHeight(int h) {
    height = h;
  }
}
