#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;


long long int solve(int n, vector<vector<int> > queries){

	vector<pair<LL,LL> > dp;
	for(int i = 0; i<queries.size(); i++){
		int a = queries[i][0];
		int b = queries[i][1];
		int k = queries[i][2];

		dp.pb(mp(a,k));
		dp.pb(mp(b+1,-1*k));
	}

	sort(dp.begin(), dp.end());

	long long int acc = 0, ans = 0;
	for(int i = 0; i<dp.size(); i++){
		acc += dp[i].ss;
		ans = max(ans,acc);
	}
	return ans;

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n,m;
	vector<vector<int> > queries;

	cin>>n>>m;
	for(int i = 0; i<m; i++){
		vector<int> q;
		int a;
		cin>>a; q.pb(a);
		cin>>a; q.pb(a);
		cin>>a; q.pb(a);

		queries.pb(q);
	}
	cout<<"Foi?"<<endl;
	long long int  r = solve(n,queries);
	cout<<r<<endl;

	return 0;
}
