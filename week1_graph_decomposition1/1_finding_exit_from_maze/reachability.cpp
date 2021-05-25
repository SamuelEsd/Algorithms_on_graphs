#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::stack;


int reach(vector<vector<int> > &adj, int x, int y) {
  vector<bool> visited(adj.size(),false);
  stack<int> openlist;
  openlist.push(x);
  
  // While there is something in stack keep visiting
  while (openlist.size() != 0)
  {
    // pop an element and if its the objective
    // return 1 else mark it as visited and propagate
    int actual = openlist.top();
    if (actual == y){
      return 1;
    }
    openlist.pop();
    visited[actual] = true;

    // propagate
    for (int i = 0; i < adj[actual].size(); i++)
    {
      if(!visited[adj[actual][i]]){
        openlist.push(adj[actual][i]); 
      }
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
