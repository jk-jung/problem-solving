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

int a[1005][1005];
map<int, int> t;

int get(int x) {
    if (!t.count(x))return -1;
    if (--t[x] == 0)t.erase(x);
    return x;
}

int f() {
    return get(t.begin()->first);
}

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    t.clear();

    for (int i = 0, x; i < n * n; i++) {
        cin >> x;
        t[x]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) a[i][j] = f();
            else a[i][j] = get(a[i][j - 1] + d);
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if(a[i][j] == -1 || (i && a[i][j] != a[i - 1][j] + c)) {
                cout << "NO\n";
                return;
            };
        }
    }
    cout << "YES\n";
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
