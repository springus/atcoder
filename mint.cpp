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
