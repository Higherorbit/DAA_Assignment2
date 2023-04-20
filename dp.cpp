#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define in(n) int n; cin>>n;
#define w(x) int x; cin>>x; while(x--)
#define int long long
#define str(s) string s; cin>>s;
#define sz(x) static_cast<int>(x.size())
#define endl "\n"
#define dbg(x) cerr << #x << "->" << x << "\n"
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
#define prntp(x) cerr<<#x<<'{';for(auto T:x)cerr<<T.first<<'-'<<T.second<<' ';cerr<<"}\n";
const int mod = 1000000007;
const int MAX=10000;
#define FAST cin.tie(0)->sync_with_stdio(0);

typedef tree <int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;

struct point{
	int x,y;
	bool operator<(const point& cur) const{
		return x<cur.x;
	}
} points[MAX+1];

int32_t main(){
	in(n)    ;
	in(c);
	for(int i=0;i<n;i++){
		in(x);
		in(y);
		points[i].x=x;
		points[i].y=y;
	}
	for(auto i:points){
		cout<<i.x<<" "<<i.y<<endl;
	}
}