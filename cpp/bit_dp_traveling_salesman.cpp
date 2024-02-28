#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const double INF = 1e9;

double calc_cost(int &from, int &to, vector<int> &X, vector<int> &Y) {
  return sqrt(
    (X.at(from) - X.at(to)) * (X.at(from) - X.at(to))
    + (Y.at(from) - Y.at(to)) * (Y.at(from) - Y.at(to))
  );
}

double get_min_cost_traveling_salesman(int &N, vector<int> &X, vector<int> &Y) {
  // bit dp
  int state_cnt = (1 << N);
  // dp[state(通った都市)][今いる都市] = 最小の移動cost;
  vector<vector<double>> dp(state_cnt, vector<double>(N + 1, INF));
  dp.at(0).at(1) = 0.0;
  // state=i: 既に通った都市
  for (int i = 0; i < state_cnt; i++) {
    // j: 移動前の都市
    for (int j = 1; j <= N; j++) {
      // state=iのときに既に通った都市
      vector<int> already(N + 1, 1);
      for (int k = 1; k <= N; k++) {
        if ((i / (1 << (k - 1))) % 2 == 0) already.at(k) = 0;
      }
      if (i != 0 && already.at(j) == 0) continue;
      
      // k: 移動後の都市
      for (int k = 1; k <= N; k++) {
        if (already.at(k) == 1) continue;
        // state=i + 都市kに行ったstate
        int v = 0;
        for (int l = 1; l <= N; l++) {
          if (already.at(l) == 1 || l == k) v += (1 << (l - 1));
        }
        // 移動後の移動cost
        double cost = calc_cost(j, k, X, Y);
        dp.at(v).at(k) = min(dp.at(v).at(k), dp.at(i).at(j) + cost);
      }
    }
  }
  return dp.at((1 << N) - 1).at(1);
}

int main() {
  // B23: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cv
  int N;
  cin >> N;

  vector<int> X(N + 1), Y(N + 1);
  for (int i = 1; i <= N; i++) cin >> X.at(i) >> Y.at(i);

  double ans = get_min_cost_traveling_salesman(N, X, Y);
  cout << ans << endl;

  cerr << endl;
  cerr << N << endl;
  // for (int i = 1; i <= N; i++) cerr << X.at(i) << ' ' << Y.at(i) << endl;
  // for (int j = 1; j <= N; j++) cerr << dp.at((1 << N) - 1).at(j) << endl;
}
