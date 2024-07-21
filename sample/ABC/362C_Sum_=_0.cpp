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

  vector<ll> L(N + 1, LZERO), R(N + 1, LZERO);
  reps(i, N) {
    cin >> L[i] >> R[i];
  }

  ll sum_l = accumulate(all(L), LZERO);
  ll sum_r = accumulate(all(R), LZERO);
  // dump(sum_l);
  // dump(sum_r);
  if (sum_l > 0) {
    COUT("No");
    return 0;
  }
  else if (sum_r < 0) {
    COUT("No");
    return 0;
  }

  vector<ll> ans_v;
  ll rem_l = - sum_l;
  // dump(rem_l);
  reps(i, N) {
    ll l = L[i];
    ll r = R[i];
    ll temp_ans = l;
    if (rem_l > 0) {
      temp_ans += min(rem_l, r - l);
    }
    ans_v.pb(temp_ans);
    rem_l -= temp_ans - l;
    // dump(temp_ans);
    // dump(rem_l);
  }

  COUT("Yes");
  for (auto ans : ans_v) {
    SCOUT(ans);
  }
  ENDL;

  ENDL;
  dump(N);
  // VECCERR(L);
  // VECCERR(R);
}
