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


int K, N;
string S;

bool is_palindrome(string s) {
  int n = s.size();
  rep(i, n / 2) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}

int main() {
  cin >> N >> K;
  cin >> S;

  vector<map<string, mint>> dp(N + 1);
  dp[0][""] = 1;
  reps(i, N) {
    // dump(i);
    char c = S[i - 1];
    // dump(c);
    for (auto [s, v] : dp[i - 1]) {
      string next_s = s;
      if (SZ(next_s) == K) next_s.erase(0, 1);
      // dump(next_s);
      if (c != '?') {
        next_s += c;
        if (SZ(next_s) < K) dp[i][next_s] += v;
        else {
          if (!is_palindrome(next_s)) dp[i][next_s] += v;
        }
      }
      else {
        string next_s_a = next_s;
        next_s_a += "A";
        if (SZ(next_s_a) < K) dp[i][next_s_a] += v;
        else {
          if (!is_palindrome(next_s_a)) dp[i][next_s_a] += v;
        }

        string next_s_b = next_s;
        next_s_b += "B";
        if (SZ(next_s_b) < K) dp[i][next_s_b] += v;
        else {
          if (!is_palindrome(next_s_b)) dp[i][next_s_b] += v;
        }
      }
    }
  }

  mint ans = 0;
  for (auto [s, v] : dp[N]) {
    ans += v;
  }
  COUT(ans.val());

  ENDL;
  dump(K);
  dump(N);
}
