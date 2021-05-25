#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  vector<long long> distances(adj.size(),0);
  distances[0] = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    int reflexed = 0;
    for (int actual_node = 0; actual_node < adj.size(); actual_node++)
    {

      for (int k = 0; k < adj[actual_node].size(); k++)
      { 
        int next_node = adj[actual_node][k];
        if(distances[actual_node]+cost[actual_node][k] < distances[next_node] && distances[actual_node] != LLONG_MAX){
          distances[next_node] = distances[actual_node]+cost[actual_node][k];
          reflexed++;
        } 
      }
    }
    if (reflexed == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}

// 4 4
// 1 2 -5
// 4 1 2
// 2 3 2
// 3 1 1