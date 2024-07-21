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

int main() {
  cin >> N;

  vector<ll> A(N + 1, 0);
  reps(i, N) cin >> A[i];

  vector<map<pair<ll, ll>, mint>> dp_last_diff_cnt(N + 1);
  ll a;
  reps(i, N) {
    // dump(i);
    a = A[i];
    // dump(a);
    for (int j = i - 1; j >= 1; j--) {
      for (auto [ld, cnt] : dp_last_diff_cnt[j]) {
        ll l, d;
        tie(l, d) = ld;
        if (j > 1 && a - l != d) continue;
        // dump(l);
        // dump(d);
        // dump(cnt.val());
        dp_last_diff_cnt[j+1][{a, a-l}] += cnt;
      }
    }
    dp_last_diff_cnt[1][{a, 0}] += 1;
  }

  vector<mint> ans_v(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (auto [ld, cnt] : dp_last_diff_cnt[i]) {
      ans_v[i] += cnt;
    }
  }
  reps(i, N) {
    SCOUT(ans_v[i].val());
  }
  ENDL;

  ENDL;
  dump(N);
  // VECCERR(A);
}
