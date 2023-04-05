#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

long leftSide = 0;
long rightSide = 0;
long minDiff = LONG_MAX;

void recursion(vector<long> vals, long index);

int main() {
  long num;
  cin >> num;
  vector<long> vals;
  long val;
  for (long i = 0; i < num; ++i) {
    cin >> val;
    vals.push_back(val);
  }
  recursion(vals, 0);
  cout << minDiff;
}

void recursion(vector<long> vals, long index) {
  if (index == vals.size()) {
    if (leftSide - rightSide > -1 && leftSide - rightSide < minDiff) {
      minDiff = leftSide - rightSide;
    }
  } else {
    // Add to left side
    leftSide += vals[index];
    recursion(vals, index+1);
    // Remove from left side
    leftSide -= vals[index];
    // Add to right side
    rightSide += vals[index];
    recursion(vals, index+1);
    // Remove from right side
    rightSide -= vals[index];
  }
}