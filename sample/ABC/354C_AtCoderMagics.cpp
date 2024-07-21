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
  cin >> N;

  vector<ll> A(N + 1, 0), C(N + 1, 0);
  map<ll, int> A_i;
  reps(i, N) {
    cin >> A.at(i) >> C.at(i);
    A_i[A.at(i)] = i;
  }

  vector<pair<ll, ll>> A_C(0);
  reps(i, N) A_C.pb(make_pair(A.at(i), C.at(i)));
  sort(all(A_C));

  stack<pair<ll, ll>> st;
  st.push(make_pair(A_C.at(0).first, A_C.at(0).second));
  for (int i = 1; i < N; i ++) {
    ll a = A_C.at(i).first;
    ll c = A_C.at(i).second;
    while (!st.empty() && st.top().second > c) st.pop();
    st.push(make_pair(A_C.at(i).first, A_C.at(i).second));
  }
  set<int> ans;
  while (!st.empty()) {
    ans.insert(A_i[st.top().first]);
    st.pop(); // 末尾要素を削除
  }
  COUT(SZ(ans));
  VECCOUT(ans);

  cerr << endl;
  dump(N);
  // VECCERR(A);
  // VECCERR(C);
  // for (auto p: A_C) cerr << p.first << ": " << p.second << endl;
}
