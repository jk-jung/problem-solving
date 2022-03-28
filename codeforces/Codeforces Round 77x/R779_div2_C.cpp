#include <string.h>
#include <stdio.h>
#include <math.h>
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
    vi v(n), p(n, -1);
    for (int &x: v)cin >> x;

    int one = 0;
    for (int x: v) if (x == 1)one++;

    if (one != 1) {
        cout << "NO\n";
        return;
    }

    int flag = 0, last = 0;
    for (int i = 0; i < n * 2; i++) {
        int k = i % n;
        int x = v[k];
        if (x == 1 && flag)break;
        if (x == 1) flag = 1;
        if (!flag)continue;

        if (x == 1) p[k] = -1;
        else {
            if (x >= last + 2) {
                cout << "NO\n";
                return;
            }
        }
        last = x;
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
