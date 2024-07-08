/*
 * Descripcion:* Get the area of a polygon
 - If you want the double of the area, just enable the flag
 *Status:* Highly tested
*/
template<typename T>
T polygonArea(vector<Point2D<T>> P, bool x2 = 0) {
  T area = 0;
  for(int i = 0; i < P.size()-1; ++i)
    area += P[i]^(P[i+1]);
  // Si el primer punto se repite, sacar:
  area += (P.back())^(P.front());
  return abs(area)/ (x2 ? 1 : 2);
}