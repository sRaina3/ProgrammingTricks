#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int coin_cnt;
    int goal;
    cin >> coin_cnt >> goal;
    int coins[coin_cnt];
    vector<int> combos(goal + 1);
    for (int i = 0; i < coin_cnt; i++) {
      int cur_coin;
      cin >> cur_coin;
      coins[i] = cur_coin;
    }

    combos[0] = 1;
    for (int i = 0; i < coin_cnt; i++) {
      for (int j = 0; j < goal + 1; j++) {
        if (j - coins[i] > -1) {
          combos[j] += combos[j - coins[i]];
          combos[j] %= 1000000007;
        }
      }
    }
    cout << combos[goal];
}