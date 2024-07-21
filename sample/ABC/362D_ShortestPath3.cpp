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

vector<ll> get_cost_dijk(int start, vector<vector<pair<int, ll>>> &G) {
  // set variables
  int n = G.size();
  vector<ll> cost(n + 1, LINF);
  vector<bool> kakutei(n + 1, false);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
  // init
  cost.at(start) = 0;
  Q.push(make_pair(cost[start], start));
  // dijk
  while (!Q.empty()) {
    int pos = Q.top().second; Q.pop();

    if (kakutei.at(pos) == true) continue;
    kakutei.at(pos) = true;
    for (auto p : G.at(pos)) {
      int nex = p.first;
      ll cst = p.second;
      if (cost.at(nex) > cost.at(pos) + cst) {
        cost.at(nex) = cost.at(pos) + cst;
        Q.push(make_pair(cost.at(nex), nex));
      }
    }
  }
  return cost;
}

int main() {
  cin >> N >> M;

  vector<ll> A(N + 1, 0);
  reps(i, N) cin >> A[i];

  vector<int> U(M + 1, 0), V(M + 1, 0);
  vector<ll> B(M + 1, 0);
  reps(i, M) cin >> U[i] >> V[i] >> B[i];

  vector<vector<pair<int, ll>>> G(N + 1);
  reps(i, M) {
    G[U[i]].pb(make_pair(V[i], B[i] + A[V[i]]));
    G[V[i]].pb(make_pair(U[i], B[i] + A[U[i]]));
  }

  vector<ll> cost = get_cost_dijk(1, G);
  for (int i = 2; i <= N; i++) {
    SCOUT(A[1] + cost[i]);
  }
  ENDL;

  ENDL;
  dump(N);
  dump(M);
  // reps(i, N) SCOUT(A[i]);
  // ENDL;
  // reps(i, M) {
  //   SCOUT(U[i]);
  //   SCOUT(V[i]);
  //   SCOUT(B[i]);
  //   ENDL;
  // }
}
