/*
  *Author:* Marcos Kolodny (MarcosK)
  *Description:* Returns $x$ such that $a^x = b (mod m)$ or $-1$ if inexistent
  *Status:* Tested on josupo.jp
*/
ll discrete_log(ll a,ll b,ll m) {
  a%=m, b%=m;
  if(b == 1) return 0;
  int cnt=0, tmp=1;
  for(int g=__gcd(a,m);g!=1;g=__gcd(a,m)) {
    if(b%g) return -1;
    m/=g, b/=g;
    tmp = tmp*a/g%m;
    ++cnt;
    if(b == tmp) return cnt;
  }
  map<ll,int> w;
  int s = ceil(sqrt(m)), base = b;
  for (int i = 0; i < s; i++)
    w[base] = i, base=base*a%m;
  base=binpow(a,s,m);
  ll key=tmp;
  for(int i = 1; i < s+2; i++) {
    key=base*key%m;
    if(w.count(key)) return i*s-w[key]+cnt;
  }
  return -1;
}