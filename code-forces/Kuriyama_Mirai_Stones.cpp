#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve() {
	long long n;
	cin>>n;

	long long arr[n],arr_sort[n];
	long long prefix_sum[n],sorted_prefix_sum[n];
	
	prefix_sum[0]=arr[0];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		arr_sort[i]=arr[i];
		prefix_sum[i]=arr[i] + prefix_sum[i-1];
	}

	sort(arr_sort,arr_sort+n);
	sorted_prefix_sum[0]=arr_sort[0];
	for(long long i=0;i<n;i++){
		sorted_prefix_sum[i]=arr_sort[i] + sorted_prefix_sum[i-1];
	}

	long long q;
	cin>>q;
	while(q--){
		long long c,s,e;
		cin>>c>>s>>e;
		if(c==1)
			cout<<( (prefix_sum[e-1]- prefix_sum[s-1]) + arr[s-1])<<"\n";
		else
			cout<<( (sorted_prefix_sum[e-1]- sorted_prefix_sum[s-1]) + arr_sort[s-1])<<"\n";
	}

}

int32_t main()
{

	int t=1;
	// //cin >> t;
	while (t--) solve();
	return 0;
}


