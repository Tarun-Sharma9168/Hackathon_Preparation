#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back

const ll MOD = 998244353;

void debug(string t = "") {
	cout << "hello" + t << '\n' ;
}

ll binexp(ll a,ll b) {
	if(b == 0) {
		return 1ll;
	}
	else if(b == 1) {
		return 1ll * a%MOD;
	}
	else if(b%2) {
		ll temp = binexp(a,(b-1)/2) ;
		temp = (temp*temp)%MOD ;
		return (a*temp)%MOD ;
	}
	else {
		ll temp = binexp(a,b/2) ;
		temp = (temp*temp)%MOD ;
		return temp ;
	}	
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int tc ; cin >> tc;  // int counter = 1;
    while(tc--)
    {
    	ll n; cin >> n; ll arr[n]; unordered_map<ll,ll> mp;
    	for(int i=0;i<n;i++) {
    		cin >> arr[i] ;
    		mp[arr[i]]++;
    	}
    	ll ans = 0; ll t1 = 1ll ,t2 ; ll m = n;
    	// cout << binexp(2,1ll * 1000000000ll) << '\n' ;
    	for(ll i=1;i<=n+1;i++) {
    		if(mp[i] > 0) {
    			m -= mp[i] ;
    			t2 = (i * ((t1 * binexp(2,m))%MOD)) % MOD ;
    			ans = (ans + t2)%MOD ;
    			// ans = (ans + (t1 * (binexp(2,m-mp[i]))*%MOD)  i)%MOD )%MOD ) % MOD ;
    			t2 = binexp(2,mp[i]) ;
    			if(t2 == 0) {
    				t2 = MOD - 1;
    			}
    			else {
    				t2--;
    			}
    			t1 = (t1 * t2)%MOD ;    			    			
    		}
    		else {
    			t2 = (i * ((t1 * binexp(2,m))%MOD))%MOD ;
    			ans = (ans + t2)%MOD ;
    			// ans = (ans + (t1 * ((binexp(2,m))*i)%MOD)%MOD)%MOD;
    			break;
    		}
    	}
    	cout << (ans)%MOD << '\n' ;
    }

    return 0;
}

