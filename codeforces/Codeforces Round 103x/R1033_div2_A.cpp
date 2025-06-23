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
    vi x(3);
    vi y(3);
    int area = 0;
    for (int i = 0; i < 3; i++)cin >> x[i] >> y[i], area += x[i] * y[i];
    if (x[0] < y[0]) {
        for (int i = 0; i < 3; i++)swap(x[i], y[i]);
    }
    if (x[0] * x[0] != area) {
        cout << "NO\n";
        return;
    }
    if (x[0] == x[1] && x[0] == x[2] && y[0] + y[1] + y[2] == x[0]) {
        cout << "YES\n";
    } else if (x[1] + x[2] == x[0] && y[1] == y[2] && y[0] + y[1] == x[0]) {
        cout << "YES\n";
    } else cout << "NO\n";

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
