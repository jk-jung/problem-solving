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

int sign(int x) {
    return x < 0 ? -1 : 1;
}

int ck(int x, int y, int op) {
    if (sign(x) * sign(y) != op) return -x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vi v(n), r(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    int s = 0;
    if (n % 2) {
        int a = ab(v[0]);
        int b = ab(v[1]);
        int c = ab(v[2]);

        int g = gcd(a + b, c);
        int aa = c / g;
        int cc = (a + b) / g;

        r[0] = ck(aa, v[0], 1);
        r[1] = ck(aa, v[1], 1);
        r[2] = ck(cc, v[2], -1);
        s += 3;
    }

    for (; s < n; s += 2) {
        int g = gcd(v[s], v[s + 1]);
        r[s] = ck(v[s + 1] / g, v[s], +1);
        r[s + 1] = ck(v[s] / g, v[s + 1], -1);
    }
    for (int x: r)cout << x << " ";
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
