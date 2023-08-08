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
    double r, a, b, x, y;
    cin >> r >> a >> b >> x >> y;
    if ((a - x) * (a - x) + (b - y) * (b - y) >= r * r) {
        cout << a << " " << b << " " << r;
    } else if (a == x && b == y) {
        printf("%.10lf %.10lf %.10lf", a, b + r / 2.0, r / 2.0);
    } else {
        double dx = a - x;
        double dy = b - y;
        double d = sqrt(dx * dx + dy * dy) / 2;
        double t = r / 2.0 + d;
        printf("%.10lf %.10lf %.10lf", x + dx / d * t / 2, y + dy / d * t / 2, t);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
