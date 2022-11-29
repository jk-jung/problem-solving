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
    vi v(n);
    for (int &x: v)cin >> x;
    if (n % 2 == 0) {
        pi a(1 << 30, 0), b(1 << 30, 0);
        for (int i = 0; i < n; i ++) {
            if (i % 2 == 0) {
                if (a.F > v[i])a = {v[i], i};
            }
            if (i % 2 == 1) {
                if (b.F > v[i])b = {v[i], i};
            }
        }
        cout << (a > b ? "Mike" : "Joe") << endl;
    } else {
        cout << "Mike" << endl;
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
