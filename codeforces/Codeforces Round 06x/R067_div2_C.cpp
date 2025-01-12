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
    int a, b, n;
    cin >> a >> b >> n;
    int g = gcd(a, b);
    vi r;
    for (int i = 1; i * i <= g; i++)
        if (g % i == 0) {
            r.pb(i);
            r.pb(g / i);
        }
    sort(r.begin(), r.end());
    while (n--) {
        int x, y;
        cin >> x >> y;
        int t = -1;
        for (int z: r)if (x <= z && z <= y)t = z;
        cout << t << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
