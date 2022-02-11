template <typename T>
vector<T> two_dimensions_compress(vector<T> &G1, vector<T> &G2,ll w ) {
    vector<T> res;
    int N = (int)G1.size();
    for (int i = 0; i < N; ++i) {
        for (T d = -1; d <= 1; ++d) { 
            T tc1 = G1[i] + d;
            T tc2 = G2[i] + d;
	    if(0<=tc1 && tc1<=w)res.push_back(tc1);
	    if(0<=tc2 && tc2<=w)res.push_back(tc2);
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int i = 0; i < N; i++) {
        G1[i] = lower_bound(res.begin(), res.end(), G1[i]) - res.begin();
        G2[i] = lower_bound(res.begin(), res.end(), G2[i]) - res.begin();
    }
    return res;
}
