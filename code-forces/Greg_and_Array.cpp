#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
	long long n,m,k;cin>>n>>m>>k;

	vector<long long>arr(n+1);
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}

	vector<long long>oper_freq_prefix(m+1,0); // this will store that how many times we need to perform each operation
	vector<long long>diff_prefix(n+1,0); //  this will store that by how much each index will get increased after performing all the operatons
	
     // below 2 vectors will store the operations
	vector<pair<long long,long long>> range(m+1);
	vector<long long>val(m+1,0);
	
	for(long long i=1;i<=m;i++){
		long long l,r,x;cin>>l>>r>>x;
		range[i]={l,r};
		val[i]=x;
	}


	for (int i = 1; i <= k; i++) {
		long long s_op,e_op;cin>>s_op>>e_op;

		oper_freq_prefix[s_op]++;
		if(e_op+1 <= m)
		    oper_freq_prefix[e_op+1]--;
	}

	//prefix sum of oper_freq_prefix[i]
	for(long long i=1;i<=m;i++)
		oper_freq_prefix[i] += oper_freq_prefix[i-1];


	//now we have the details of freq of each operation
	//now calulate by how much each index value will increase

	//prefix sum of diff_prefix[i]
	for(long long i=1;i<=m;i++){
	    long long x=range[i].first;
	    long long y=range[i].second;
	    long long d=val[i];
	    
		diff_prefix[x] += d*oper_freq_prefix[i];
		
		if(y+1 <= n)
		diff_prefix[y+1] -= d*oper_freq_prefix[i];
	}

	for(long long i=1;i<=n;i++)
		diff_prefix[i]+=diff_prefix[i-1];


	for(long long i=1;i<=n;i++)
		cout<<(diff_prefix[i] + arr[i]) <<" ";
	cout<<"\n";
}

int32_t main()
{

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t=1;
	//cin >> t;
	while (t--) solve();
	return 0;
}


