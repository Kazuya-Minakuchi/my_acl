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
string T, S;

bool check_is_ok(string &S, string &T) {
  if (S == T) return true;

  int s_size = S.size();
  int t_size = T.size();
  if (abs(s_size - t_size) >= 2) return false;

  if (s_size == t_size) {
    for (int i = 0; i < s_size; i++) {
      if (S.at(i) != T.at(i)) {
        string rem_s = S.substr(i + 1, s_size);
        string rem_t = T.substr(i + 1, t_size);
        return (rem_s == rem_t);
      }
    }
  }
  else if (s_size > t_size) {
    for (int i = 0; i < t_size; i++) {
      if (S.at(i) != T.at(i)) {
        string rem_s = S.substr(i + 1, s_size);
        string rem_t = T.substr(i, t_size);
        return (rem_s == rem_t);
      }
    }
  }
  else {  // if (s_size < t_size)
    for (int i = 0; i < s_size; i++) {
      if (S.at(i) != T.at(i)) {
        string rem_s = S.substr(i, s_size);
        string rem_t = T.substr(i + 1, t_size);
        return (rem_s == rem_t);
      }
    }
  }
  return true;
}

int main() {
  cin >> N >> T;

  int ans_cnt = 0;
  vector<int> ans(0);
  rep(i, N) {
    cin >> S;
    if (check_is_ok(S, T)) {
      ans_cnt++;
      ans.push_back(i + 1);
    }
  }
  COUT(ans_cnt);
  for (int i = 0; i < ans.size(); i++) {
    SCOUT(ans.at(i));
  }
  ENDL;

  ENDL;
  dump(N);
  dump(T);
}
