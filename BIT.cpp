template<typename T=long long>
class BIT{
  // 0-index
  // update(i,a) i番目の要素をaに更新するO(logn)
  // sum(l,r) [l,r)の合計を求める O(logn)
  // sum_query(r) [0,r)の合計を求める
private:
  T sum_query(int i){
    T res=0;
    for(int x=i-1;x>=0;x=(x&(x+1))-1)res+=bit[x];
    return res;
  }
public:
  int n;
  vector<T> bit;
  BIT(int n_):n(n_),bit(n_,0){}
  void update(int i, T a){
    for(int x=i;x<n;x|=x+1){
      bit[x]+=a;
    }
  }
  T sum(int l,int r){
    return sum_query(r)-sum_query(l);
  }
};
