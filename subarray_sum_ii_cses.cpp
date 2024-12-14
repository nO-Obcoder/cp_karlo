/*
Miles to go before I sleep,
Miles to go before I sleep.
*/


// #define int            long long int
// #define F              first
// #define S              second
// #define pb             push_back
// #define si             set <int>
// #define vi             vector <int>
// #define pii            pair <int, int>
// #define vpi            vector <pii>
// #define vpp            vector <pair<int, pii>>
// #define mii            map <int, int>
// #define mpi            map <pii, int>
// #define spi            set <pii>
// #define endl           "\n"
// #define sz(x)          ((int) x.size())
// #define all(p)         p.begin(), p.end()
// #define double         long double
// #define que_max        priority_queue <int>
// #define que_min        priority_queue <int, vi, greater<int>>
// #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
// #define print(a)       for(auto x : a) cout << x << " "; cout << endl
// #define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
// #define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

// inline int power(int a, int b)
// {
// 	int x = 1;
// 	while (b)
// 	{
// 		if (b & 1) x *= a;
// 		a *= a;
// 		b >>= 1;
// 	}
// 	return x;
// }

// template <typename Arg1>
// void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
// template <typename Arg1, typename... Args>
// void __f (const char* names, Arg1&& arg1, Args&&... args)
// {
// 	const char* comma = strchr (names + 1, ',');
// 	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
// }

// int is_prime(long long n){
// 	int flag=0;
// 	for(long long i=2;i*i<=n;i++){
// 		if(!(n%i)){
// 			flag = 1;
// 			break;
// 		}
// 	}

// 	return flag;
// }

// const int N = 200005;

// int32_t main()
// {
// 	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// 	//clock_t z = clock();

// 	int t;
// 	cin >> t;
// 	while (t--) solve();

// 	//cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

// 	return 0;
// }


#include <map>
#include <iostream>
using namespace std;

//don't use unordered map -> will get tle
long long optimal_using_prefix_sum_concept(long long arr[],long long n,long long k){

	long long count=0,prefix_sum=0;
	map<long long,long long>mp;
	mp[prefix_sum]++;
	for(long long i=0;i<n;i++){
		prefix_sum+=arr[i];

		//calucate x-k
		long long remove = prefix_sum - k;

		// Add the number of subarrays to be removed:
		count+=mp[remove];

		
		// Update the count of prefix sum
		mp[prefix_sum]+= 1;
	}

	return count;
}


// long long brute(long long arr[],long long n,long long s){
// 	long long count=0;

// 	for(long long i=0;i<n;i++){
// 		long long sum=0;
// 		for(long long j=i;j<n;j++){
// 			sum+=arr[j];

// 			if(sum == s)
// 				count++;
// 		}
// 	}

// 	return count;
// }


void solve() {
	long long n,s;
	cin>>n>>s;

	long long arr[n];
	for(long long i=0;i<n;i++)
		cin>>arr[i];

	//cout<<brute(arr,n,s)<<"\n";
	cout<<optimal_using_prefix_sum_concept(arr,n,s)<<"\n";

}

int32_t main()
{

	// int t=1;
	// //cin >> t;
	// while (t--) solve();
	solve();
	return 0;
}


