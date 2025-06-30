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


int n, va, vb, ux, uy;

double f(int x) {
    return sqrt(double(ux - x) * (ux - x) + double(uy) * uy) / double(vb);
}

void solve() {
    cin >> n >> va >> vb;
    vi v(n);
    for (auto &x: v)cin >> x;
    cin >> ux >> uy;

    int r = 0;
    double t = 1e20, t2 = 1e20;

    for (int i = 1; i < n; i++) {
        double k = (v[i] - v[0]) / double(va);
        double k2 = f(v[i]);
        if (k + k2 <= t) {
            if (k + k2 == t) {
                if (k2 < t2) {
                    t2 = k2;
                    r = i;
                }
            } else {
                t = k + k2;
                t2 = k2;
                r = i;
            }
        }
    }
    cout << r + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}