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
    int n, m;
    cin >> n >> m;
    int r = n / m;
    vi v(n), c(m + 1);
    for (int &x: v) {
        cin >> x;
        if (x <= m)c[x]++;
    }
    int pos = 1, rr = 0;
    for (int i = 0; i < n; i++) {
        while (pos <= m && c[pos] >= r)pos++;
        if (pos > m)break;
        if (v[i] > m) {
            rr++;
            v[i] = pos;
            c[pos]++;
        }
    }
    pos = 1;
    for (int i = 0; i < n; i++) {
        while (pos <= m && c[pos] >= r)pos++;
        if (pos > m)break;
        int x = v[i];
        if (c[x] > r) {
            rr++;
            v[i] = pos;
            c[pos]++;
            c[x]--;
        }
    }


    cout << r << " " << rr << endl;
    for (int x: v)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
