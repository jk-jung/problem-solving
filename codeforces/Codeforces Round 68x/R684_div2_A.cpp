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
    int n, c0, c1, h;
    string s;
    cin >> n >> c0 >> c1 >> h >> s;

    int n0 = 0, n1 = 0;
    for (char x: s)if (x == '0')n0++; else n1++;

    int r = 0;
    if (c0 > c1) swap(c0, c1), swap(n0, n1);
    if (c1 - c0 > h) {
        r += h * n1;
        n0 += n1;
        n1 = 0;
    }
    cout << r + n1 * c1 + n0 * c0 << endl;
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
