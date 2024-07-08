/*
 *Description:* Computes lowest common ancestor, precomputed in $O(V log V)$, $O(log V)$ per query, uses binary lifting and works for directed and undirected graphs.
*/
struct LCA {
  vector<vector<int>> T, parent;
  vector<int> depth, vis;
  int LOGN, V;
  // If WA, bigger logn?
  LCA(vector<vector<int>> &T, int logn = 20): T(T), LOGN(logn), vis(T.size()) {
    parent.assign(T.size()+1, vector<int>(LOGN, 0));
    depth.assign(T.size()+1, 0);
    // If is forest
    //for (int u = 0; u < T.size(); u++)
    //  if (!vis[u]) dfs(u);
  }
  void dfs(int u = 0, int p = -1) {
    vis[u] = true;
    for (int v : T[u]) {
      if (p != v) {
        depth[v] = depth[u] + 1;
        parent[v][0] = u;
        for (int j = 1; j < LOGN; j++)
          parent[v][j] = parent[parent[v][j-1]][j-1];
          dfs(v, u);
      }
    }
  }
  int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u]-depth[v];
    for (int j = LOGN - 1; j >= 0; j--)
      if (k & (1 << j))
        u = parent[u][j];
    if (u == v)
      return u;
    for (int j = LOGN - 1; j >= 0; j--) {
      if (parent[u][j] != parent[v][j]) {
        u = parent[u][j];
        v = parent[v][j];
      }
    }        
    return parent[u][0];
  }
};
