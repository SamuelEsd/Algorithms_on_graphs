#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::queue;

bool dfs(vector<vector<int>> &adj, int actual, vector<int> &visited){
  visited[actual]++;
  for (int i = 0; i < adj[actual].size(); i++)
  {
    if(visited[adj[actual][i]] == 2){
      continue;
    }
    if(visited[adj[actual][i]] == 1){
      return true;
    }
    if(dfs(adj,adj[actual][i],visited)){
      return 1;
    }
  }
  visited[actual]++;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  vector<int> visited(adj.size(),0);
  for (int i = 0; i < adj.size(); i++)
  {
    if (visited[i] != 0)
    {
      continue;
    }
    if(dfs(adj,i,visited)){
      return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
