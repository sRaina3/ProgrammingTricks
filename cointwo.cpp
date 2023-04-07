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
    vector<vector<long long>> combos(coin_cnt + 10, vector<long long>(goal + 1));
    for (int i = 0; i < coin_cnt + 1; i++) {
      for (int j = 0; j < goal + 1; j++) {
        combos[i][j] = 0;
      }
    }
    for (int i = 0; i < coin_cnt; i++) {
      int cur_coin;
      cin >> cur_coin;
      coins[i] = cur_coin;
    }
    combos[0][0] = 1;

    for (int i = 1; i < coin_cnt + 1; i++) {
      for (int j = 0; j < goal + 1; j++) {
        combos[i][j] = combos[i - 1][j];
        if (j >= coins[i - 1]) {
          combos[i][j] += combos[i][j - coins[i - 1]];
          combos[coin_cnt][goal] % ((long long)pow(10,9) + 7);
        }
      }
    }
    cout << combos[coin_cnt][goal] % ((long long)pow(10,9) + 7);
}