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
    int h, m, a, b, c, d;
    cin >> h >> m >> a >> b >> c >> d;


    int t = h * 60 + m;
    if (t >= 1200) {
        printf("%.10lf", int((a + d - 1) / d) * c * 0.8);
    } else {
        double v1 = int((a + d - 1) / d) * c;
        double v2 = int((a + (1200 - t) * b + d - 1) / d) * c * 0.8;
        printf("%.10lf", min(v1, v2));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
