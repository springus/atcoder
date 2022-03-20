vector<long long> Dijkstra(const vector<vector<pair<int,long long>>> &G,int s=0){
  int n=(int)G.size();
  vector<long long > res(n,infl);
  res[s]=0;
  priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> que;
  que.push(make_pair(0,s));
  while(que.size()){
    long long d=que.top().first;
    int v=que.top().second;
    que.pop();
    if(res[v]<d)continue;
    for(auto np:G[v]){
      int nv=np.first;
      long long nd=np.second;
      if(res[nv]>res[v]+nd){
	res[nv]=res[v]+nd;
        que.push(make_pair(res[nv],nv));
      }
    }
  }
  return res;
}
