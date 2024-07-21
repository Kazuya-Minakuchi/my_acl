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


int N;
ll T;
string S;

int main() {
  cin >> N >> T;
  cin >> S;

  vector<ll> X(N+1, LZERO);
  reps(i, N) cin >> X[i];

  vector<ll> X_right, X_left;
  reps(i, N) {
    if (S[i-1] == '1') X_right.pb(X[i]);
    else X_left.pb(X[i]);
  }

  sort(all(X_right));
  sort(all(X_left));

  ll ans = 0;
  ll search;
  for (ll x_r : X_right) {
    search = x_r + 2 * T;
    auto itr1 = lower_bound(all(X_left), x_r);
    auto itr2 = upper_bound(all(X_left), search);
    ll add = (ll)(itr2 - itr1);
    // dump(x_r);
    // dump(add);
    ans += add;
  }
  COUT(ans);

  ENDL;
  dump(N);
  dump(T);
  dump(S);
  // VECCERR(X);
}
