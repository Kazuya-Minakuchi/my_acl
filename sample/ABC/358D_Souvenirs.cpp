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


int N, M;

int main() {
  cin >> N >> M;

  vector<ll> A(N + 1, 0), B(M + 1, 0);
  reps(i, N) cin >> A[i];
  reps(i, M) cin >> B[i];

  sort(all(A));
  sort(all(B));

  ll ans = 0;
  int i_a = 1;
  reps(i, M) {
    ll b = B[i];
    while (A[i_a] < b && i_a <= N) i_a++;
    if ((N - i_a) < (M - i)) {
      ans = -1;
      break;
    }
    ans += A[i_a];
    // dump(i);
    // dump(i_a);
    // dump(A[i_a]);
    // dump(ans);
    i_a++;
  }
  COUT(ans);

  ENDL;
  dump(N);
  dump(M);
  // VECCERR(A);
  // VECCERR(B);
}
