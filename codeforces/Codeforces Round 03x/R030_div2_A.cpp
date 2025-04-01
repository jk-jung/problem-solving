#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    ll x, y, n;
    cin >> x >> y >> n;

    for (ll i = -1000; i <= 1000; i++) {
        ll t = 1;
        for (int j = 0; j < n; j++) {
            t *= i;
            if (ab(t) > 1e9)break;
        }
        if(x * t == y){
            cout << i << endl;
            return;
        }
    }
    cout << "No solution" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
