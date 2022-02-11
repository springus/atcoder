struct Edge {
    long long from;
    long long to;
    long long cost;
};
using Edges = vector<Edge>;
bool bellman_ford(const Edges &E, int V, int s, vector<long long> &flag) {
    flag.resize(V, infl);
    flag[s] = 0;
    int cnt = 0;
    while (cnt < V) {
        bool end = true;
        for (auto e : E) {
            if (flag[e.from] != infl && flag[e.from] + e.cost < flag[e.to]) {
                flag[e.to] = flag[e.from] + e.cost;
                end = false;
            }
        }
        if (end) break;
        cnt++;
    }
    return (cnt == V);//trueは閉路あり
}
