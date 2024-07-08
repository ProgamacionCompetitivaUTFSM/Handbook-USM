/*
 *Description:* Solves assignament problem in $O(n^3)$. If the matrix is rectangular in $O(n^2 m)$, where $n <= m$
 *Status:* Tested
*/
void Hungarian(vector<vector<int>> &A, vector<pair<int, int>> &result, int &C, const int INF = 1e6 + 1) {
  int n = A.size() - 1, m = A[0].size() - 1;
  vector<int> minv(m + 1), u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  vector<bool> used(m + 1);
  for (int i = 1; i <= n; ++i) {
    p[0] = i; int j0 = 0;
    for (int j = 0; j <= m; ++j)
      minv[j] = INF;
    for (int j = 0; j <= m; ++j)
      used[j] = false;
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          int cur = A[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) minv[j] = cur, way[j] = j0;
          if (minv[j] < delta) delta = minv[j], j1 = j;
        }
      for (int j = 0; j <= m; ++j) {
        if (used[j]) u[p[j]] += delta, v[j] -= delta;
        else minv[j] -= delta;
      }
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while(j0);
  }
  for (int i = 1; i <= m; ++i)
    result.push_back(make_pair(p[i], i));
  C = -v[0];
}