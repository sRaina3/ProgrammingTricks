#include <iostream>
using namespace std;


int main () {
  int num_nums;
  cin >> num_nums;
  for (int i = 0; i < num_nums; i++) {
    int count = 0;
    int num;
    cin >> num;
    int cur = 1;
    while (cur*cur < num) {
      if (num % cur == 0) {
        count++;
      }
      cur++;
    }
    count *= 2;
    if (cur != 1 && cur*cur == num) {
      count++;
    }
    if (cur == 1) {
      count = 1;
    }
    cout << count << "\n";
    
  }
}