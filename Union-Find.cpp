#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int bear_cnt;
	cin >> bear_cnt;
  vector<int> bears(bear_cnt + 2);
  // Test
  bears.push_back(-1);
	for(int i = 0; i < bear_cnt; i++) {
    int cur_b;
    cin >> cur_b;
    bears[i + 1] = cur_b;
  }

  vector<int> rvals(bear_cnt + 2);
  vector<int> lvals(bear_cnt + 2);
  rvals.push_back(-1);
  lvals.push_back(-1);
  int end = bear_cnt - 1;
  int start = 0;
  while (end > -1 && start < bear_cnt) {
    rvals[end + 1] = end + 2;
    for (int i = 0; i < bear_cnt; i++) {
      if (bears[rvals[end + 1]] < bears[end + 1]) {
        break;
      } else {
        rvals[end + 1] = rvals[rvals[end + 1]];
      }
    }
    lvals[start + 1] = start;
    for (int i = 0; i < bear_cnt; i++) {
      if (bears[lvals[start + 1]] < bears[start + 1]) {
        break;
      } else {
        lvals[start + 1] = lvals[lvals[start + 1]];
      }
    }
    end--;
    start++;
  }

  vector<int> output(bear_cnt + 2);
  output.push_back(-1);
	for (int i = 0; i < bear_cnt; i++) {
    int maxMin = -1;
	  maxMin += rvals[i + 1] - lvals[i + 1];
    if (maxMin < 1) {
      maxMin = rvals[i + 1];
    }
    if (bears[i + 1] > output[maxMin]) {
      output[maxMin] = bears[i + 1];
    }
	}

	for (int curPos = bear_cnt - 2; curPos > -1; curPos--) {
    if (output[curPos + 1 ] < output[curPos + 2]) {
      output[curPos + 1] = output[curPos + 2];
    }
	}

	for (int i = 0; i < bear_cnt; i++) {
	  cout << output[i + 1];
    if (i < bear_cnt - 1) {
      cout << " ";
    }
  }
}