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
string S;

int main() {
  cin >> N;
  cin >> S;

  map<int, int> num_cnt;
  for (char s: S) {
    int s_num = int(s-'0');
    num_cnt[s_num]++;
  }

  ll ans = 0;
  ll search_max = 1;
  rep(i, N) search_max *= 10;
  map<int, int> temp_num_cnt;
  ll temp_num, wari;
  for (ll i = 0; i * i < search_max; i++) {
    temp_num = i * i;
    wari = 1;
    temp_num_cnt = {};
    rep(j, N) {
      int temp = temp_num / wari % 10;
      temp_num_cnt[temp]++;
      wari *= 10;
    }

    if (temp_num_cnt == num_cnt) ans++;
  }
  COUT(ans);

  ENDL;
  dump(N);
  dump(S);
  dump(search_max);
}