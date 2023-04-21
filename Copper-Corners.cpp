#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int dim;
  cin >> dim;
  int ans = 0;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      int cur;
      cin >> cur;
      if (i == 0 && j == 0 || i == dim - 1 && j == 0 || i == 0 && j == dim -1 || i == dim - 1 && j == dim -1) {
        ans += cur;
      }
    }
  }
  cout << ans;
}