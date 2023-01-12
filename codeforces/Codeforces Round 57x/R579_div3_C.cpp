#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void solve() {
    ll n, r = 0, x;
    cin >> n;
    while (n--) {
        cin >> x;
        r = gcd(r, x);
    }
    ll m = 0;
    for(ll i = 1;i*i<=r;i++){
        if(r % i == 0)m ++ ;
        if(r % i == 0 && i != r / i)m++;
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
