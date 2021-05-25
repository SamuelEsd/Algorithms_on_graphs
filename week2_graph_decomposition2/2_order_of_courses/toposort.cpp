#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::pair;
using std::sort;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<vector <long long>> &order, int x, long long &clock) {
  // run dfs for every not visited node
  for (int i = 0; i < adj[x].size(); i++)
  {
    if(used[adj[x][i]] != 0){
      continue;
    }
    dfs(adj,used,order,adj[x][i],clock);
  }
  // ist important to put the clock after calling for dfs because if it is incremented before
  // it can return nodes with the same value.
  clock++;
  // save the index and post order value of the node
  order.push_back({clock,x});
  // mark as visited
  used[x]++;
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);        // to keep track of which nodes have been visited
  vector<vector <long long>> order;       // to keep track of the order of a sertain node
  vector<int> final_order(adj.size(), 0); // to return the order
  long long clock = 0;                    // for the order of the nodes in dfs

  // run dfs for every not visited node
  for (int i = 0; i < adj.size(); i++)
  {
    if(used[i] != 0){
      continue;
    }
    dfs(adj,used,order,i,clock);
  }

  // after we got the post order order of every node
  // sort by post order every node and take the reverse
  sort(order.begin(),order.end());
  reverse(order.begin(),order.end());

  // just take the indexes of the numbers as told before
  for(int i = 0; i < order.size(); i++){
    final_order[i] = order[i][1];
  }
  return final_order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
