#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

#include <atcoder/all>

const int INF = 1e9;

int op(int a, int b) {
  return max(a, b);
}

int e() {
  return 0;
}

int use_segtree(vector<int> A) {
  int N = A.size();

  int a_max = 0;
  rep(i, N) a_max = max(a_max, A.at(i));

  atcoder::segtree<int, op, e> a_len(a_max + 1);
  rep(i, N) {
    int a = A.at(i);
    int prev_len = a_len.prod(0, a);
    int cur_len = a_len.get(a);
    int new_len = max(cur_len, prev_len + 1);
    a_len.set(a, new_len);
  }
  return a_len.all_prod();
}

int use_longest_increasing_sequence(vector<int> A) {
  int N = A.size();
  vector<int> L(0);
  L.push_back(A.at(0));
  for(int i = 1; i < N; i++) {
    int a = A.at(i);
    int n_l = L.size();
    if (a > L.at(n_l - 1)) L.push_back(a);
    else {
      int pos = lower_bound(all(L), a) - L.begin();
      L.at(pos) = a;
    }
  }
  return L.size();
}

int use_longest_week_increasing_sequence(vector<int> A) {
  int N = A.size();
  vector<int> L(0);
  L.push_back(A.at(0));
  for(int i = 1; i < N; i++) {
    int a = A.at(i);
    int n_l = L.size();
    if (a >= L.at(n_l - 1)) L.push_back(a);
    else {
      int pos = upper_bound(all(L), a) - L.begin();
      L.at(pos) = a;
    }
  }
  return L.size();
}

int main() {
  // A24
  int N;
  cin >> N;

  vector<int> A(N);
  int a_max = 0;
  rep(i, N) {
    int a;
    cin >> a;
    A.at(i) = a;
    a_max = max(a_max, a) ;
  }

  // int ans = use_segtree(A);
  int ans = use_longest_week_increasing_sequence(A);
  cout << ans << endl;

  cerr << endl;
  cerr << N << endl;
  // for (int i = 1; i <= N; i++) cerr << A.at(i) << ' ';
  // cerr << endl;
  // for (int i = 1; i <= N; i++) cerr << a_len.get(i) << ' ';
  // cerr << endl;
}
