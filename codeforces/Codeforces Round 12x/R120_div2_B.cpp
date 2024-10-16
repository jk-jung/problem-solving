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

void solve() {
    double a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    if (c < z)swap(c, z);
    double dis = sqrt(pow(a - x, 2) + pow(b - y, 2));
    if (dis < c)swap(dis, c);
    printf("%.10f", max(0.0, dis - c - z) / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
