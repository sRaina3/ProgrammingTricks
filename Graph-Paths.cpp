#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
long numCity;
vector<vector<pair<long,long>>> graph(200000, vector<pair<long,long>>());
 
void solver() {
  vector<long> output(numCity + 1, LONG_MAX);
	priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> queue;
	queue.push(make_pair(0,1));

	while (!queue.empty()) {
		long curlen = queue.top().first; 
		long curdest = queue.top().second; 
		queue.pop();
		if (curlen <= output[curdest]) {
      for (pair<long,long> curFlight : graph[curdest]) {
        long oldLen = curFlight.first;
        long nextDest = curFlight.second;  
        if (oldLen + curlen < output[nextDest]) {
          output[nextDest] = oldLen + curlen;
          queue.push(make_pair(oldLen + curlen, nextDest));
        }
      }
    }
	}
  output[1] = 0;
  for (int i = 0; i < numCity; i++) {
		cout << output[i + 1];
    cout << " ";
	}
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