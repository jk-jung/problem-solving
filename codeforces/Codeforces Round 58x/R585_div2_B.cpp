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
    ll a = n * (n + 1) / 2, r = 0;
    ll s = 0;
    vector<ll> cnt(2);
    cnt[0]++;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x < 0) s ^= 1;
        r += cnt[s];
        cnt[s]++;
    }
    cout << a - r << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
