#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

struct Compare {
    bool operator()(vector<long long> const & a, vector<long long> const & b)
    { return a[0] > b[0]; }
};

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  // Initialize all distances to infinity and create the open list
  vector<long long> distances(adj.size(), LLONG_MAX);
  vector<bool> visited(adj.size(),false);
  priority_queue<vector<long long>, vector<vector<long long>>, Compare > open_list;
  // Add first element to open list and give a distance of 0
  open_list.push({0,s});
  distances[s] = 0;
  // Pop the minimum distance node and relax all its neighbors
  while (open_list.size() != 0)
  {
    int actual_node = open_list.top()[1];
    open_list.pop();
    if (visited[actual_node])
    {
      continue;
    }
    visited[actual_node] = true;
    for (int i = 0; i < adj[actual_node].size(); i++)
    {
      int next_node = adj[actual_node][i];
      if(distances[actual_node]+cost[actual_node][i] < distances[next_node]){
        distances[next_node] = distances[actual_node]+cost[actual_node][i];
        open_list.push({distances[next_node],next_node});
      }
    }
    
  }
  if (distances[t] < LLONG_MAX)
  {
    return distances[t];
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}


// 4 4 
// 1 2 1 
// 4 1 2 
// 2 3 2 
// 1 3 5 
// 1 3