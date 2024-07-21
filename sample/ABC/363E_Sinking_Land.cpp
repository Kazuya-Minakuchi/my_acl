#include <bits/stdc++.h>
#include <atcoder/all>

typedef int64_t ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const ll LZERO = 0;

using namespace std;
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n) for(int i = 1; i <=(int)(n); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define SZ(x) ((int)(x).size())
#define dump(x) cerr << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define COUT(x) cout<<(x)<<endl
#define CERR(x) cerr<<(x)<<endl
#define SCOUT(x) cout<<(x)<<" "
#define SCERR(x) cerr<<(x)<<" "
#define ENDL cout<<endl
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl
#define VECCERR(x) for(auto&youso_: (x) )cerr<<youso_<<" ";cerr<<endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int H, W;
ll Y;

void add_next_sea(
    int x, int y,
    vector<vector<ll>> &A,
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> &next_sea,
    vector<vector<int>> &chekced) {
  // 既にチェック済み
  if (chekced[x][y] == 1) return;

  next_sea.push(make_tuple(A[x][y], x, y));
  chekced[x][y] = 1;
}

int main() {
  cin >> H >> W >> Y;

  vector<vector<ll>> A(H + 2, vector<ll>(W + 2, -1));
  reps(i, H) reps(j, W) cin >> A[i][j];

  // 1 = chekced
  vector<vector<int>> chekced(H + 2, vector<int>(W + 2, 0));
  rep(i, H + 2) chekced[i][0] = chekced[i][W + 1] = 1;
  rep(j, W + 2) chekced[0][j] = chekced[H + 1][j] = 1;

  // hight, x, y: hightが小さい順に取り出す
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> next_sea;
  // initial
  reps(i, H) {
    add_next_sea(i, 1, A, next_sea, chekced);
    add_next_sea(i, W, A, next_sea, chekced);
  }
  reps(j, W) {
    add_next_sea(1, j, A, next_sea, chekced);
    add_next_sea(H, j, A, next_sea, chekced);
  }

  ll ans = H * W;

  vector<pair<int, int>> move_xy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int next_x, next_y;
  reps(t, Y) {
    // dump(t);
    while (!next_sea.empty()) {
      auto [h, x, y] = next_sea.top();
      if (h > t) break;

      next_sea.pop();
      ans--;

      for (auto [dx, dy] : move_xy) {
        next_x = x + dx;
        next_y = y + dy;
        add_next_sea(next_x, next_y, A, next_sea, chekced);
      }
    }
    COUT(ans);
  }

  ENDL;
  dump(H);
  dump(W);
  dump(Y);
}
