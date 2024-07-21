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

ll calc_ans_raw(ll n) {
  int k = to_string(n).length();

  mint ans = 0;
  mint ten = 10;
  rep(i, n) {
    mint add = ten.pow(i * k) * n;
    ans += add;
  }
  return ans.val();
}

ll calc_ans(ll n) {
  int k_n = to_string(n).length();
  mint ans1 = n;
  mint ten = 10;
  // dump(ten.pow(k_n).val());
  mint ans2 = (ten.pow(k_n).pow(n) - 1) / (ten.pow(k_n) - 1);
  return (ans1 * ans2).val();
}



int main() {
  cin >> N;

  ll ans;
  ans = calc_ans(N);
  COUT(ans);

  ENDL;
  dump(N);
}
