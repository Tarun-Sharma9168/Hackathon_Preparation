// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define MAX 100002 
#define pb push_back//vector function 

// Vector to store primes 
vector<int> primes; //storing the prime numbers

// k_cnt stores count of prime factors of k 
// current_map stores the count of primes 
// in the current sub-array 
// cnts[] is an array of maps which stores 
// the count of primes for element at index i 
unordered_map<int, int> k_cnt, current_map, cnts[MAX]; 

// Function to store primes in 
// the vector primes 
void sieve() 
{ 

	int prime[MAX]={0}; 
	prime[0] = prime[1] = 1; //these are not prime
	for (int i = 2; i < MAX; i++) { 
		if (prime[i] == 0) { 
			for (int j = i * 2; j < MAX; j += i) { 
				if (prime[j] == 0) { 
					prime[j] = i; //put the prime factor in it in every column which is divisible by i
				} 
			} 
		} 
	} 
	for (int i = 2; i < MAX; i++) { 
		if (prime[i] == 0) {//if still there is 0 somewhere means it is prime so we store i only there in that column 
			prime[i] = i; 
			primes.pb(i); //and push all prime numbers in the primes vector
		} 
	} 
} 
// Function to count sub-arrays whose product 
// is divisible by k 
ll countSubarrays(int* arr, int n, int k) 
{ 

	// Special case
    //making it into the long long so this is the general tactics 
	if (k == 1) { 
		cout << (1LL * n * (n + 1)) / 2; 
		return 0; 
	} 

    //making of the prime factors of the k that is given
    //k_primes contain the prime factorization of k
	vector<int> k_primes; 
	for (auto p : primes) { 
		while (k % p == 0) { 
			k_primes.pb(p); 
			k /= p; 
		} 
	} 

	// If k is prime and is more than 10^6 
	if (k > 1) { 
		k_primes.pb(k); 
	} 
    
    //K_cnt contains the power associated with every prime numbers
	for (auto num : k_primes) 
    { 
		k_cnt[num]++; 
	} 

	// Two pointers initialized 
	int l = 0, r = 0; 

	ll ans = 0; 

	while (r < n) { 

		// Add rth element to the current segment 
		for (auto& it : k_cnt) { 

			// p = prime factor of k 
			int p = it.first; 
            //just finding the prime factors of the element
			while (arr[r] % p == 0) { 
				current_map[p]++; 
				cnts[r][p]++; 
				arr[r] /= p; 
			} 
		} 

		// Check if current sub-array's product 
		// is divisible by k 
		int flag = 0; 
		for (auto& it : k_cnt) { 
			int p = it.first; 
			if (current_map[p] < k_cnt[p]) { 
				flag = 1; 
				break; 
			} 
		} 

		// If for all prime factors p of k, 
		// current_map[p] >= k_cnt[p] 
		// then current sub-array is divisible by k 

		if (!flag) { 

			// flag = 0 means that after adding rth element 
			// segment's product is divisible by k 
			ans += n - r; 

			// Eliminate 'l' from the current segment 
			for (auto& it : k_cnt) { 
				int p = it.first; 
				current_map[p] -= cnts[l][p]; 
			} 

			l++; 
		} 
		else { 
			r++; 
		} 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;

    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	sieve(); 
	cout << countSubarrays(arr, n, k); 
    cout<<"\n"; 
	return 0; 
} 
