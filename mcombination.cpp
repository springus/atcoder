const long long mod=1e9+7;
//const long long mod= ;
 struct mint{
  long long x;
  mint(long long x=0) : x((x%mod+mod)%mod){ }
  mint operator -( )const{return mint(-x);}
  mint& operator +=(const mint &a) {
    if((x+=a.x)>=mod)x-=mod;
    return *this;
  }
  mint& operator -=(const mint &a){
    if((x+=mod-a.x)>=mod)x-=mod;
    return *this;
  }
  mint& operator *=(const mint &a){
    (x*=a.x)%=mod;
    return *this;
  }
  mint& operator /=(const mint &a){
    return (*this)*=a.inv();
  }
  mint operator+(const mint &a) const{return mint(*this)+=a;}
  mint operator-(const mint &a) const{return mint(*this)-=a;}
  mint operator*(const mint &a) const{return mint(*this)*=a;}
  mint operator/(const mint &a) const{return mint(*this)/=a;}
  mint pow(long long t)const{
    if(t<1)return 1;
    mint a=pow(t>>1);
    a*=a;
    if(t&1)a *= *this;
    return a;
  }
  mint inv() const{return pow(mod-2);}
};
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint aPb(int a, int b) { if (b < 0 || a < b) return mint(0); return fact[a] * ifact[a - b]; }
  mint aCb(int a, int b) { if (b < 0 || a < b) return mint(0); return fact[a] * ifact[a - b] * ifact[b]; }
  mint nHk(int n, int k) { if (n == 0 && k == 0) return mint(1); if (n <= 0 || k < 0) return 0;
  return aCb(n + k - 1, k); } // nHk = (n+k-1)Ck : n is separator
};
