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

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    vector<ll> r;
    for (ll x = 1;x <= 81; x++) {
        ll y = x;
        for (int i = 1; i < a; i++)y *= x;
        y = y * b + c;
        if(y < 0 || y > 1e9)continue;
        ll t = y;
        ll z = 0;
        while(y){
            z += y % 10;
            y /= 10;
        }

        if (z == x)r.pb(t);
    }
    cout << r.size() << endl;
    for (ll x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
