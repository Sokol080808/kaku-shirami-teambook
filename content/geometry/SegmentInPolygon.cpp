/**
 * Author: starch
 * Date: 2024-09-14
 * Source: https://codeforces.com/gym/101471/submission/149579502
 * Description: length of longest segment inside polygon
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=210;
int n,w;
double s,res,ans;
int sgn(ll x){return !x?0:(x>0?1:-1);}
struct point{
	int x,y;
	point operator-(point a){return {x-a.x,y-a.y};}
	ll operator|(point a){return 1ll*x*a.y-1ll*y*a.x;} 
	double len(){return sqrt(1ll*x*x+1ll*y*y);} 
}p[N];
vector<pair<double,int> >v;
double isp(point x1,point y1,point x2,point y2){
	return 1.0*((x2-x1)|(y2-x1))/((y2-x2)|(y1-x1));
}
double calc(point a,point b){
	v.clear(),w=s=res=0;
	for(int i=1;i<=n;i++){
		int x=sgn((b-a)|(p[i-1]-a)),y=sgn((b-a)|(p[i]-a));
		if(x==y) continue;
		v.push_back({isp(a,b,p[i-1],p[i]),(x<y?1:-1)*(x&&y?2:1)});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<(int)v.size();i++){
		if(w) s+=v[i].first-v[i-1].first;
		else res=max(res,s),s=0;
		w+=v[i].second;
	}
	return max(res,s)*((b-a).len());
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
	p[0]=p[n];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) ans=max(ans,calc(p[i],p[j]));
	printf("%.9lf\n",ans);
	return 0;
} 
