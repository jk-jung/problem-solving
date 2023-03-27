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
    ll n;
    string v;
    cin >> n >> v;

    string t = v;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    if (t.size() == 1) {
        cout << n * (n + 1) / 2 % 998244353 << endl;
        return;
    }

    char y = v[0];
    ll r = 1;
    for (char x: v) {
        if (y != x)break;
        r++;
        y = x;
    }

    reverse(v.begin(), v.end());
    y = v[0];
    for (char x: v) {
        if (y != x)break;
        r++;
        y = x;
    }

    if (v[0] == v.back()) {
        ll s = 1, e = n - 2;
        while (v[s] == v.back())s++;
        while (v[e] == v[0]) e--;
        r += s * (n - e - 1);
    }

    cout << r % 998244353 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
