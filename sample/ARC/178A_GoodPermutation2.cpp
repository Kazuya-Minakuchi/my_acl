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


int main() {
  cin >> N >> M;

  vector<bool> A_flag(N + 1, false);
  reps(i, M) {
    int a;
    cin >> a;
    A_flag[a] = true;
  }

  if (A_flag[1] || A_flag[N]) {
    cout << "-1" << endl;
    return 0;
  }

  set<int> i_set;
  reps(i, N) i_set.insert(i);

  vector<int> ans(0);
  int next_i;
  reps(i, N) {
    if (!A_flag[i]) {
      next_i = *begin(i_set);
    }
    else {
      for (auto index: i_set) {
        if (index > i) {
          next_i = index;
          break;
        }
      }
    }
    ans.pb(next_i);
    i_set.erase(next_i);
  }
  VECCOUT(ans);

  cerr << endl;
  dump(N);
  dump(M);
}
