#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  long long int numStick;
  cin >> numStick;
  vector<long long int> lengths;
  long long int total;
  for (long long int i = 0; i < numStick; i++) {
    long long int curLen = 0;
    cin >> curLen;
    total += curLen;
    lengths.push_back(curLen);
  }
  sort(lengths.begin(), lengths.end());
  long long int median = lengths[lengths.size() / 2];
  long long int ans = 0;
  for (long long int i = 0; i < numStick; i++) {
    long long int cur = lengths[i];
    ans += abs(cur - median);
  }
  cout << ans;
  
}