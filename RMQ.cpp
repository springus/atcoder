template<typename T>
struct RMQ{
  //RPM:[0,n-1]の最小値を管理する
  //update(i,x): i番目のの要素をxに更新O(logn)
  //find(a,b)[x,b)で最小の要素を取得O(logn)
  const T INF =pow(2,31)-1;
  int n;
  vector<T> Tree;
  RMQ(int n_): n(), Tree(n_*4,INF){
    int x=1;
    while(n_ > x)x*=2;
    n=x;
  }
  void update(int i , T x){
    i+=n-1;
    Tree[i]=x;
    while(i>0){
      i=(i-1)/2;
      Tree[i]=min(Tree[i*2+1],Tree[i*2+2]);
    }
  }
  T find(int a,int b){return find_sub(a,b,0,0,n);}
  T find_sub(int a,int b,int k,int l,int r){
    if(r<=a || b<=l)return INF;
    else if(a<=l && r<=b)return Tree[k];
    else {
      T vl = find_sub(a,b,k*2+1,l,(l+r)/2);
      T vr = find_sub(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
};
