#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 1012346;

long long int solve(vector<LL> arr, LL r){
	cout<<"Start"<<endl;
	map<LL,LL> dp;
    for(LL i = 0; i < arr.size(); i++)
        dp[arr[i]]++;
    
    cout<<"End freq"<<endl;
    LL ans = 0;
    for(int i = 0; i + 2 < arr.size(); i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        ans += dp[arr[i]] * dp[arr[i] * pow(r,1)] * dp[arr[i] * pow(r,2)];
    }
    
    cout<<"End func"<<endl;
    return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	LL n,k;
	cin>>n>>k;

	vector<LL> idx;
	for(LL i = 0; i<n; i++){
		cout<<i<<endl;
		LL a; cin>>a;
		idx.push_back(a);
	}
	cout<<"GO"<<endl;
	cout<<solve(idx,k)<<endl;
	return 0;
}
