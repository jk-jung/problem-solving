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
    vi a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    map<int, int> ck;
    for (int i = 0; i < n; i++) {
        if (ck.count(a[i]))ck[a[i]] = min(ck[a[i]], b[i]);
        else ck[a[i]] = b[i];
    }
    for (int i = 1; i <= 500; i++) {
        for (int j = 0; j < i; j++) {
            int t = 2 * (i - j - 1);
            if (ck.count(j) && ck[j] <= t) {
                cout << i - 2 << endl;
                return;
            }
        }
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
