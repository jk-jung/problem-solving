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
    int n, k, q;
    cin >> n >> k >> q;
    vi a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++)cin >> a[i];
    for (int i = 1; i <= k; i++)cin >> b[i];

    while (q--) {
        int d;
        cin >> d;
        if(d == 0){
            cout << 0 << " ";
            continue;
        }
        int idx = lower_bound(a.begin(), a.end(), d) - a.begin();
        idx--;
        ll aa = a[idx + 1] - a[idx];
        ll bb = b[idx + 1] - b[idx];
        cout << b[idx] + (d - a[idx]) * bb / aa << " ";
    }
    cout << endl;
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
