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


// long long brute(long long arr[],long long n,long long s,long long e){
// 	long long sum=0;

// 	for(long long i=s-1;i<=(e-1);i++){
// 		sum+=arr[i];
// 	}

// 	return sum;
// }


void solve() {
	long long n,q;
	cin>>n>>q;

	long long arr[n];
	long long prefix_sum[n];
	
	prefix_sum[0]=arr[0];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
		prefix_sum[i]=arr[i] + prefix_sum[i-1];
	}

	while(q--){
		long long s,e;
		cin>>s>>e;
		// cout<<brute(arr,n,s,e)<<"\n";
		cout<<( (prefix_sum[e-1]- prefix_sum[s-1]) + arr[s-1])<<"\n";
	}

}

int32_t main()
{

	// int t=1;
	// //cin >> t;
	// while (t--) solve();
	solve();
	return 0;
}


