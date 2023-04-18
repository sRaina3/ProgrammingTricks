#include <iostream>
using namespace std;

int main () {
  int num;
  cin >> num;
  int checker = 4;
  while (checker < num) {
    bool v_one = false;
    bool v_two = false;
    for (int i = 2; i <= checker/2; i++) {
      if (checker % i == 0) {
        v_one = true;
      }
    }
    for (int i = 2; i <= (num-checker)/2; i++) {
      if ((num-checker) % i == 0) {
        v_two = true;
      }
    }
    if (v_one && v_two) {
      cout << checker << " " << num-checker;
      return 0;
    }
    checker++;
  }
  cout << "HUH?";
}