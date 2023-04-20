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
#define INF numeric_limits<double>::infinity()
const int MAX=10000;
#define FAST cin.tie(0)->sync_with_stdio(0);

typedef tree <int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;

struct point{
	double x,y;
	bool operator<(const point& cur) const{
		return x<cur.x;
	}
} points[MAX+1];

int32_t main(){
	in(n)    ;
	in(c);
	for(int i=1;i<=n;i++){
		double x,y;
		cin>>x>>y;
		points[i].x=x;
		points[i].y=y;
	}
	std::vector<double> sumX,sumY,sumXY,sumXX;
	sort(points+1,points+n+1);
	sumX[0]=0;
	sumY[0]=0;
	sumXY[0]=0;
	sumXX[0]=0;
	for(int i=1;i<=n;i++){
		sumX[i]=sumX[i-1]+points[i].x;
		sumY[i]=sumY[i-1]+points[i].y;
		sumXY[i]=sumXY[i-1]+points[i].x*points[i].y;
		sumXX[i]=sumXX[i-1]+points[i].x*points[i].x;
	}
	double e[MAX+1][MAX+1];
	memset(e,0.0,sizeof(e));
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			// calculate the slope and intercept for the line
			// connecting pi,.. pj
			double curSumX=sumX[j]-sumX[i-1];
			double curSumY=sumY[j]-sumY[i-1];
			double curSumXY=sumXY[j]-sumXY[i-1];
			double curSumXX=sumXX[j]-sumXX[i-1];
			double a,b;
			double numSlope=(j-i+1)*(curSumXY)-curSumX*curSumY;
			if(numSlope==0){
				a=0.0;
			}
			else{
				if((j-i+1)*(curSumXX)==curSumX*curSumX){
					a=INF;
				}
				else{
					a=numSlope/((j-i+1)*(curSumXX)-curSumX*curSumX);
				}
			}
			b=curSumY-(j-i+1)*curSumX/(j-i+1);
			// now we need to calculate the error
			for(int k=i;k<=j;k++){
				double err=points[k].y-(a*points[k].x+b);
				e[i][j]+=err*err;
			}
		}
	}
	vector<double>dp(MAX+1,INT_MAX);
	dp[0]=0;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			dp[j]=min(dp[j],e[i][j]+c+dp[i-1]);
		}
	}
	cout<<dp[n]<<endl;
}