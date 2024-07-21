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


int K;
vector<mint> fac, facinv;
void modcalc(int n = 3000) {
  fac.resize(n + 1, 1);  // 階乗
  facinv.resize(n + 1, 1);  // 階乗の逆元
  fac[0] = facinv[0] = 1;
  fac[1] = facinv[1] = 1;
  for(ll i = 2; i < n; i++) {
    mint mint_i = i;
    fac[i] = fac[i - 1] * mint_i;  // i! = (i-1)! * i
    facinv[i] = facinv[i - 1] * mint_i.inv();  // (i!)^-1 = (i-1)!^-1 * i^-1
  }
}

// nCk = n! * (k!)^-1 * ((n-k)!)^-1
mint comb(int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return fac[n] * facinv[k] * facinv[n - k];
}

int main() {
  modcalc();

  cin >> K;

  vector<int> C(27, 0);
  int sum_c = 0;
  reps(i, 26) {
    cin >> C[i];
    sum_c += C[i];
  }

  chmin(K, sum_c);

  vector<vector<mint>> dp(27, vector<mint>(K + 1, 0));
  dp[0][0] = 1;
  reps(i, 26) {
    rep(j, K + 1) {
      rep(l, min(j, C[i]) + 1) dp[i][j] += dp[i - 1][j - l] * comb(j, l);
    }
  }

  mint ans = 0; 
  for (int j = 1; j <= K; j++) ans += dp[26][j];
  COUT(ans.val());

  ENDL;
  dump(K);
  // VECCERR(C);
}
