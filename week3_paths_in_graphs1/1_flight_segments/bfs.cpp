#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  vector<int> min_dist(adj.size(),-1);
  vector<bool> visited(adj.size(),false);
  queue<int> open_list;

  //Push the start node to queue
  open_list.push(s);
  min_dist[s] = 0;
  while (open_list.size() != 0)
  {
    // pop next element in queue
    // and push every not visited neighbor
    int temp = open_list.front();
    open_list.pop();
    for (int i = 0; i < adj[temp].size(); i++)
    {
      if (!visited[adj[temp][i]])
      {
        open_list.push(adj[temp][i]);
        min_dist[adj[temp][i]] = min_dist[temp]+1;
        visited[adj[temp][i]] = true;
      } 
    }
  }
  

  return min_dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
