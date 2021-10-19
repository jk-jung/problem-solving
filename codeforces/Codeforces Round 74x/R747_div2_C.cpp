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
    char a, b;
    cin >> n >> b;
    vi v;
    vi ck(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == b)continue;
        v.pb(i);
        ck[i] = 1;
    }

    vi r;
    if (ck[n]) {
        for (int i = n; i >= 2; i--) {
            if (!ck[i]) {
                bool ok = true;
                for (int x: v)if (x % i == 0)ok = false;
                if (ok) {
                    cout << "1\n" << i << '\n';
                    return;
                }
            }
        }
        cout << "2\n" << n << " " << n - 1 << '\n';
    } else if (v.size()) {
        cout << "1\n" << n << '\n';
    } else cout << "0\n";
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
