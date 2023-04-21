#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  for (int i = 0; i < s1.length() - s2.length() + 1; i++) {
    bool works = true;
    if (s1[i] == s2[0]) {
      for (int j = i; j < i + s2.length(); j++) {
        if (s1[j] != s2[j - i]) {
          works = false;
        }
      }
      if (works) {
        ans++;
      }
    }
  }
  cout << ans;
}