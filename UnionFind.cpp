struct UnionFind{
  vector<int> par;
  UnionFind(int n=0):par(n,-1){}
  int root(int x){
    if(par[x]<0)return x;
    return par[x]=root(par[x]);//経路圧縮
  }
  bool unite(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return false;
    if(-par[x]<-par[y])swap(x,y);//大きい方に小さい方をくっつける
    par[x]+=par[y];
    par[y]=x;
    return true;
  }
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -par[root(x)];}
};
