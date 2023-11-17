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


ll go(ll n, ll k) {
    if (n == 1) return 1;
    ll t = 1ll << (n - 1);
    if(k == t) return n;
    if(k < t) return go(n - 1, k);
    return go(n - 1, k - t);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    cout << go(n, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
