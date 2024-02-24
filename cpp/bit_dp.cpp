#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int INF = 1e9;

int main() {
  // A23
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(M + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A.at(i).at(j);
    }
  }

  // bit dp
  int col_cnt = (1 << N);
  // dp[クーポンiまで考えたとき][state(無料商品)] = 最小のクーポン数;
  vector<vector<int>> dp(M + 1, vector<int>(col_cnt, INF));
  dp.at(0).at(0) = 0;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < col_cnt; j++) {
      // state=jのときに既に無料になっている商品
      vector<int> already(N + 1, 1);
      for (int k = 1; k <= N; k++) {
        if ((j / (1 << (k - 1))) % 2 == 0) already.at(k) = 0;
      }

      // state=jとクーポンiを使ったときのstate
      int v = 0;
      for (int k = 1; k <= N; k++) {
        if (already.at(k) == 1 || A.at(i).at(k) == 1) v += (1 << (k - 1));
      }

      // クーポンiを使わない/使う場合の遷移
      dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i - 1).at(j));
      dp.at(i).at(v) = min(dp.at(i).at(v), dp.at(i - 1).at(j) + 1);
    }
  }

  int ans = dp.at(M).at((1 << N) - 1);
  if (ans == INF) cout << "-1" << endl;
  else cout << ans << endl;

  cerr << endl;
  cerr << N << endl;
  cerr << M << endl;
  // for (int i = 1; i <= M; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     cerr << A.at(i).at(j) << ' ';
  //   }
  //   cerr << endl;
  // }
}
