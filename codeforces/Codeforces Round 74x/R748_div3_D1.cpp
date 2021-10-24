#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
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
    sort(v.begin(), v.end());

    int r = v.back() - v[0];
    if (r == 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = r; i >= 1; i--)
        if (r % i == 0) {
            int t = (v[0] + 1000000) % i, cnt = 0;
            for (int x: v)if ((x + 1000000) % i == t) cnt++;
            if (cnt == n) {
                cout << i << endl;
                return;
            }
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
