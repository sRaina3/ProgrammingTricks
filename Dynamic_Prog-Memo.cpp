#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main () {
  int c_cnt;
  int goal;
  cin >> c_cnt >> goal;
  int coins[c_cnt];
  int mins[goal + 1];
  for (int i = 0; i < c_cnt; i++) {
    int cur_c;
    cin >> cur_c;
    coins[i] = cur_c;
  }
  mins[0] = 0;
  for (int i = 1; i < goal + 1; i++) {
    mins[i] = INT_MAX - 500;
  }

  for (int i = 0; i < c_cnt; i++) {
    for (int j = 0; j < goal + 1; j++) {
      if (j >= coins[i]) {
        mins[j] = min(mins[j], 1 + mins[j - coins[i]]);
      }
    }
  }

  if (mins[goal] == INT_MAX || mins[goal] < 0 || mins[goal] > 10000000) {
    cout << -1;
    return 0;
  }
  cout << mins[goal];
}