#include <string.h>
#include <stdio.h>
#include <math.h>
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

    if (v[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++)cout << i << " ";
        cout << '\n';
        return;
    }
    if (v[n - 1] == 0) {
        for (int i = 1; i <= n; i++)cout << i << " ";
        cout << n + 1 << " ";
        cout << '\n';
        return;
    }
    for (int k = 0; k < n - 1; k++) {
        if (v[k] == 0 && v[k + 1] == 1) {
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
                if (i - 1 == k) cout << n + 1 << " ";
            }
            return;
        }
    }

    cout << "-1\n";
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
