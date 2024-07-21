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


ll N;


int main() {
  cin >> N;

  if (N == 1) {
    COUT(0);
    return 0;
  }

  ll rem_N = N - 1;

  int keta = 1;
  ll keta_cnt = 9;
  // 答えが何桁か求める
  while (true) {
    if (rem_N > keta_cnt) {
      rem_N -= keta_cnt;
    } else {
      break;
    }
    keta++;
    if (keta % 2 == 1) keta_cnt *= 10;
  }
  ll start = keta_cnt / 9;
  ll ans_half = start + rem_N - 1;
  // dump(keta);
  // dump(keta_cnt);
  // dump(rem_N);
  // dump(start);
  // dump(ans_half);

  string ans = to_string(ans_half);
  // ansをketa桁の回文にする
  int n_half = ans.size();
  if (keta % 2 == 1) {
    for (int i = n_half - 2; i >= 0; i--) ans += ans[i];
  }
  else {
    for (int i = n_half - 1; i >= 0; i--) ans += ans[i];
  }
  COUT(ans);

  ENDL;
  dump(N);
}
