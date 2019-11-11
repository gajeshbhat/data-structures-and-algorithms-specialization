#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

int dfs(vector<vector<int> > &adj,vector<int> &used,vector<int> &order,int x,int order_insert_idx) {
used[x] = 1;
for (size_t i = 0; i < adj[x].size(); i++) {
  if (used[adj[x][i]] == 0) {
    order_insert_idx = dfs(adj,used,order,adj[x][i],order_insert_idx);
  }
}
order[order_insert_idx] = x;
return order_insert_idx - 1;
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order(adj.size());
  int order_idx = adj.size() - 1; // Equals to total number of vertices
  for (size_t vertex = 0; vertex < adj.size(); vertex++) {
    if (used[vertex] == 0) {
      order_idx = dfs(adj,used,order,vertex,order_idx); // Recusively inserts the numbers and returns the order_idx
    }
  }
  return order;
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
  std::cout << '\n';
}
