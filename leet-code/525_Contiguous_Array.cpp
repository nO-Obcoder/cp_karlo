#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void solve() {
	long long n;cin>>n;

	long long arr[n];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}

	for(long long i=0;i<n;i++){
		if(!arr[i])
			arr[i]=-1;
	}

	long long prefix_sum=0,ans=0;
	unordered_map<long long,long long>mp; //store the the index at which sum occurs for first time

	for(long long i=0;i<n;i++){
		prefix_sum+=arr[i];

		if(prefix_sum == 0){
			ans=i+1;
		} else if(mp.find(prefix_sum) != mp.end()){
			ans = max(ans,(i-mp[prefix_sum]));
		} else{
			mp[prefix_sum]=i;
		}
	}
	
	cout<<ans<<"\n";
}

int32_t main()
{

	long long t=1;
	cin >> t;
	while (t--) solve();
	return 0;
}
