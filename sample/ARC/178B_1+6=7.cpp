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
int T;
mint ten = 10;


ll calc_ans(ll A1, ll A2, ll A3) {
  if (A1 > A2) swap(A1, A2);
  // impossible
  if (A3 < A2) return 0;
  if (A3 > A2 + 1) return 0;

  mint ans = 0;
  if (A2 == A3) {
    if (A1 == A2) {
      ans = 8 * ten.pow(A2 - 1) * (8 * ten.pow(A2 - 1) + 1) / 2;
    }
    else {  // A1 < A2
      ans = 9 * ten.pow(A1 - 1) * (9 * ten.pow(A2 - 1) - (ten.pow(A1) + ten.pow(A1 - 1) - 1) / 2);
    }
  }
  else {  // A3 = A2 + 1
      ans = 81 * ten.pow(A2 + A1 - 2) - calc_ans(A1, A2, A2);
  }
  return ans.val();
}

int main() {
  cin >> T;

  ll A1, A2, A3;
  rep(i, T) {
    cin >> A1 >> A2 >> A3;
    ll ans = calc_ans(A1, A2, A3);
    COUT(ans);
  }

  cerr << endl;
  dump(T);
}
