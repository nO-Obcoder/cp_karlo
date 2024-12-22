/*
Given an array with all 0s initially perform the following Q queries on it.
In the ith query you will be given 3 integers: Li, Ri, Xi. You need to add Xi, to
all the values in the array from index Li to Ri.
After performing all the queries print the final state of the array.

Tc: O(1)
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

	vector<long long>diff(n+1,0); //  this will store that by how much each index will get increased after performing all the operatons

	long long q;cin>>q;
	while(q--){
		long long l,r,x;cin>>l>>r>>x;
		diff[l]+=x;
		diff[r+1]-=x;
	}

	//prefix sum of diff[i]
	for(long long i=1;i<=n;i++)
		diff[i] += diff[i-1];

	for(long long i=1;i<=n;i++)
		cout<<(diff[i] + arr[i]) <<" ";
	cout<<"\n";
}

int32_t main()
{

	long long t=1;
	cin >> t;
	while (t--) solve();
	return 0;
}
