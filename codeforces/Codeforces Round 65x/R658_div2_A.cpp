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
    vi a(1001), b(1001);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int j = 0, x; j < m; j++) {
        cin >> x;
        b[x]++;
    }

    for (int i = 1; i <= 1000; i++)
        if (a[i] && b[i]) {
            cout << "YES\n";
            cout << 1 << " " << i << endl;
            return;
        }
    cout << "NO\n";
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
