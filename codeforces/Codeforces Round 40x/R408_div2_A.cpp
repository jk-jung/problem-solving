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
    int n, m, k;
    cin >> n >> m >> k;
    vi v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    for (int i = 1; i < n; i++) {
        int a = m - i;
        int b = m + i;
        if (a >= 1 && v[a] && v[a] <= k) {
            cout << i * 10 << endl;
            return;
        }
        if (b <= n && v[b] && v[b] <= k) {
            cout << i * 10 << endl;
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
