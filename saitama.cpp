#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> lanterns;

int main() {
  int num_lant;
  cin >> num_lant;
  lanterns.resize(num_lant);
  for (int i = 0; i < num_lant; i++) {
    int cur_power;
    int cur_pos;
    cin >> cur_power >> cur_pos;
    pair<int,int> pair = make_pair(cur_power, cur_pos);
    lanterns.push_back(pair);
  }

  int min_destroyed = num_lant;
  for (int i = 0; i < num_lant; i++) {
    int cur_destroyed = solver();
    if (min_destroyed > cur_destroyed) {
      min_destroyed = cur_destroyed;
    }
  }
  cout << min_destroyed;
}

int solver() {
  int counter = 0;
  for (int i = lanterns.size() - 1; i > -1; i--) {
    int cur_pos = lanterns[i].first;
    int cur_pow = lanterns[i].second;
    
  }
}
