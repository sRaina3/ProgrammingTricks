#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> lanterns;

int solver() {
  int counter = 0;
  int cur_pos = lanterns[lanterns.size() - 1].first;
  int cur_pow = lanterns[lanterns.size() - 1].second;
  for (int j = (lanterns.size() / 2) - 2; j > -1; j--) {
    int check_pos = lanterns[j].first;
    if (cur_pos - cur_pow > check_pos) {
      counter++;
    }
  }
  return counter;
}

int main() {
  int num_lant;
  cin >> num_lant;
  lanterns.resize(num_lant);
  for (int i = 0; i < num_lant; i++) {
    int cur_pos;
    int cur_power;
    cin >> cur_pos >> cur_power;
    pair<int,int> pair = make_pair(cur_pos, cur_power);
    lanterns.push_back(pair);
  }

  int min_destroyed = num_lant;
  int pos = 0;
  while (pos < num_lant) {
    int cur_left = solver();
    cout << cur_left << "\n";
    if (min_destroyed > num_lant - cur_left) {
      min_destroyed = num_lant - cur_left;
    }
    lanterns.pop_back();
    pos++;
  }
  cout << min_destroyed;
}
