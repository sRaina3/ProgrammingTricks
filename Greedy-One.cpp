#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int d;
  int sumTime;
  cin >> d;
  cin >> sumTime;
  int min = 0;
  int max = 0;
  vector<int> mins;
  vector<int> maxs;
  for (int i = 0; i < d; i++) {
    int low;
    int high;
    cin >> low;
    cin >> high;
    min += low;
    max += high;
    mins.push_back(low);
    maxs.push_back(high);
  }
  if (min <= sumTime && sumTime <= max) {
    cout << "YES\n";
    int timeSave = sumTime - min;
    for (int i = 0; i < d; i++) {
      int min = mins[i];
      int max = maxs[i];
      int curSave = max - min;
      if (curSave <= timeSave) {
        timeSave -= curSave;
        cout << min + curSave;
      } else {
        cout << min + timeSave;
        timeSave = 0;
      }
      cout << " ";
    }
  } else {
    cout << "NO";
  }
}