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
ll H, W;
// string S, T;
int T;

int main() {
  cin >> N;

  vector<ll> L(N + 1, 0), R(N + 1, 0);
  reps(i, N) cin >> L[i] >> R[i];
  vector<ll> L_sorted(0), R_sorted(0);
  reps(i, N) {
    L_sorted.pb(L[i]);
    R_sorted.pb(R[i]);
  }
  sort(all(L_sorted));
  sort(all(R_sorted));

  vector<ll> dup_cnt(N + 1, 0);
  ll l, r;
  reps(i, N) {
    l = L[i];
    r = R[i];
    ll out1 = N - (upper_bound(all(L_sorted), r) - L_sorted.begin());
    ll out2 = lower_bound(all(R_sorted), l) - R_sorted.begin();
    // dump(l);
    // dump(r);
    // dump(out1);
    // dump(out2);
    // ENDL;
    dup_cnt[i] = N - out1 - out2 - 1;
  }

  ll ans = 0;
  reps(i, N) ans += dup_cnt[i];
  ans /= 2;
  COUT(ans);

  cerr << endl;
  dump(N);
  // VECCERR(L_sorted);
  // VECCERR(R_sorted);
}
