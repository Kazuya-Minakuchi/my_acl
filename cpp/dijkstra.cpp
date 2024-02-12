#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int64_t INF = 1e18;

vector<int64_t> get_cost_dijk(int start, vector<vector<pair<int, int64_t>>> &G) {
  // set variables
  int n = G.size();
  vector<int64_t> cost(n + 1, INF);
  vector<bool> kakutei(n + 1, false);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> Q;
  // init
  cost.at(start) = 0;
  Q.push(make_pair(cost[start], start));
  // dijk
  while (!Q.empty()) {
    int pos = Q.top().second; Q.pop();

    if (kakutei.at(pos) == true) continue;
    kakutei.at(pos) = true;
    for (auto p : G.at(pos)) {
      int nex = p.first;
      int64_t cst = p.second;
      if (cost.at(nex) > cost.at(pos) + cst) {
        cost.at(nex) = cost.at(pos) + cst;
        Q.push(make_pair(cost.at(nex), nex));
      }
    }
  }
  return cost;
}

int main() {
  // ABC325 E
  int N;
  int64_t A, B, C;
  cin >> N >> A >> B >> C;

  vector<vector<pair<int, int64_t>>> G_c(N + 1), G_t(N + 1);

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      int64_t d;
      cin >> d;
      G_c.at(i).push_back(make_pair(j, d * A));
      G_t.at(i).push_back(make_pair(j, d * B + C));
    }
  }

  vector<int64_t> cost_c = get_cost_dijk(1, G_c);
  vector<int64_t> cost_t = get_cost_dijk(N, G_t);

  int64_t ans = INF;
  for (int i = 1; i <= N; i++) ans = min(ans, cost_c.at(i) + cost_t.at(i));
  cout << ans << endl;

  cerr << endl;
  cerr << N << endl;
  cerr << A << endl;
  cerr << B << endl;
  cerr << C << endl;
  // for (int i = 1; i <= N; i++) cerr << cost_c.at(i) << ' ';
  // cerr << endl;
  // for (int i = 1; i <= N; i++) cerr << cost_t.at(i) << ' ';
  // cerr << endl;
}
