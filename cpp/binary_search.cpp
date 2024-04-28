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
// string S;
char C;

vector<ll> A(100010, 0);

ll calc_print_cnt(ll time) {
  ll cnt = 0;
  reps(i, N) cnt += time / A.at(i);
  return cnt;
}

// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
    if (calc_print_cnt(index) >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = INF; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main() {
  // A12
  cin >> N >> K;

  reps(i, N) cin >> A.at(i);

  ll ans = binary_search(K);
  COUT(ans);

  cerr << endl;
  dump(N);
  dump(K);
  // reps(i, N) cerr << A.at(i) << " "; cerr << endl;
}
