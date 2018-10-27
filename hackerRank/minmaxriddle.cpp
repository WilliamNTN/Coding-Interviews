#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 1012345;

LL n;
LL vals[maxN];
LL mins[maxN];

vector<LL> riddle(){

	vector<LL> ans;

	LL thisMax = -0x3f3f3f3f;

	for(int i = 0; i<n; i++)
		thisMax = max(thisMax,mins[i]);

	ans.pb(thisMax);

	for(LL win = 2; win <=n; win++){
		thisMax = -0x3f3f3f3f;

		for(LL i = win-1; i<n; i++){
			mins[i] = min(vals[i],vals[i-1]);
			thisMax = max(thisMax,mins[i]);
		}
		ans.pb(thisMax);
		for(int i = 0; i<n; i++)
			vals[i] = mins[i];
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>vals[i];
		mins[i] = vals[i];
	}

	vector<LL> ans = riddle();

	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	
	cout<<endl;
	return 0;
}
