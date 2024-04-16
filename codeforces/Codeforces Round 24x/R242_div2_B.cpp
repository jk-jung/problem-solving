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

int x[1005];
int y[1005];
int k[1005];

void solve() {
    int n, s;
    cin >> n >> s;

    s = 1000000 - s;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> k[i];
    }
    double a = 0, b = 1e9, r = -1;
    for (int _ = 0; _ < 300; _++) {
        double m = (a + b) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (m * m >= x[i] * x[i] + y[i] * y[i]) {
                cnt += k[i];
            }
        }
        if (cnt >= s) {
            r = m;
            b = m;
        } else {
            a = m;
        }
    }
    if (r == -1) {
        cout << -1 << endl;
        return;
    } else
        printf("%.7f\n", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
