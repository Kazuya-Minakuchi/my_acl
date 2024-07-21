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


int M, N;

int main() {
  cin >> M >> N;

  vector<int> X(M + 1, 0);
  vector<bitset<10>> reset(M + 1, 0);
  reps(i, M) {
    cin >> X[i];
    reset[X[i]].set(i-1);
  }

  vector<vector<mint>> dp(N + 1, vector<mint>((1 << M) + 10, 0));
  bitset<10> rem_num = 0;
  rep(i, M) rem_num.set(i);
  // dump(rem_num);
  // dump(rem_num.to_ulong());
  dp[0][(int)rem_num.to_ulong()] = 1;
  for (int i = 0; i <= N - 1; i++) {
    reps(j, (1 << M)) {
      mint val = dp[i][j];
      if (val.val() == 0) continue;
      bitset<10> bt(j);
      reps(x, M) {
        if (bt[x-1]) {
          auto bt2 = bt;
          bt2.reset(x-1);
          bt2 |= reset[x];
          dp[i + 1][bt2.to_ulong()] += val;
        }
      }
    }
  }
  mint ans = 0;
  for (auto val : dp[N]) {
    ans += val;
  }
  COUT(ans.val());

  ENDL;
  dump(M);
  dump(N);
}
