#include <string.h>
#include <stdio.h>
#include <math.h>
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
    for (auto &[x, y]: v)cin >> x >> y;
    string r;

    sort(v.begin(), v.end());
    int a = 0, b = 0;
    for (auto [x, y]: v) {
        if (a > x || b > y) {
            cout << "NO\n";
            return;
        }
        while (a < x)a++, r += 'R';
        while (b < y)b++, r += 'U';
    }
    cout << "YES\n" << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
