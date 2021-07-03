#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))

ll mod = 1000000007;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll r = ((n+1) / 2) * 2 % mod;

        ll base = 2;
        for(ll i = 3;;i++){
            ll next = lcm(base, i);
            ll k1 = n / base;
            ll k2 = n / next;

            r = (r + (k1 - k2) * i) % mod;
            base = next;
            if (k1 == 0) break;
        }
        cout << r <<endl;
    }

}