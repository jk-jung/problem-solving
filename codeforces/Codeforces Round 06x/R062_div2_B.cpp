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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int n, k;
    cin >> n >> k;
    k = 100 - k;
    vi v(n);
    for (int &x: v)cin >> x;
    double s = 0, e = 1000;
    for (int _ = 0; _ < 1000; _++) {
        double m = (s + e) / 2;
        double up = 0, down = 0;
        for (int x: v) {
            if (x < m)down += m - x;
            else up += x - m;
        }
        up = up * k / 100;
        if(down <= up) s = m;
        else e = m;
    }
    cout << setprecision(10) << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
