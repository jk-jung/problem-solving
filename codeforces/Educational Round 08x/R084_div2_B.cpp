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
    vi used(n + 1);

    int non = 0;
    for (int i = 0; i < n; i++) {
        int m, t = 0;
        cin >> m;
        for (int k = 0, x; k < m; k++) {
            cin >> x;
            if (t == 0 && used[x] == 0) {
                used[x] = 1;
                t = x;
            }
        }
        if (t == 0)non = i + 1;
    }
    if (non) {
        cout << "IMPROVE\n";
        for (int i = 1; i <= n; i++)
            if (!used[i]) {
                cout << non << " " << i << endl;
                break;
            }
    } else {
        cout << "OPTIMAL\n";
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
