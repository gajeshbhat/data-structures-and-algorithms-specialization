#include <iostream>
#include <vector>
#include <queue>
#include <set>

using std::vector;
using std::queue;
using std::set;

int distance(vector<vector<int> > &adj, int s, int t) {

queue<int>nebighours;
vector<int>distance_from_s(adj.size(),-1);
vector<bool>has_visited(adj.size(),false);
has_visited[s] = true;
distance_from_s[s] = 0;
nebighours.push(s);

while (!nebighours.empty()) {
int current_vertex = nebighours.front();
nebighours.pop();

// Explore nebighours of current vertex;
set<int> current_nebs;
current_nebs.insert(current_vertex);

for (size_t i = 0; i < adj[current_vertex].size(); i++) {
  if (!has_visited[adj[current_vertex][i]] && current_vertex != adj[current_vertex][i] && current_nebs.find(adj[current_vertex][i]) == current_nebs.end()) {
    // Unvisited, to be explore so add to queue
    nebighours.push(adj[current_vertex][i]);
    // Update the distance
    distance_from_s[adj[current_vertex][i]] = distance_from_s[current_vertex] + 1;
    // Update the visited flag
    has_visited[adj[current_vertex][i]] = true;
    // update set to stop duplicate counting
    current_nebs.insert(adj[current_vertex][i]);
  }
}
}
return distance_from_s[t];
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
  std::cout << distance(adj, s, t) << "\n";

}
