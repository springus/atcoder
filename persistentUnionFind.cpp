struct persistentUnionFind{
  int now;
  vector<int> par;
  vector<int> rank;
  vector<int> time;
  vector<vector<pair<int,int>>> num;
  persistentUnionFind(int n){
    now=0;
    par.resize(n);num.resize(n);
    for(int i=0;i<n;++i){
      par[i]=i;
      num[i].push_back(make_pair(0,1));
    }
    rank=vector<int>(n,0);
    time=vector<int>(n,inf);
  }
  int root(int x,int t){
    if(t<time[x])return x;
    else return root(par[x],t);
  }
  bool unite(int x,int y){
    ++now;
    x=root(x,now);
    y=root(y,now);
    if(x==y)return false;
    if(rank[x]<rank[y])swap(x,y);
    if(rank[x]==rank[y])++rank[x];
    num[x].push_back(make_pair(now,size(x,now)+size(y,now)));
    par[y]=x;
    time[y]=now;
    return true;
  }
  int size(int x,int t){
    x=root(x,t);
    int ac=0;
    int wa=num[x].size();
    while(wa-ac>1){
      int wj=(wa+ac)/2;
      if(num[x][wj].first<=t)ac=wj;
      else wa=wj;
    }
    return num[x][ac].second;
  }
  bool same(int x,int y,int t){return root(x,t)==root(y,t);}
};
