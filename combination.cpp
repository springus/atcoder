class combination{
  // not modint 
  // O(n^2) n<=1e4
  // long long n<=60
public:
  vector<vector<long long>> v;
  combination(int n){
    v.resize(n+1,vector<long long>(n+1,0));
    for(int i=0;i<n;i++){
      v[i][0]=1;
      v[i][i]=1;
    }
    for(int i=1;i<n;i++){
      for(int k=1;k<i;k++){
	v[i][k]=(v[i-1][k-1]+v[i-1][k]);
      }
    }
  }
};
