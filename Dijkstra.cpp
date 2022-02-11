vector<long long> Dijkstra(vector<vector<pair<int,int>>> &G,int s=0){
  vector<long long > res(n,infl);
  res[s]=0;
  priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > que;
  que.push(make_pair(0,s));
  while(que.size()){
    long long dis=que.top().fi;
    int v=que.top().se;
    que.pop();
    if(res[v]<dis)continue;
    for(auto nx:G[v]){
      int nv=nx.fi;
      int w=nx.se;
      if(chmin(res[nv],res[v]+w))que.push(make_pair(res[nv],nv));
    }
  }
  return res;
}
