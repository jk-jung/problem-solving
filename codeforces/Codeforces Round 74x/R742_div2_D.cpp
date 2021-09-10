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

int n, s;

ll t11(int x) {
    ll r = 0, b = 1;
    while (x) {
        r += x % 10 * b;
        x /= 10;
        b *= 11;
    }
    return r;
}

ll ss(vi &v) {
    ll r = 0;
    for (int i = 0; i < s; i++)r += t11(v[i]);
    return r;
}


vi make(int x) {
    int m = n - x, base = 1, need = s - x;
    vi r(s, 1), v;

    while (m) {
        int k = m % 10;
        for (int i = 1; i <= k; i++) v.pb(base);
        m /= 10;
        base *= 10;
    }

    while (v.size() < need) {
        bool flag = true;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= 10) {
                int k = v[i] / 10;
                v[i] = k;
                for (int j = 0; j < 9; j++)v.pb(k);
                flag = false;
                break;
            }
        }

        if (flag) break;
    }
    if (v.size() < need) return {};

    for (int i = 0; i < need; i++)r[i] = 0;
    for (int i = 0; i < v.size(); i++)r[i % need] += v[i];
    return r;
}

void solve() {
    cin >> n >> s;
    vi r(s, 1);
    r[0] = n - s + 1;

    for (int i = 0; i < s; i++) {
        vi t = make(i);
        if (t.size() != 0 && ss(r) < ss(t)) r = t;
    }
    for (int i = 0; i < s; i++)cout << r[i] << " ";
    cout << '\n';
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
