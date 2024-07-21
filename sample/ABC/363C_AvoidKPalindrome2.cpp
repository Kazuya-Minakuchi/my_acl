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


int N, K;
string S;

// sにchar_cnt文字の回文が含まれるかどうかを判定する
bool include_palindrome(string s, int char_cnt) {
    int n = s.size();
    for (int i = 0; i <= n - char_cnt; i++) {
      bool is_palindrome = true;
      for (int j = 0; j < char_cnt / 2; j++) {
        if (s[i + j] != s[i + char_cnt - 1 - j]) {
            is_palindrome = false;
            break;
        }
      }
      if (is_palindrome) {
        return true;
      }
    }
    return false;
}

int main() {
  cin >> N >> K;
  cin >> S;
  sort(all(S));

  ll ans = 0;
  while(true) {
    if (!include_palindrome(S, K)) {
      ans++;
      // dump(S);
    }
    if (!next_permutation(all(S))) break;
  }
  COUT(ans);

  ENDL;
  dump(N);
  dump(K);
  dump(S);
}
