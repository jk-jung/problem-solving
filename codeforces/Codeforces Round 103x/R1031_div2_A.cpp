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


int f(int &k, int a, int x) {
    int r = 0;
    if (k >= a) {
        r = (k - a) / x + 1;
        k -= r * x;
    }
    return r;
}

void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    if (x > y)swap(x, y), swap(a, b);
    cout << f(k, a, x) + f(k, b, y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
