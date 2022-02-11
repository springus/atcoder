template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    int n = (int)a.size();
    vector<long long> dp(n, infl);
    for (int i = 0; i < n; ++i) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), infl) - dp.begin();
}
