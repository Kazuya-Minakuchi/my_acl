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

ll D, H, K, L, M, N, Q, R, W;
string S, T;
// char C;


ll calc_mst(ll &N, vector<pair<ll, pair<int, int>>> &EdgeList) {
  // N: number of vertexs
  // EdgeList: <cost, <v1, v2>>
  sort(all(EdgeList));
  atcoder::dsu d2(N + 1);
  ll mst = 0;
  for (auto p : EdgeList) {
    int idx1 = p.second.first;
    int idx2 = p.second.second;
    if (d2.same(idx1, idx2) == false) {
      d2.merge(idx1, idx2);
      mst += p.first;
    }
  }
  return mst;
}

int main() {
  // A67
  cin >> N >> M;

  vector<pair<ll, pair<int, int>>> EdgeList(0);
  ll C;
  int a, b;
  ll c;
  reps(m, M) {
    cin >> a >> b >> c;
    EdgeList.pb(make_pair(c, make_pair(a, b)));
  }

  ll ans = calc_mst(N, EdgeList);
  COUT(ans);

  cerr << endl;
  dump(N);
  dump(M);
}
