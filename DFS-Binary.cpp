#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
  int num;
  cin >> num;
  char s[num];
  for (int i = 0; i < num; ++i) {
    s[i] = '0';
  }
  int ind = num - 1;
  for (int i = 0; i < pow(2,num); ++i) {
    cout << s;
    s[ind] = '1';
    ind--;
    cout << "\n";
  }
}