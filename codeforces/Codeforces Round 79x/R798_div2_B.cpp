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
    vi v(n), used(n + 1);
    for (int &x: v)cin >> x;
    if (n == 1) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n - 2; i++) {
            for (int k = 1; k <= n; k++)
                if (v[i] != k && used[k] == 0) {
                    cout << k << " ";
                    used[k] = 1;
                    break;
                }
        }
        vi t;
        for (int i = 1; i <= n; i++)if (used[i] == 0 )t.pb(i);
        if (t[0] == v[n - 2] || t[1] == v[n - 1])swap(t[0], t[1]);
        cout << t[0] << " " << t[1] << endl;
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
