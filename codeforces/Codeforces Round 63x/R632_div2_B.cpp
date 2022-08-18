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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: a) cin >> x;
    for (int &x: b) cin >> x;


    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i] && y == 0) {
            cout << "NO\n";
            return;
        }
        if (a[i] < b[i] && x == 0) {
            cout << "NO\n";
            return;
        }
        if (a[i] > 0)x = 1;
        if (a[i] < 0) y = 1;

    }
    cout << "YES\n";
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
