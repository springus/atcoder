template <typename T = int>
struct PotentialUnionFind {
  vector<int> par;
  vector<T> diff_weight;
  PotentialUnionFind(int n,T SUM_=0):par(n, -1), diff_weight(n,SUM_) { }
  int root(int x) {
    if(par[x] < 0) return x;
    int r = root(par[x]);
    diff_weight[x] += diff_weight[par[x]];
    return par[x] = r;
  }
  bool unite(int x, int y, T w){
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if(x == y) return false;
    if(par[x] > par[y]){ swap(x,y); w = -w; }
    par[x] += par[y];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
  T weight(int x){root(x); return diff_weight[x];}
  T diff(int x, int y){return weight(y)-weight(x);}
  bool same(int x, int y){return root(x)==root(y);}
  int size(int x){return -par[root(x)];}
};
