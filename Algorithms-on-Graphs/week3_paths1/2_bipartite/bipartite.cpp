/*Does not work for the last test case. See the simple method in bipartite.py.file*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::vector;
using std::queue;
using std::set;

int switch_color(int color_code){
  if (color_code == 0) {
    return 1;
  }
  return 0;
}

void color_graph(vector<vector<int> > &adj,vector<int> &vertex_color,int start_color_vertex){

  queue<int>nebighours;
  vector<bool>has_colored(adj.size(),false);
  int color = 0; // 0 stands for white color here with whcih we start
  int first_vertex = start_color_vertex; // Choosen at random as we do a BFS

  nebighours.push(first_vertex);
  has_colored[first_vertex] = true;
  vertex_color[first_vertex] = color;

  while (!nebighours.empty()) {
    int current_vertex = nebighours.front();
    nebighours.pop();
    color = switch_color(color); // Flip color at each level

    for (size_t i = 0; i < adj[current_vertex].size(); i++) {
      if (!has_colored[adj[current_vertex][i]]) {
        has_colored[adj[current_vertex][i]] = true;
        vertex_color[adj[current_vertex][i]] = color;
        nebighours.push(adj[current_vertex][i]);
      }
    }
  }

}

int bipartite(vector<vector<int> > &adj) {

  vector<int>vertex_color(adj.size(),-1);
  color_graph(adj,vertex_color,0);
  vector<bool>has_visited(adj.size(),false);

  for (size_t i = 0; i < adj.size(); i++) {
    std::cout << "Edges for vertex " << i+1 << "(" << vertex_color[i] << ")" << "are : ";
    for (size_t j = 0; j < adj[i].size(); j++) {
      std::cout << adj[i][j] + 1 << " ";
    }
    std::cout  << '\n';
  }


  for (size_t i = 0; i < adj.size(); i++) {
      has_visited[i] = true;
      // Special case of disconnected edges then call color on it again before proceeding
      if (vertex_color[i] == -1) {
        color_graph(adj,vertex_color,i);
      }
      for (size_t j = 0; j < adj[i].size(); j++) {
          // Visit and check if the nebighours have same color
          if (!has_visited[adj[i][j]]) {
          has_visited[adj[i][j]] = true;
          if (vertex_color[adj[i][j]] == vertex_color[i]) {
            return 0;
          }
        }
    }
  }
  return 1;
}

int bipartite_simple(vector<vector<int> > &adj) {
  vector<bool> has_visited(adj.size(),false);
  vector<int> prev_color(adj.size());
  prev_color[0] = 0; // Assign white color to first vertex

  queue<int> nebighours;
  nebighours.push(0);
  has_visited[0]= true;

  while (!nebighours.empty()) {
    int current_vertex = nebighours.front();
    nebighours.pop();
    for (size_t i = 0; i < adj[current_vertex].size(); i++) {
      if (prev_color[current_vertex] == prev_color[adj[current_vertex][i]]) {
        return 0;
      }
      else{
        if (!has_visited[adj[current_vertex][i]]) {
        has_visited[adj[current_vertex][i]] = true;
        prev_color[adj[current_vertex][i]] = 1 - prev_color[current_vertex];
        nebighours.push(adj[current_vertex][i]);
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
  std::cout << bipartite(adj) << "\n";
}
