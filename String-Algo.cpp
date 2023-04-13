#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main () {
  string s1;
  string s2;
  cin >> s1 >> s2;
  if (s1.length() > s2.length()) {
    swap(s1,s2);
  }
  int count = 0;
  for (int i = 1; i <= s1.length(); i++) {
    if (s1[i-1] != s2[i-1]) {
      break;
    }
    if (s1.length() % i == 0 && s2.length() % i == 0) {
      bool correct = true;
      string cur = s1.substr(0, i);
      string check;
      for (int j = 0; j < s1.length(); j++) {
        check = s1.substr(j, i);
        if (cur != check) {
          correct = false;
          break;
        }
        j += i - 1;
      }
      
      if (correct) {
        for (int k = 0; k < s2.length(); k++) {
          check = s2.substr(k, i);
          if (cur != check) {
            correct = false;
          }
          k += i - 1;
        }
      }
      if (correct) {
        count++;
      }
    }
  }
  cout << count;
}