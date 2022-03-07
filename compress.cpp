template<typename T>
vector<T> compress(vector<T>& a){
  vector<int> b=a,res((int)a.size());
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());
  for(int i=0;i<(int)a.size();i++){
    res[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin();
  }
  return res;
}
