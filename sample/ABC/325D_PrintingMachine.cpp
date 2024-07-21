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

  // 小さい順に取り出される優先度付きキュー
  priority_queue<ll, vector<ll>, greater<>> start;
  unordered_map<ll, vector<ll>> start_end;
  ll td_max = 0;
  ll t, d;
  rep(i, N) {
    cin >> t >> d;
    start.push(t);
    start_end[t].push_back(t + d);
    chmax(td_max, t + d);
  }

  ll ans = 0;
  // 小さい順に取り出される優先度付きキュー
  priority_queue<ll, vector<ll>, greater<>> pq;
  for (ll i = 1; i <= td_max; i++) {
    // skip to next start time
    if (pq.empty()) {
      // remove start times before i
      while (!start.empty() && start.top() < i) start.pop();
      if (start.empty()) break;
      else i = start.top();
    }
    // add end times
    if (start_end.count(i)) {
      for (auto end : start_end.at(i)) pq.push(end);
    }
    // remove end times before i
    while (!pq.empty() && pq.top() < i) pq.pop();
    // end time count
    if (!pq.empty()) {
      pq.pop();
      ans++;
    }
  }

  COUT(ans);

  ENDL;
  dump(N);
}
