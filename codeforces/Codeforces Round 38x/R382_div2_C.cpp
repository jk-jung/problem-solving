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


ll d[1110];

ll f(ll x) {
    if (x == 0) return 1;
    if (x == 1) return 2;
    if(d[x]) return d[x];
    return d[x] = f(x - 1) + f(x - 2);

}

void solve() {
    ll n;
    cin >> n;

    ll r = 0;
    for (ll i = 1; i <= 1000; i++) {
        if(f(i) > n)break;
        r = i;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
