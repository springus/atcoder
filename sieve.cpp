//n以下の素数を求めるtrueは素数
vector<bool> sieve(ll n){
  vector<bool> flag(n+1,true);
  flag[0]=flag[1]=false;
  for(ll i=2;i<=n;++i){
    if(!flag[i])continue;
    for(ll k=2*i;k<=n;k+=i)flag[k]=false;
  }
  return flag;
}
