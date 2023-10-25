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
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vi L(m + 1, 1 << 30);

    int r = 0, ss = -1, ee = -1;
    for (int i = 0, p = 0; i < m; i++) {
        while (p < n && a[p] != b[i])p++;
        if (p < n) {
            L[i] = p++;
            r = i + 1;
            ss = i;
            ee = 1 << 30;
        }
    }

    for (int i = m - 1, p = n - 1, pos = m - 2; i >= 0; i--) {
        while (p >= 0 && a[p] != b[i])p--;
        if (p < 0)break;
        p--;
        pos = min(pos, i - 1);
        while (pos >= 0 && L[pos] > p)pos--;
        int cnt = m - i + pos + 1;
        if (cnt > r) {
            r = cnt;
            ss = pos;
            ee = i;
        }
    }

    if (!r)cout << '-';
    else {
        for (int i = 0; i <= ss; i++)cout << b[i];
        for (int i = ee; i < m; i++)cout << b[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
