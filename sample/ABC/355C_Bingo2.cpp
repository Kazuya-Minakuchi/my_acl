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
  cin >> N >> T;

  vector<ll> A(T + 1, 0);
  reps(i, T) cin >> A[i];

  vector<int> r_cnt(N + 1, 0), c_cnt(N + 1, 0), v_cnt(2, 0);

  ll ans = -1;
  ll a, r, c;
  reps(i, T) {
    a = A[i];
    r = (a-1) / N + 1;
    c = a % N;
    if (c == 0) c = N;
    // dump(i);
    // dump(a);
    // dump(r);
    // dump(c);
    r_cnt[r]++;
    c_cnt[c]++;
    if (r == c) {
      v_cnt[0]++;
      if (v_cnt[0] == N) {
        ans = i;
        break;
      }
    }
    if (r + c == N + 1) {
      v_cnt[1]++;
      if (v_cnt[1] == N) {
        ans = i;
        break;
      }
    }
    if (r_cnt[r] == N) {
      ans = i;
      break;
    }
    if (c_cnt[c] == N) {
      ans = i;
      break;
    }
  }
  COUT(ans);

  cerr << endl;
  dump(N);
  dump(T);
  // VECCERR(r_cnt);
  // VECCERR(c_cnt);
  // VECCERR(v_cnt);
}
