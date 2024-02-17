#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


void dfs(int pos, vector<vector<int>> &G, vector<bool> &visited) {
  visited.at(pos) = true;
  for (int i = 0; i < G.at(pos).size(); i++) {
    int nex = G.at(pos).at(i);
    if (visited.at(nex) == false) dfs(nex, G, visited);
  }
  return;
}

int main() {
  // A62
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N + 1, vector<int>(0));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  vector<bool> visited(N + 1, false);
  dfs(1, G, visited);

  bool connected = true;
  for (int i = 1; i <= N; i++) {
    if (!visited.at(i)) {
      connected = false;
      break;
    }
  }
  if (connected) cout << "The graph is connected." << endl;
  else cout << "The graph is not connected." << endl;

  cerr << endl;
  cerr << N << endl;
}
