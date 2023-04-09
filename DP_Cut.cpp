#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
  int len;
  int p1;
  int p2;
  int p3;
  cin >> len >> p1 >> p2 >> p3;
  int maxs[len + 1];
  maxs[0] = 0;
  for (int i = 1; i < len + 1; i++) {
    maxs[i] = -1 * INT_MAX;
    bool cuttable = false;
    int temp1 = -1 * INT_MAX;
    int temp2 = -1 * INT_MAX;
    int temp3 = -1 * INT_MAX;
    if (i >= p1) {
      cuttable = true;
      temp1 = maxs[i-p1];
    }
    if (i >= p2) {
      cuttable = true;
      temp2 = maxs[i-p2];
    }
    if (i >= p3) {
      cuttable = true;
      temp3 = maxs[i-p3];
    }
    if (cuttable) {
      temp1 = max(temp1,temp2);
      temp1 = max(temp1,temp3);
      maxs[i] = temp1 + 1;
    }
  }
  cout << maxs[len];
}
