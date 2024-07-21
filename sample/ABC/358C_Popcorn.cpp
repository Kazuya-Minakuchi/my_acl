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


int N, M;

int main() {
  cin >> N >> M;

  vector<string> S(N + 1, "");
  reps(i, N) cin >> S[i];

  vector<bitset<10>> bit_S(N + 1, 0);
  reps(i, N) {
    bitset<10> b = 0;
    rep(j, M) {
      if (S[i][j] == 'o') b[j] = true;
    }
    bit_S[i] = b;
  }

  vector<vector<int>> dp(N + 1, vector<int>(1 << M, INF));
  dp[0][0] = 0;
  reps(i, N) {
    // dump(i);
    // dump(bit_S[i]);
    rep(j, 1<<M) {
      if (dp[i - 1][j] == INF) continue;
      bitset<10> next_b = j;
      next_b |= bit_S[i];
      // dump(next_b);
      chmin(dp[i][j], dp[i - 1][j]);
      chmin(dp[i][next_b.to_ullong()], dp[i - 1][j] + 1);
    }
  }

  int ans = dp[N][(1 << M) - 1];
  COUT(ans);

  ENDL;
  dump(N);
  dump(M);
}
