//mod=1000000007
ll mod_pow(ll x,ll n){
  ll res=1;
  while(n>0){
    if(n&1)res=res*x%mod;
    x=x*x%mod;
    n>>=1;
  }
  return res;
} 