#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int check_cycle(int vertex,vector<vector<int> > &adj,vector<int> &has_visited,vector<int>&current_stack){

if (has_visited[vertex] == 0) {
  current_stack[vertex] = 1;
  has_visited[vertex] = 1;


  for (size_t i = 0; i < adj[vertex].size(); i++) {
    if (has_visited[adj[vertex][i]] == 0 && check_cycle(adj[vertex][i],adj,has_visited,current_stack) ) {
      // In not in the stack but if found in the surrounding vertices then true
      return 1;
    }
    else if (current_stack[adj[vertex][i]] == 1) {
      // If already in stack cycle found.
      return 1;
    }
  }
}

// Already visited and no need to visit again remove from stack
current_stack[vertex] = 0;
return 0;
}

int acyclic(vector<vector<int> > &adj) {
vector<int>has_visited(adj.size());
vector<int>current_stack(adj.size());

for (size_t vertex = 0; vertex < adj.size(); vertex++) {
    if (check_cycle(vertex,adj,has_visited,current_stack)) {
      return 1;
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
  }
  std::cout << acyclic(adj) << "\n";
}
