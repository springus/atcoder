#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,a,n) for(int i=a;i<(n);i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
using ll=long long;
using ld=long double;
template<typename T> using vc = vector<T>;
template<typename T,typename U> using pp=pair<T,U>;
template<typename T> using pq=priority_queue<T>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T> >;
using vi=vc<int> ;using vvi=vc<vi>;using vvvi=vc<vvi>;
using vl=vc<ll>;using vvl=vc<vl>;using vvvl=vc<vvl>;
using pi=pp<int,int>;using pd=pp<double,double>;using pl=pp<ll,ll>;using pip=pp<int,pi>;
using vpi=vc<pi>;using vvpi=vc<vpi>;using vpip=vc<pip>;using vvpip=vc<vpip>;
using vs=vc<string>;using vss=vc<vs>;using vst=vc<set<int> >;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int inf=1001001001;
const ll infl=100100100100100100;
const ll mod=1000000007;
const int mx = 500050;
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
void rprint(T &a) {printf("%.10Lf\n",a);}
template<typename T>
void coutarray(vc<T>& v) { rep(i, sz(v)) {if(i)cout << " "; cout << v[i];} cout << endl; }
template<typename T>
void coutmatrix(vc<vc<T> >& v) { rep(i,sz(v)) { rep(j, sz(v[i])) {cout << " "; cout << v[i][j]; } cout << "\n";} };
void _main();int main(){ios::sync_with_stdio(false);std::cin.tie(nullptr); _main();return 0;}

void solve(){
}
void _main(){
  int TS=1;
  //cin>>TS;
  rep(tss,TS){solve();}
}
