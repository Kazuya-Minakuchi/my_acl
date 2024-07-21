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


int H, W;
unordered_set<int> sensor_all;
unordered_set<int> used;
vector<vector<int>> move_xy = {
  {-1, -1},  {-1, 0},  {-1, 1},
  {0, -1},  {0, 1},
  {1, -1},  {1, 0},  {1, 1}
};
int g_cnt = 0;

int encode(pair<int, int> ij) {
  int i, j;
  tie(i, j) = ij;
  return i * W + j;
}

pair<int, int> decode(int k) {
  return make_pair(k / W, k % W);
}

void update_s_used(int i, int j) {
  if (i < 0) return;
  else if (i >= H) return;
  else if (j < 0) return;
  else if (j >= W) return;

  int s = encode(make_pair(i, j));
  if (sensor_all.count(s) == 0) return;
  else if (used.count(s)) return;

  used.insert(s);
  for (auto xy : move_xy) {
    update_s_used(i + xy.at(0), j + xy.at(1));
  }
  return;
}

void update_get_g_cnt() {
  for (auto s: sensor_all) {
    if (used.count(s)) continue;
    int i, j;
    tie(i, j) = decode(s);
    update_s_used(i, j);
    g_cnt++;
  }
}

int main() {
  cin >> H >> W;

  vector<string> masu(H);
  rep(i, H) {
    rep(j, W) {
      char c;
      cin >> c;
      if (c == '.') continue;
      int k = encode(make_pair(i, j));
      sensor_all.insert(k);
    }    
  }

  update_get_g_cnt();
  COUT(g_cnt);

  ENDL;
  dump(H);
  dump(W);
}
