#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()


#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

class UnionFind {
  public:
  vector<int> par;
  vector<int> siz;

  UnionFind(int N) {
    vector<int> newPar(N + 1, -1);  // no parent
    vector<int> newSiz(N + 1, 1); // all size=1
    par = newPar;
    siz = newSiz;
  }

  int root(int x) {
    while (true) {
      if (par.at(x) == -1) break;  // no parent=root
      x = par.at(x);  // move to parent
    }
    return x;
  }

  void unite(int u, int v) {
    int RootU = root(u);
    int RootV = root(v);
    if (RootU == RootV) return;  // already united
    if (siz.at(RootU) < siz.at(RootV)) {  // unite smaller to larger
      par.at(RootU) = RootV;
      siz.at(RootV) += siz.at(RootU);
    }
    else {
      par.at(RootV) = RootU;
      siz.at(RootU) += siz.at(RootV);
    }
  }

  bool same(int u, int v) {  // check if roots are same
    if (root(u) == root(v)) return true;
    return false;
  }
};

int main() {
  // B66
  int N, M;
  cin >> N >> M;

  vector<int> A(M + 1), B(M + 1);
  for (int i = 1; i <= M; i++) cin >> A.at(i) >> B.at(i);

  int Q;
  cin >> Q;

  vector<int> query(Q + 1), x(Q + 1, -1), u(Q + 1, -1), v(Q + 1, -1);
  unordered_set<int> x_set;
  for (int i = 1; i <= Q; i++) {
    cin >> query.at(i);
    if (query.at(i) == 1) {
      int temp_x;
      cin >> temp_x;
      x.at(i) = temp_x;
      x_set.insert(temp_x);
    }
    else cin >> u.at(i) >> v.at(i);
  }

  UnionFind UF(N);

  for (int i = 1; i <= M; i++) {
    if (!x_set.count(i)) UF.unite(A.at(i), B.at(i));
  };

  vector<bool> connected(0);
  for (int i = Q; i >= 1; i--) {
    if (query.at(i) == 1) {
      UF.unite(A.at(x.at(i)), B.at(x.at(i)));
    }
    else {
      connected.push_back(UF.same(u.at(i), v.at(i)));
    }
  }

  reverse(all(connected));

  for (auto c: connected) {
    if (c) cout << "Yes" << endl;
    else cout << "No" << endl;
  }


  cerr << endl;
  cerr << N << endl;
  cerr << M << endl;
  cerr << Q << endl;
  // for (int i = 1; i <= N; i++) {
  //   cerr << i << ": ";
  //   for (auto p : G.at(i)) {
  //     cerr << "{" << p.first << ", " << p.second << "}, ";
  //   }
  //   cerr << endl;
  // }
}
