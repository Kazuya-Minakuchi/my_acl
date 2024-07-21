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

int N, M, K;

int main() {
  cin >> N >> M >> K;

  vector<bitset<16>> all_bit(0);
  for (int i = 0; i < (1 << N); i++) {
    all_bit.pb(bitset<16>(i));
  }

  vector<int> C(M + 1, 0);
  vector<vector<int>> A(M + 1, vector<int>(0));
  vector<char> R(M + 1, '.');
  int a;
  reps(i, M) {
    cin >> C[i];
    rep(j, C[i]) {
      cin >> a;
      A[i].pb(a);
    }
    cin >> R[i];
  }

  ll ans = 0;
  for (auto bs: all_bit) {
    bool is_ok = true;
    reps(i, M) {
      int ok_cnt = 0;
      for (auto a: A[i]) if (bs[a - 1]) ok_cnt++;
      if (ok_cnt >= K && R[i] == 'x') is_ok = false;
      if (ok_cnt < K && R[i] == 'o') is_ok = false;
      if (!is_ok) break;
    }
    if (is_ok) ans++;
  }
  COUT(ans);

  ENDL;
  dump(N);
  dump(M);
  dump(K);
}
