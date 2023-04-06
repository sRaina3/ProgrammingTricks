#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
vector<long> graph;

long recursive_find(long rd) {
  if (graph[rd] < 0) {
    return rd;
  } else {
    graph[rd] = recursive_find(graph[rd]);
    return graph[rd];
  }
}

bool connect(long startP, long endP) {
  startP = recursive_find(startP);
  endP = recursive_find(endP);
  if (startP == endP) {
    return false;
  } else if (graph[startP] > graph[endP]) {
    graph[startP] += graph[endP];
    graph[endP] = startP;
  } else {
    graph[endP] += graph[startP];
    graph[startP] = endP;
  }
  return true;
}

int main() {
  long num_city;
  long num_road;
  cin >> num_city >> num_road;
  graph.resize(num_city, -1);

  long maxSize = 0;
  for (long i = 0; i < num_road; i++) {
    long startP;
    long endP;
    cin >> startP >> endP;
    if (connect(startP, endP)) {
      long newMax = -1*graph[recursive_find(startP)];
      maxSize = max(maxSize, newMax);
      num_city--;
    }
    cout << num_city << " " << maxSize << "\n";
  }
}