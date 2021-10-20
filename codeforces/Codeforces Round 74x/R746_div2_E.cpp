#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
int v[1000005];

bool can(int x) {
    int xo = 0;
    vi a(20);
    for (int i = 0; i < n; i++) {
        xo ^= v[i];
        for (int k = 0; k < 20; k++) if (v[i] >> k & 1)a[k]++;
        if (i + 1 >= x) {
            int t = 0;
            for (int k = 0; k < 20; k++)if (a[k] == x) t |= 1 << k;

            if (t > xo) return true;
            xo ^= v[i - x + 1];
            for (int k = 0; k < 20; k++) if (v[i - x + 1] >> k & 1)a[k]--;
        }
    }
    return false;
}

int d[2][1<<20];
ll ck[2][1<<20], CK;

int calc(int x) {
    CK ++;
    int r = 0, cnt = 0, st = 0;

    ck[1][0] = CK;
    d[1][0] = -1;
    for (int i = 0; i < n; i++) {
        int t = i % 2;
        st ^= v[i];
        st >>= x + 1;
        st <<= x + 1;

        if (v[i] >> x & 1) {
            cnt++;
            if (cnt >= 2 && ck[t][st] == CK)
                r = max(r, i - d[t][st]);
        } else {
            CK++;
            cnt = 0;
        }

        if(ck[t][st] != CK) {
            ck[t][st] = CK;
            d[t][st] = i;
        }
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)cin >> v[i];

    int r = 0;
    for (int i = 0; i < 20; i++) {
        r = max(r, calc(i));
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
