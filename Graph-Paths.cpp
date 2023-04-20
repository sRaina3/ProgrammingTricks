#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
long numCity;
vector<vector<pair<long,long>>> graph(200000, vector<pair<long,long>>());
 
void solver() {
  
}
 
int main() {
  long numFlight;
	cin >> numCity;
  cin >> numFlight;
	for (int i = 0; i < numFlight; i++) {
		long start;
    long dest;
    long len;
		cin >> start; 
    cin >> dest; 
    cin >> len;
		graph[start].push_back(make_pair(len, dest));
	}
	solver();
  return 0;
}