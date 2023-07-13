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
    int n, k;

    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    ll pos = 0, sum = 0;
    while (k--) {
        ll x;
        cin >> x;
        while(pos < n && sum + v[pos] < x) {
            sum += v[pos];
            pos++;
        }
        cout << pos + 1 <<" " << x - sum << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
