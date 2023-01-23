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

int n;
int a[100005];
int t[100005];
int s[20][100005];

int f(int x, int y) {
    if (x == 0) return t[y];
    return t[y] - t[x - 1];
}

int go(int y, int x) {
    if (x >= n) return 0;
    int &r = s[y][x];
    if (r != -1)return r;
    if (y == 0) r = 0;
    else if (y == 1) {
        r = (a[x] + a[x + 1]) >= 10;
    } else {
        int z = y - 1;
        int zz = (1 << z);
        int aa = go(z, x);
        int bb = go(z, x + zz);
        r = aa + bb;
        int ee = x + zz + zz - 1;
        if (ee < n)
            r += (f(x, x + zz - 1) % 10 + f(x + zz, x + zz + zz - 1) % 10) >= 10;
    }
    return r;
}

void solve() {
    cin >> n;
    memset(s, -1, sizeof(s));
    for (int i = 0; i < n; i++)cin >> a[i];
    t[0] = a[0];
    for (int i = 1; i < n; i++)t[i] = t[i - 1] + a[i];
    for (int k = 1; k < 20; k++) {
        for (int i = 0; i < n; i++) {
            s[k][i] = go(k, i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int i = 0;
        for (; (1 << i) < (y - x) + 1; i++);
        cout << go(i, x-1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
