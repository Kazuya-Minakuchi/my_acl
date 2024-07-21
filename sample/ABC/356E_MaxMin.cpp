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


int N;

int main() {
  cin >> N;

  vector<ll> A(N);
  ll max_A = 0;
  rep(i, N) {
    cin >> A[i];
    chmax(max_A, A[i]);
  }

  vector<ll> C(max_A + 2, 0);
  rep(i, N) {
    C[A[i]]++;
  }
  reps(i, max_A + 1) {
    C[i] += C[i - 1];
  }

  ll ans = 0;
  reps(i, max_A + 1) {
    ll d = C[i] - C[i - 1];  // 分母iの個数
    if (d == 0) continue;

    for (int j = i; j <= max_A + 1; j += i) {
      ll k = j / i;  // k = 分子j / 分母i
      ans += k * (C[min(max_A + 1, (ll)(j + i - 1))] - C[j - 1]) * d;  // k * kになる個数 * 分母iの個数
    }
    ans -= d * (d + 1) / 2;  // 自分自身を引く
  }
  COUT(ans);

  ENDL;
  dump(N);
  // VECCERR(A);
  // VECCERR(C);
}
