#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
 
int main() {
  int r;
  int c;
  cin >> r >> c;
  char field[r][c];
  char in;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> in;
      field[i][j] = in;
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (field[i][j] == 'S') {
        if (i-1 > -1 && field[i-1][j] == 'W' ) {
          cout << "No";
          return 0;
        }
        if (i+1 < r && field[i+1][j] == 'W' ) {
          cout << "No";
          return 0;
        }
        if (j-1 > -1 && field[i][j-1] == 'W' ) {
          cout << "No";
          return 0;
        }
        if (j+1 < c && field[i][j+1] == 'W' ) {
          cout << "No";
          return 0;
        }

        if (i-1 > -1 && field[i-1][j] == '.') {
          field[i-1][j] = 'D';
        }
        if (i+1 < r && field[i+1][j] == '.') {
          field[i+1][j] = 'D';
        }
        if (j-1 > -1 && field[i][j-1] == '.') {
          field[i][j-1] = 'D';
        }
        if (j+1 < c && field[i][j+1] == '.') {
          field[i][j+1] = 'D';
        }
      } 
    }
  }

  cout <<  "Yes\n";
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << field[i][j];
    }
    cout << "\n";
  }
}