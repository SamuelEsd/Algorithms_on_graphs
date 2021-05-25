#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void bfs(vector<vector<int> > &adj, vector<int> &shortest, int s){
  vector<bool> visited(adj.size(),false);
  queue<int> open_list;

  open_list.push(s);
  visited[s] = true;
  while(open_list.size() != 0){
    int actual_node = open_list.front();
    open_list.pop();
    for (int neighbor = 0; neighbor < adj[actual_node].size(); neighbor++)
    {
      int next_node = adj[actual_node][neighbor];
      if(visited[next_node]){
        continue;
      }
      else{
        visited[next_node] = true;
        shortest[next_node] = 0;
        open_list.push(next_node);
      }
    }
    

  }

}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  distance[s] = 0;
  reachable[s] = 1;
  bool is_negative_cycle = true;
  // run bellman-forth from source
  for (int i = 0; i < adj.size(); i++)
  {
    int reflexed = 0;
    for (int actual_node = 0; actual_node < adj.size(); actual_node++)
    {

      for (int k = 0; k < adj[actual_node].size(); k++)
      { 
        int next_node = adj[actual_node][k];
        if(distance[actual_node]+cost[actual_node][k] < distance[next_node] && distance[actual_node] != LLONG_MAX){
          distance[next_node] = distance[actual_node]+cost[actual_node][k];
          reachable[next_node] = 1;
          reflexed++;
        } 
      }
    }
    if (reflexed == 0)
    {
      is_negative_cycle = false;
      break;
    }
  }
  //if there's a negative cycle, mark all nodes reacheable from the negative ycle
  if (is_negative_cycle)
  {
    for (int actual_node = 0; actual_node < adj.size(); actual_node++)
    {
      for (int k = 0; k < adj[actual_node].size(); k++)
      { 
        int next_node = adj[actual_node][k];
        if(distance[actual_node]+cost[actual_node][k] < distance[next_node] && distance[actual_node] != LLONG_MAX){
          shortest[next_node] = 0;
          bfs(adj, shortest, next_node);
        } 
      }
    } 
  }
  
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}


// 6 7
// 1 2 10
// 2 3 5
// 1 3 100
// 3 5 7
// 5 4 10
// 4 3 -18
// 6 1 -1
// 1