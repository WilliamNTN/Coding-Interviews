#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 201234;


int n,d;
int vals[maxN];
map<int,int> hash;

int solve(){

	for(int i = 0; i<d; i++)
		hash[vals[i]]++;

	int ans = 0;

	for(int i = d; i<n; i++){
		int search = (d+1)/2;
		int j;
		for(j = 0; j<=200, search > 0; j++){
			search -= hash[j];
		};j--;

		double found = 0;
		if(d % 2 != 0) found = j;
		else{

			if(search < 0) found = j;
			else{

				for(int k = j+1; k <= 200; k++){
					if(hash[k] > 0){
						found = (j*1.0 + k*1.0)/2.0;
						break;
					}
				}
			}
		}
		if(found * 2 <= vals[i]) ans++;

		hash[vals[i]]++;
		hash[vals[i-d]]--;
	}

	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>d;
	for(int i = 0; i<n; i++) cin>>vals[i];

	cout<<solve()<<endl;
	return 0;
}
