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
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    double s = 0, e = 1e10, r = -1;
    for (int cnt = 0; cnt < 300; cnt++) {
        double f = (s + e) / 2;

        double t = m + f;
        for (int i = 0; i < n; i++) {
            double x = a[i];
            double y = b[(i + 1) % n];
            t -= t / x;
            t -= t / y;
        }

        if (t >= m) e = f, r = f;
        else s = f;
    }
    if(r < 0){
        cout << -1;
        return;
    }
    printf("%.10lf", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
