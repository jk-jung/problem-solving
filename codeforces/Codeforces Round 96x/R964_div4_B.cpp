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

int f(int a, int b, int c, int d) {
    int r = 0;
    if (a > c)r++;
    else if (a < c)r--;
    if (b > d)r++;
    else if (b < d)r--;
    return r > 0;
}

void solve() {
    int a, b, c, d;
    int r = 0;
    cin >> a >> b >> c >> d;
    r += f(a, b, c, d);
    r += f(b, a, c, d);
    r += f(a, b, d, c);
    r += f(b, a, d, c);
    cout << r << endl;
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
