#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::priority_queue;

struct Compare {
    bool operator()(vector<double> const & a, vector<double> const & b)
    { return a[0] > b[0]; }
};

double dist(double x1, double y1, double x2, double y2){
  return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double minimum_distance(vector<int> x, vector<int> y) {
  vector<double> distance(x.size(),50000);
  vector<bool> visited(x.size(),false);

  double result = 0.;
  distance[0] = 0.0;
  priority_queue<vector<double>, vector<vector<double>>, Compare> open_list;
  open_list.push({distance[0],0});

  while (open_list.size() != 0)
  {
    int actual_node = open_list.top()[1];
    open_list.pop();
    if (visited[actual_node])
    {
      continue;
    }
    visited[actual_node] = true;
    for (int i = 0; i < x.size(); i++)
    {
      if(actual_node == i || visited[i]){
        continue;
      }
      if (distance[i] > dist(x[actual_node],y[actual_node],x[i],y[i]))
      {
        distance[i] = dist(x[actual_node],y[actual_node],x[i],y[i]);
        open_list.push({distance[i],(double)i});
      } 
    }
  }
  
  for (int i = 0; i < x.size(); i++)
  {
    result += distance[i];
  }
  

  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
