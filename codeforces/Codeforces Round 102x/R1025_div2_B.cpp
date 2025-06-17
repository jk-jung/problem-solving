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


int f(int n, int m) {
    if (n == 1 && m == 1)return 0;
    if (n == 1) return f(n, (m + 1) / 2) + 1;
    if (m == 1) return f((n + 1) / 2, m) + 1;
    return f((n + 1) / 2, m) + 1;
}

int go(int n, int m, int a, int b) {
    return min(
            min(f(a, m), f(n - a + 1, m)),
            min(f(n, b), f(n, m - b + 1))
    ) + 1;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << go(n, m, a, b) << endl;
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
