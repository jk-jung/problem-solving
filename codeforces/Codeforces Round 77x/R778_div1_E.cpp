#include <string.h>
#include <stdio.h>
#include <math.h>
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

const int N = 316;

int ck[32600005], CK, base = 1500000;
int cnt[32600005];

int calc(vi &v, int t) {
    CK++;
    int r = 0;
    int m = 1 << 30;
    for (int i = 0; i < v.size(); i++) {
        int x = v[i] - t * i;
        m = min(m, x);
    }
    for (int i = 0; i < v.size(); i++) {
        int x = v[i] - t * i - m;
        if (ck[x] != CK) cnt[x] = 0;
        ck[x] = CK;
        r = max(r, ++cnt[x]);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    for (int i = 0; i < n; i++) {
        CK++;
        for (int k = 1; k <= N; k++) {
            int j = i - k;
            if (j < 0)break;

            int dif = v[i] - v[j];
            if (ab(dif) % k) continue;

            int x = dif / k + base;
            if (ck[x] != CK) cnt[x] = 1;
            ck[x] = CK;

            r = max(r, ++cnt[x]);
        }
    }

    for (int i = -N; i <= N; i++)r = max(r, calc(v, i));
    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
