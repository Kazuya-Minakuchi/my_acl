#include <bits/stdc++.h>
#include <atcoder/all>

typedef int64_t ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const ll LZERO = 0;

using namespace std;
using mint = atcoder::modint998244353;

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

int N, M;
ll H;
// string S, T;

vector<ll> A(20, 0), B(20, 0);
map<set<int>, int> removed_win;

int calc_win(int turn, set<int> removed) {
  if (removed_win.count(removed)) return removed_win[removed];

  int next_turn = 1 - turn;
  set<int> wins;
  int win_num = next_turn;
  reps(i, N-1) {
    if (removed.count(i)) continue;
    for (int j = i+1; j <= N; j++) {
      if (removed.count(j)) continue;
      if (A.at(i) == A.at(j) || B.at(i) == B.at(j)) {
        set<int> temp_removed = removed;
        temp_removed.insert(i);
        temp_removed.insert(j);
        int temp_win = calc_win(next_turn, temp_removed);
        if (temp_win == turn) win_num = turn;
      }
      if (win_num == turn) break;
    }
    if (win_num == turn) break;
  }

  removed_win[removed] = win_num;
  // dump(turn);
  // VECCERR(removed);
  // dump(win_num);
  return win_num;
}

int main() {
  cin >> N;
  reps(i, N) cin >> A.at(i) >> B.at(i);

  set<int> removed = {};
  ll ans = calc_win(0, removed);
  // dump(ans);
  if (ans == 0) COUT("Takahashi");
  else COUT("Aoki");
  // COUT(ans);

  cerr << endl;
  dump(N);
  // VECCERR(A);
  // VECCERR(B);
}
