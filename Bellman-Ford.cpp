#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int numRoom;
int numTunnel;
long long int MAX_NUM = LLONG_MAX / 2;

struct tunnel {
	int start;
	int dest;
	int points;
};
	
vector<tunnel> tunnels;
 
void solver() {
  
}
 
int32_t main() {
	cin >> numRoom;
  cin >> numTunnel;
	for (int i = 0; i < numTunnel; i++) {
		tunnel curTun;
		cin >> curTun.start;
    curTun.start--;
    cin >> curTun.dest;
    curTun.dest--;
    cin >> curTun.points;
    // Future Note: Reverse Bellmand Ford
		curTun.points *= -1; 
		tunnels.push_back(curTun);
	}
	solver();
  return 0;
}