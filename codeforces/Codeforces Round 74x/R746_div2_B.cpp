
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
    int n, x;
    cin >> n >> x;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    b = a;
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        bool can = i >= x || n - 1 - i >= x;
        if(can || a[i] == b[i]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
