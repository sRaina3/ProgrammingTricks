#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Envelope {
  int insert_pos;
  int w;
  int h;
};

bool sorter(Envelope a, Envelope b) {
  if (a.w == b.w) {
    return a.h < b.h;
  }
  return a.w < b.w;
}

vector<Envelope> envelopes;
int dp[5001], preev[5001];

int main() {
  int env_count;
  int width;
  int height;
  cin >> env_count >> width >> height;

  for (int i = 0; i < env_count; i++) {
    int cur_width, cur_height;
    cin >> cur_width >> cur_height;
    if (cur_width > width && cur_height > height) {
      envelopes.push_back({i + 1, cur_width, cur_height});
    }
  }

  sort(envelopes.begin(), envelopes.end(), sorter);
  int max_size = 0, last = -1;
  for (int i = 0; i < envelopes.size(); i++) {
    dp[i] = 1;
    preev[i] = -1;
    for (int j = 0; j < i; j++) {
      if (envelopes[j].w < envelopes[i].w && envelopes[j].h < envelopes[i].h && dp[j]+1 > dp[i]) {
        dp[i] = dp[j]+1;
        preev[i] = j;
      }
    }
    if (dp[i] > max_size) {
      max_size = dp[i];
      last = i;
    }
  }

  cout << max_size << endl;

  if (max_size > 0) {
    vector<int> indices;
    while (last != -1) {
      indices.push_back(envelopes[last].insert_pos);
      last = preev[last];
    }
    reverse(indices.begin(), indices.end());
    for (int i = 0; i < indices.size(); i++) {
      cout << indices[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
