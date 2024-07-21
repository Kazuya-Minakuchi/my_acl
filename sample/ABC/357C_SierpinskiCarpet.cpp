#include <bits/stdc++.h>
#include <atcoder/all>

typedef int64_t ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const ll LZERO = 0;

using namespace std;
// using mint = atcoder::modint998244353;
using mint = atcoder::modint1000000007;

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

vector<vector<char>> get_carpet(int K) {
  if (K == 0) return {{'#'}};

  int n = 1;
  reps(i, K) n *= 3;

  vector<vector<char>> carpet(n, vector<char>(n, '.'));
  auto sub_carpet = get_carpet(K-1);
  rep(i, n) rep(j, n) {
    if (i / (n / 3) == 1 && j / (n / 3) == 1) {
      carpet[i][j] = '.';
    }
    else {
      carpet[i][j] = sub_carpet[i % (n / 3)][j % (n / 3)];
    }
  }

  return carpet;
}

int main() {
  cin >> N;

  auto carpet = get_carpet(N);

  rep(i, carpet.size()) {
    rep(j, carpet[i].size()) {
      cout << carpet[i][j];
    }
    cout << endl;
  }

  ENDL;
  dump(N);
}
