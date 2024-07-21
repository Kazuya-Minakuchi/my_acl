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


ll N, K;

int main() {
  cin >> N >> K;

  mint sum_except_one = (N + 1) * N / 2 - 1;
  dump(sum_except_one.val());

  mint mod_n = N;
  dump(mod_n.val());

  mint mod_move = 2;
  mint mod_stay = (N - 1) * (N - 1) + 1;
  dump(mod_move.val());
  dump(mod_stay.val());

  vector<pair<mint, mint>> prob_one_other(K + 1);
  prob_one_other[0] = {1, 0};
  mint prob_one, prob_other;
  reps(i, K) {
    prob_one = prob_one_other[i - 1].first * mod_stay + prob_one_other[i - 1].second * (N - 1) * mod_move;
    prob_other = prob_one_other[i - 1].second * mod_stay + (prob_one_other[i - 1].second * (N - 2) + prob_one_other[i - 1].first) * mod_move;
    prob_one_other[i] = {prob_one, prob_other};
  }

  mint ans = 0;
  ans += prob_one_other[K].first;
  ans += (prob_one_other[K].second * sum_except_one);
  ans /= mod_n.pow(2 * K);
  COUT(ans.val());

  ENDL;
  dump(N);
  dump(K);
}
