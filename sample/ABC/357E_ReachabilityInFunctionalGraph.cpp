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
vector<set<int>> from_to(200010);
vector<ll> from_to_cnt(200010, 0);
vector<int> search_cnt(200010, 0);

int main() {
  cin >> N;

  vector<int> a(N + 1, 0);
  reps(i, N) cin >> a[i];

  atcoder::scc_graph g(N + 1);
  reps(i, N) g.add_edge(i, a[i]);

  vector<vector<int>> scc = g.scc();
  reverse(all(scc));

  vector<int> to_cnt(N + 1, 0);
  for (auto& scc : scc) {
    if (scc.size() == 1) {
      to_cnt[scc[0]] = to_cnt[a[scc[0]]] + 1;
    }
    else {
      for (auto& i : scc) {
        to_cnt[i] = SZ(scc);
      }
    }
  }


  ll ans = 0;
  reps(i, N) ans += to_cnt[i];
  COUT(ans);

  ENDL;
  dump(N);
}
