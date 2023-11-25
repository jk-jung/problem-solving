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
    int n;
    cin >> n;
    vector<pi> v(n);
    int a = 0, b = 0;
    int xx = 0, xi = 0, yy = 0, yi = 0;

    int c = 0;
    for (auto &[x, y]: v) {
        ++c;
        cin >> x >> y, a += x, b += y;
        int aa = -x - x + y + y;
        int bb = -y - y + x + x;
        if (xx < aa) {
            xx = aa;
            xi = c;
        }
        if (yy < bb) {
            yy = bb;
            yi = c;
        }
    }
    int rr = 0;
    int r = ab(a - b);
    if(r < ab(a - b + xx)){
        r = ab(a - b + xx);
        rr = xi;
    }
    if(r < ab(b - a + yy)) {
        r = ab(b - a + yy);
        rr = yi;
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
