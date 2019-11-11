#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void sccDfs(int vertex,vector<vector<int> > &adj,int id_count,vector<int> &ids,vector<bool> &onStack,vector<int> &low_link,stack<int> &component_tracker_stack,int *result){
// Push to stack , mark the vertex as on stack update and update the id count as assign to the vertex
component_tracker_stack.push(vertex);
onStack[vertex] = true;
ids[vertex] = low_link[vertex] = id_count++;

// Visit nebs and mark them and push them in the stack
for (size_t i = 0; i < adj[vertex].size(); i++) {
  // Recurse on each vertex
  if (ids[adj[vertex][i]] == -1) {
    sccDfs(adj[vertex][i],adj,id_count,ids,onStack,low_link,component_tracker_stack,result);
  }
  // When finally reached end of a connected component, time for call back so we check the lowlink values.
  if (onStack[adj[vertex][i]] == true) {
    // Calculate and assing the minimum
    low_link[vertex] = std::min(low_link[vertex],low_link[adj[vertex][i]]);
  }
}
 // After visiting all the neighbours if we are at start of the SCC we started form we have a component
 // Now we empty the component_tracker_stack and and update the result which is sccCount

if (ids[vertex] == low_link[vertex]) {
  while (!component_tracker_stack.empty()) {
    onStack[component_tracker_stack.top()] = false;
    low_link[component_tracker_stack.top()] = ids[vertex];
    if (component_tracker_stack.top() == vertex) {
      break;
    }
    component_tracker_stack.pop();
  }
  (*result)++;
}
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0; // result is count of strongly conneted components
  int id_count = 0;
  int unvisited_mark = -1;

  vector<int> ids(adj.size(),unvisited_mark);
  vector<bool> onStack(adj.size(),false);
  vector<int> low_link(adj.size(),0);
  stack<int>component_tracker_stack;

  for (size_t vertex = 0; vertex < adj.size(); vertex++) {
    if (ids[vertex] == unvisited_mark) {
      // if unvisited, visit and check for component;
      sccDfs(vertex,adj,id_count,ids,onStack,low_link,component_tracker_stack,&result);
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj) << "\n";
}
