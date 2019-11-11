#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::vector;
using std::pair;
using std::queue;
using std::set;

int reach(vector<vector<int> > &adj, int x, int y) {
  queue<int>vertices;
  set<int> has_seen;
  vertices.push(x);

 while(!vertices.empty()){
  int vertex_to_check = vertices.front();
  // If vertex has not been checked yet.
  if(has_seen.find(vertex_to_check) == has_seen.end()){
  for(int i=0; i<adj[vertex_to_check].size();i++){
    if(adj[vertex_to_check][i] == y){
      return 1;
    }
   else{
      vertices.push(adj[vertex_to_check][i]);
  }
 }
}
vertices.pop();
has_seen.insert(vertex_to_check);
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
  std::cout << reach(adj, x - 1, y - 1) << "\n";
}
