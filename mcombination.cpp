const long long mod=1e9+7;
//const long long mod= ;
class mint{
private:long long x;
public:
  mint(long long _x=0) : x((_x%mod+mod)%mod){ }
  mint operator -( )const{return mint(-x);}
  mint& operator +=(const mint &rhs) {
    if((this->x+=rhs.x)>=mod)x-=mod;
    return *this;
  }
  mint& operator -=(const mint &rhs){
    if((this->x+=mod-rhs.x)>=mod)x-=mod;
    return *this;
  }
  mint& operator *=(const mint &rhs){
    (this->x*=rhs.x)%=mod;
    return *this;
  }
  mint& operator /=(const mint &rhs){
    return (*this)*=rhs.inv();
  }
  mint operator+(const mint &rhs) const{return mint(*this)+=rhs;}
  mint operator-(const mint &rhs) const{return mint(*this)-=rhs;}
  mint operator*(const mint &rhs) const{return mint(*this)*=rhs;}
  mint operator/(const mint &rhs) const{return mint(*this)/=rhs;}
  mint pow(long long t)const{
    if(t<1)return 1;
    mint a=pow(t>>1);
    a*=a;
    if(t&1)a *= *this;
    return a;
  }
  mint inv() const{return pow(mod-2);}
  friend ostream &operator<<(ostream &os ,const mint &a){return os<<a.x;}
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
