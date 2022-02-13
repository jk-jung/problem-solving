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

int d[200005];

bool ck(vi &v) {
    int s = 0;
    for (int x: v)s += x;
    d[0] = 1;
    for (int x: v) {
        for (int i = s; i >= 0; i--) {
            if (d[i])d[i + x] = 1;
        }
    }

    return d[s / 2] == 0;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    int g = 0, s = 0;
    for (int x: v)g = gcd(g, x);
    for (int &x: v) x /= g, s += x;

    if (s % 2) {
        cout << 0 << endl;
    } else {
        if (ck(v)) cout << 0 << endl;
        else {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                if (v[i] % 2) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
