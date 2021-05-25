#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::stack;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  
  // for each node apply DFS while keeping track of visited 
  // nodes to avoid expanding twice over the same node.
  vector<bool> visited(adj.size(),false);
  for(int j = 0; j < adj.size(); j++){
    if(visited[j]){
      continue;
    }
    res++;
    stack<int> openlist;
    openlist.push(j);
    
    // While there is something in stack keep visiting
    while (openlist.size() != 0){
      // pop an element and if its the objective
      // return 1 else mark it as visited and propagate
      int actual = openlist.top();
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
  }
  return res;
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
  std::cout << number_of_components(adj);
}
