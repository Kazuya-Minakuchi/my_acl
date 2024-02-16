#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

const int INF = 1e9;

struct Edge {
  int to, cap, rev;
};

class MaximumFlow {
public:
  int size_;
  vector<bool> used;
  vector<vector<Edge>> G;

  MaximumFlow(int vertex_cnt) {
    size_ = vertex_cnt;
    vector<bool> newUsed(vertex_cnt + 1, false);
    vector<vector<Edge>> newG(vertex_cnt + 1, vector<Edge>(0));
    used = newUsed;
    G = newG;
  }

  void add_edge(int from, int to, int volume) {
    int Current_Gf = G.at(from).size();
    int Current_Gt = G.at(to).size();
    G.at(from).push_back(Edge{to, volume, Current_Gt}); // {to, volume, reverse index}
    G.at(to).push_back(Edge{from, 0, Current_Gf});
  }

  // search max flow from pos to goal
  int dfs(int pos, int goal, int F) {
    if (pos == goal) return F;  // goal
    used.at(pos) = true;

    auto edges = G.at(pos);
    for (int i = 0; i < edges.size(); i++) {
      Edge edge = edges.at(i);
      if (edge.cap == 0) continue;  // no remain volume
      if (used.at(edge.to)) continue;  // skip used vertex to avoid circulation

      int flow = dfs(edge.to, goal, min(F, edge.cap));  // seach from next vertex

      if (flow >= 1) {
        G.at(pos).at(i).cap -= flow;  // decrease remain volume
        G.at( G.at(pos).at(i).to ).at( G.at(pos).at(i).rev ).cap += flow;  // increase reverse volume
        return flow;
      }
    }
    return 0;  // no flow route
  }

  int max_flow(int from, int to) {
    int Total_Flow = 0;
    while (true) {
      for (int i = 0; i <= size_; i++) used.at(i) = false;
      int F = dfs(from, to, INF);

      if (F == 0) break;
      Total_Flow += F;
    }
    return Total_Flow;
  }
};

int main() {
  // A68
  int N, M;
  cin >> N >> M;

  vector<int> A(M + 1), B(M + 1), C(M + 1);
  for (int i = 1; i <= M; i++) {
    cin >> A.at(i) >> B.at(i) >> C.at(i);
  }

  MaximumFlow Z(N);
  for (int i = 1; i <= M; i++) {
    Z.add_edge(A.at(i), B.at(i), C.at(i));
  }

  cout << Z.max_flow(1, N) << endl;

  cerr << endl;
  cerr << N << endl;
  cerr << M << endl;
  // for (int i = 1; i <= N; i++) {
  //   cerr << i << ": ";
  //   for (auto p : G.at(i)) {
  //     cerr << "{" << p.first << ", " << p.second << "}, ";
  //   }
  //   cerr << endl;
  // }
}
