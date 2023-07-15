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
    cin >> n;
    ll r = 0, c = 0;
    n++;
    while (n % 2 == 0) {
        n /= 2;
        if (c == 0)r++;
        else r += 1ll << (c - 1);
        c++;
    }
    if (r == 0)cout << (n == 1 ? 0 : n) << endl;
    else cout << (n - 1) * (1ll << (c - 1)) + r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
