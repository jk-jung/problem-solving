#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vi u = v;
    sort(u.begin(), u.end());

    vector<vector<int>> r;
    for (int i = 0; i < n; i++) {
        if (v[i] == u[i])continue;

        int j = i + 1;
        while (v[j] != u[i])j++;

        int m = j - i + 1;
        for (int k = m - 1; k > 0; k--)v[i + k] = v[i + k - 1];
        v[i] = u[i];

        r.pb({i + 1, j + 1, j - i});
    }

    cout << r.size() << '\n';
    for (auto t: r) {
        for (int x: t) cout << x << " ";
        cout << '\n';
    }

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
