#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*this below code only works when 1<=a,b <=1000000*/

// const int N=1e6+1;
// vector<long long>prefix(N,0);

// void solve() {
// 	long long day,tsc;cin>>day>>tsc;

// 	while(day--){
// 		long long a,b,cost;cin>>a>>b>>cost;
// 		prefix[a]+=cost;
// 		prefix[b+1]-=cost;
// 	}

// 	for(long long i=1;i<N;i++){
// 		prefix[i]+=prefix[i-1];
// 	}

// 	long long ans=0;
// 	for(long long i=0;i<N;i++){
// 		ans+=min(prefix[i],tsc);
// 	}

// 	cout<<ans<<"\n";
// }



void solve() {
	long long day,tsc;cin>>day>>tsc;
	vector<long long>start(day),end(day),cost(day);

	for(long long i=0;i<day;i++){
		cin>>start[i]>>end[i]>>cost[i];
	}

	set<long long>st; //this will store the uniques days at which total cost of subscripiton of a day has changed
	for(long long i=0;i<day;i++){
		st.insert(start[i]);
		st.insert(end[i]+1);
	}

	//do mapping of 1st day of total cost change to 0th index and so on
	//key 0 -> will point to start[0]
	map<long long,long long>mp;
	long long idx=0;
	for(auto itr: st){
		mp[itr]=idx;
		idx++;
	}

	//compute prefix sum
	vector<long long>prefix(idx+1,0);

	for(long long i=0;i<day;i++){
		long long idx1=mp[start[i]];
		long long idx2=mp[end[i] + 1];

		prefix[idx1]+=cost[i];
		prefix[idx2]-=cost[i];
	}

	for(long long i=1;i<=idx;i++){
		prefix[i]+=prefix[i-1];
	}


	//no of days which has the total subscription cost was prefix[i]
	vector<long long>set_to_vec(st.begin(),st.end());

	long long ans=0;
	for(long long i=0;i<idx;i++){
		long long no_of_days = set_to_vec[i+1] - set_to_vec[i];
		ans+=(no_of_days)*min(prefix[i],tsc);
	}

	cout<<ans<<"\n";
}

int32_t main()
{

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t=1;
	//cin >> t;
	while (t--) solve();
	return 0;
}




