#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  vector<int> color(adj.size(),-1);
  queue<int> open_list;

  //Push the start node to queue
  for(int j = 0; j < adj.size(); j++){
    if (color[j] != -1)
    {
      continue;
    }
    
    open_list.push(j);
    color[j] = 0;
    while (open_list.size() != 0)
    {
      // pop next element in queue
      // and push every not visited neighbor
      int temp = open_list.front();
      open_list.pop();
      for (int i = 0; i < adj[temp].size(); i++)
      {
        if (color[adj[temp][i]] == color[temp])
        {
          return 0;
        }
        if (color[adj[temp][i]] == -1)
        {
          open_list.push(adj[temp][i]);
          color[adj[temp][i]] = (color[temp]+1)%2;
          int k;
        } 
      }
    }
  }
  
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
