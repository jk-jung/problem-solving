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
    int n, h, k;
    cin >> n >> h >> k;
    ll r = 0, c = 0;
    vi v(n);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n;) {
        if (c + v[i] <= h) {
            c += v[i];
            i++;
        } else {
            ll t = (c + v[i] - h + k - 1) / k;
            r += t;
            c -= t * k;
            if (c < 0)c = 0;
        }
    }
    r += (c + k - 1) / k;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
