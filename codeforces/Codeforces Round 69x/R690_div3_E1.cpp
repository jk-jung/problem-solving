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


ll nCk(ll a, ll b) {
    ll r = 1;
    for (int i = 0; i < b; i++)r *= (a - i);
    for (int i = 0; i < b; i++)r /= (i + 1);
    return r;
}

void solve() {
    int n, m = 3, k = 2;
    cin >> n;
    vi v(n * 2 + 5);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    ll r = 0;
    int cnt = 0;
    for (int i = 0; i <= k; i++)cnt += v[i];
    for (int i = 1; i <= n; i++) {
        cnt -= v[i];
        cnt += v[i + k];

        for (int a = 1; a <= min(m, v[i]); a++) {
            int b = m - a;
            if (cnt < b) continue;
            r = (r + nCk(v[i], a) * nCk(cnt, b));
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
