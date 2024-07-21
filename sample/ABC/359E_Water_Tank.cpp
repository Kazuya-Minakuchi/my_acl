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


int main() {
  cin >> N;

  vector<ll> H(N + 1, 0);
  reps(i, N) cin >> H[i];

  vector<ll> ans_v(N + 1, 0);
  map<ll, int> h_i;
  reps(i, N) {
    // dump(i);
    // dump(H[i]);
    auto itr = h_i.lower_bound(H[i]);
    // SCERR(itr->first);
    // SCERR(" ");
    // SCERR(itr->second);
    // ENDL;
    if (itr != h_i.end()) ans_v[i] = ans_v[itr->second] + H[i] * (i - itr->second);
    else ans_v[i] = H[i] * i;

    auto temp_itr = h_i.begin();
    while (temp_itr != h_i.end() && temp_itr->first < H[i]) {
      temp_itr = h_i.erase(temp_itr);
    }

    h_i[H[i]] = i;
  }

  reps(i, N) SCOUT(ans_v[i] + 1);

  ENDL;
  dump(N);
  // VECCERR(H);
}
