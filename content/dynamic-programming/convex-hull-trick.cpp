/*
 *Description:* Given lines mantains a convex space to maximum queries, $a$ is the slope and $b$ the constant.
 *Important:* Sort slopes before use
 *Status:* Partially tested
*/
struct convex_hull_trick {
  vector<ll> A, B;
  const ll inf = numeric_limits<ll>::max()/4;
  double cross(ll i, ll j, ll k) {
    return 1.0*(A[j] - A[i]) * (B[k] - B[i]) - 1.0*(A[k] - A[i]) * (B[j] - B[i]);
  }
  void add(ll a, ll b) {
    A.push_back(a), B.push_back(b);
    while(A.size() > 2 and cross(A.size() - 3, A.size() - 2, A.size() - 1) <= 0)
      A.erase(A.end() - 2), B.erase(B.end() - 2);
  }
  ll query(ll x) {
    if(A.empty()) return inf;
    ll l = 0, r = A.size() - 1;
    while (l < r) {
      ll mid = (l + r)/2;
      ll f1 = A[mid] * x + B[mid];
      ll f2 = A[mid + 1] * x + B[mid + 1];
      if(f1 > f2) l = mid + 1;
      else r = mid;
    }
    return A[l] * x + B[l];
  }
};
