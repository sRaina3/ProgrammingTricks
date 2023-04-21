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
  int KMPman[s2.length()] = {0};

  int j = 0;
  for (int i = 1; i < s2.length(); ++i) {
    while (j > 0 && s2[i] != s2[j]) {
      j = KMPman[j - 1];
    }
    if (s2[i] == s2[j]) {
      j++;
    }
    KMPman[i] = j;
  }

  int k  = 0;
  for (int i = 0; i < s1.length(); ++i) {
    while (k > 0 && s1[i] != s2[k]) {
      k = KMPman[k - 1];
    }
    if (s1[i] == s2[k]) {
      k++;
    }
    if (k == s2.length()) {
      k = KMPman[k - 1];
      ans++;
    }
  }
  cout << ans;
}