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
  vector<long long int> output(numRoom, MAX_NUM);
  output[0] = 0;
  
	for (int i = 0; i < numRoom; i++) {
		for (tunnel curTun: tunnels) {
			int s = curTun.start;
			int d = curTun.dest;
			int len = curTun.points;
			if (output[s] != MAX_NUM && output[s] + len < output[d]) {
			  output[d] = output[s] + len;
      }
		}
	}
 
	for (int i = 0; i < numRoom; i++) {
		for (tunnel curTun: tunnels) {
			int s = curTun.start;
			int d = curTun.dest;
			int len = curTun.points;
			if (output[s] != MAX_NUM && output[s] + len < output[d]) {
        output[d] = -1 * MAX_NUM;
      }
		}
	}

  if(abs(output[numRoom - 1]) == MAX_NUM) {
		cout << -1;
		return;
	} 
  output[numRoom - 1] *= -1;
  cout << output[numRoom - 1];
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