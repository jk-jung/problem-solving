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
    int n, m;
    cin >> n >> m;

    if (m % 2) {
        cout << "YES\n";
        for (int i = 1; i <= n; i += 2) {
            cout << i << " " << i + 1 << '\n';
        }
    } else if (m % 4 == 2) {
        cout << "YES\n";
        for (int i = 4; i <= n; i += 4) {
            cout << i - 1 << " " << i << '\n';
        }
        for (int i = 2; i <= n; i += 2) {
            if (i % 4 == 0)continue;
            cout << i << " " << i - 1 << '\n';
        }
    } else {
        cout << "NO\n";
    }
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
