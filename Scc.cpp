class Scc{
private:
  vector<vector<int>> g,rg;
  vector<int> order;
  vector<bool> visited;
  int V;
  void dfs(int s){
    if(visited[s])return ;
    visited[s]= true;
    for(int nx:g[s])dfs(nx);
    order.push_back(s);
  }
  void rdfs(int s,int t){
    if(comp[s]!=-1)return ;
    comp[s]=t;
    for(int nx:rg[s])rdfs(nx,t);
  }
public:
  vector<vector<int>> Graph;
  vector<int> comp;
  Scc(int v){
    V = v;
    g.resize(v);
    rg.resize(v);
    order = vector<int>();
    visited.resize(v,false);
    Graph = vector<vector<int>>();
    comp.resize(v,-1);
  }
  void add_edge(int from,int to){
    g[from].push_back(to);
    rg[to].push_back(from);
  }
  void init(){
    for(int i = 0;i<V;i++)dfs(i);
    reverse(order.begin(),order.end());
    int number=0;
    for(int i=0;i<V;i++){
      if(comp[order[i]]==-1)rdfs(order[i],number++);
    }
    Graph.resize(number);
    for(int i=0;i<V;i++){
      for(int v: g[i]){
	if(comp[i]==comp[v])continue;
	Graph[comp[i]].push_back(comp[v]);
      }
    }
  }
};

