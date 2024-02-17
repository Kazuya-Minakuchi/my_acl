#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


vector<int> get_dist_bfs(int start, vector<vector<int>> &G) {
  // variables
  vector<int> dist(G.size(), -1);
  queue<int> next_q;
  // init
  next_q.push(start);
  dist.at(start) = 0;
  // bfs
  while(!next_q.empty()) {
    int pos = next_q.front(); next_q.pop();
    for (auto n : G.at(pos)) {
      if (dist.at(n) != -1) continue;
      next_q.push(n);
      dist.at(n) = dist.at(pos) + 1;
    }
  }
  return dist;
}
  
int main() {
  // A63
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N + 1, vector<int>(0));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }

  vector<int> dist = get_dist_bfs(1, G);
  for (int i = 1; i <= N; i++) cout << dist.at(i) << endl;

  cerr << endl;
  cerr << N << endl;
  // for (int i = 1; i <= N; i++) {
  //   cerr << i << ": ";
  //   for (auto j: G.at(i)) cerr << j << ", ";
  //   cerr << endl;
  // }
  // cerr << endl;
  // for (int i = 1; i <= N; i++) {
  //   cerr << from.at(i) << "->" << i << endl;
  // }
}
