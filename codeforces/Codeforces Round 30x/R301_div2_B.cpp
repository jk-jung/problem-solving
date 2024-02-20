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
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vi a(k);
    for (int &z: a) cin >> z, x -= z;
    sort(a.begin(), a.end());
    int c = 0;
    for (int z: a)if (z < y)c++;
    if (c >= (n + 1) / 2) {
        cout << -1;
        return;
    }

    vi r;
    int tmp = (n + 1) / 2 - c - 1;
    for (int i = 0; i < n - k; i++) {
        if(tmp) {
            tmp --;
            r.pb(1);
            x --;
        }else {
            r.pb(y);
            x -= y;
        }
    }

    if(x<0)cout << -1 ;
    else {
        for (int z: r)cout << z << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
