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


ll Sx, Sy, Tx, Ty;

int main() {
  cin >> Sx >> Sy >> Tx >> Ty;

  if (Sy > Ty) {
    swap(Sy, Ty);
    swap(Sx, Tx);
  }

  ll shift;
  if (Sy % 2 == 0) shift = Sy;
  else shift = Sy - 1;
  Ty -= shift;
  Sy -= shift;

  if (Sx % 2 == 0) shift = Sx;
  else shift = Sx - 1;
  Sx -= shift;
  Tx -= shift;

  ll x_l, x_r;
  if (Sy == 0) {
    x_l = - (Ty - Sy);
    x_r = Ty - Sy + 1;
  }
  else {  // Sy == 1
    if (Sx == 0) {
      x_l = - (Ty - Sy) - 1;
      x_r = Ty - Sy;
    }
    else {  // Sx == 1
      x_l = - (Ty - Sy) + 1;
      x_r = Ty - Sy + 2;
    }
  }

  ll ans = 0;
  ans += abs(Sy - Ty);  
  if (Tx < x_l) ans += (x_l - Tx + 1) / 2;
  if (Tx > x_r) ans += (Tx - x_r + 1) / 2;
  COUT(ans);

  ENDL;
  dump(Sx);
  dump(Sy);
  dump(Tx);
  dump(Ty);
  dump(x_l);
  dump(x_r);
}
