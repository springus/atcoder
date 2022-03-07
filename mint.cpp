const long long mod=1e9+7;
//const long long mod=998244353;
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
