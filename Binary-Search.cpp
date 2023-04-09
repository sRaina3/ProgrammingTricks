#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  long mCount;
  long goal;
  cin >> mCount;
  cin >> goal;
  vector<long long int> rates;
  long rate;
  for (long i = 0; i < mCount; ++i) {
    cin >> rate;
    rates.push_back(rate);
  }
  long long start = 0;
  long long int end = LONG_LONG_MAX;
  while (start < end) {
    long long int cur = 0;
    long long int mid = ((end - start) / 2) + start;
    for (long long int i : rates) {
      cur += mid / i;
      if (cur >= goal) {
        end = mid;
        break;
      }
    }
    if (cur < goal) {
      start = mid + 1;
    }
  }
  cout << start;
  return 0;
}