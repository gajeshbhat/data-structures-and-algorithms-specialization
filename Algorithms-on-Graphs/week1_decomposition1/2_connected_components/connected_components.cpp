#include <iostream>
#include <vector>
#include <stack>
#include <set>

using std::vector;
using std::pair;

void dfs_and_mark(vector<vector<int> > &adj,vector<int> &is_visited,int vertex_idx){
  // First thing we mark
  is_visited[vertex_idx] = 1;
  for (size_t neb_vertex = 0; neb_vertex < adj[vertex_idx].size(); neb_vertex++) {
    // If nebighour is unmarked, mark them recursively
    if (is_visited[adj[vertex_idx][neb_vertex]] == 0) {
      dfs_and_mark(adj,is_visited,adj[vertex_idx][neb_vertex]);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
int res = 0;
vector<int> is_visited(adj.size()); // Creats extra arrya and inits with zeros eqal to number of vertices

for (size_t vertex = 0; vertex < adj.size(); vertex++) {
  if (is_visited[vertex] == 0) {
    dfs_and_mark(adj,is_visited,vertex);
    res++;
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
  std::cout << number_of_components(adj) << "\n";
}
