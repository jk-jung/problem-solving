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

int c[10000005];
ll s[10000005];
int cnt[10000005];

void init() {
    for (int i = 2; i < 10000005; i++) {
        if (c[i])continue;
        for (int j = i; j < 10000005; j += i) {
            c[j] = 1;
            s[i] += cnt[j];
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, cnt[x]++;

    init();
    int m;
    cin >> m;

    for (int i = 1; i < 10000005; i++) {
        s[i] += s[i - 1];
    }


    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l > 10000000) {
            cout << 0 << endl;
            continue;
        }
        r = min(r, 10000000);
        cout << s[r] - s[l - 1] << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
