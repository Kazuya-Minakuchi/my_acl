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

ll calc_ans (ll x, ll y) {
  ll x_4 = x / 4;
  ll x_1 = x_4;
  ll x_2 = x_4;
  ll x_3 = x_4;
  if (x % 4 >= 1) x_1++;
  if (x % 4 >= 2) x_2++;
  if (x % 4 >= 3) x_3++;
  ll y_2 = y / 2;
  ll y_1 = y_2;
  if (y % 2 == 1) y_1++;
  // dump(x_1);
  // dump(x_2);
  // dump(x_3);
  // dump(x_4);
  // dump(y_1);
  // dump(y_2);
  ll ans = 0;
  ans += x_1 * y_1 * 2;
  ans += x_1 * y_2;
  ans += x_2 * y_1;
  ans += x_2 * y_2 * 2;
  ans += x_3 * y_2;
  ans += x_4 * y_1;
  return ans;
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A < 0) {
    ll shift_x = (- A / 4 + 1) * 4;
    A += shift_x;
    C += shift_x;
  }
  if (B < 0) {
    ll shift_y = (- B / 2 + 1) * 4;
    B += shift_y;
    D += shift_y;
  }


  ll ans1 = calc_ans(C, D); // (C, D)
  ll ans2 = calc_ans(A, D); // (A, D)
  ll ans3 = calc_ans(C, B); // (C, B)
  ll ans4 = calc_ans(A, B); // (A, B)
  // dump(ans1);
  // dump(ans2);
  // dump(ans3);
  // dump(ans4);
  ll ans = ans1 - ans2 - ans3 + ans4;
  COUT(ans);

  cerr << endl;
  dump(A);
  dump(B);
  dump(C);
  dump(D);
}
