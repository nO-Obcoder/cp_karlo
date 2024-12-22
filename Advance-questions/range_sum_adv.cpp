/*
Given an array of N elements, answer the following Q queries in O(1) time
● Query: L, R
● Result = A[L] + 2 * A[L + 1] + 3 * A[L + 2] + .... (R - L + 1) * A[R]

Ans:  from l to r  { sigma(i*Ai) - (l-1)*sigma(Ai) }
*/



#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void solve() {
	long long n;cin>>n;

	long long arr[n+1];
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}

	vector<long long>prefix1(n+1,0);
	vector<long long>prefix2(n+1,0);
	
	//prefix sum of A[i]
	prefix1[1]=arr[1];
	for(long long i=2;i<=n;i++)
		prefix1[i]+=prefix1[i-1] + arr[i];

	for(auto ele: prefix1)
		cout<<ele <<" ";
	cout<<"\n";

	//prefix sum of i*A[i]
	prefix2[1]=arr[1];
	for(long long i=2;i<=n;i++)
		prefix2[i]+=prefix2[i-1] + i*arr[i];

	for(auto ele: prefix2)
		cout<<ele <<" ";
	cout<<"\n";

	long long q;cin>>q;
	while(q--){
		long long l,r;cin>>l>>r;
		long long ans=0;

		ans+= prefix2[r] - prefix2[l-1];
		ans-= (l-1)*(prefix1[r] - prefix1[l-1]);
		cout<<ans<<"\n";
	}
}

int32_t main()
{

	long long t=1;
	cin >> t;
	while (t--) solve();
	return 0;
}

