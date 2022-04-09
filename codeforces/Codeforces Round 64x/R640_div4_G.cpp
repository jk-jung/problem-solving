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
    if (n < 4)cout << -1;
    else if (n == 4) cout << "3 1 4 2";
    else {
        vi used(n + 1);
        vi r;
        for (int i = 1; i <= n; i += 2) r.pb(i);
        if (n % 2) {
            r.pb(r.back() - 3);
            r.pb(r.back() + 2);
            r.pb(r.back() - 4);
        } else {
            r.pb(r.back() - 3);
            r.pb(r.back() + 4);
            r.pb(r.back() - 2);
        }
        if (r.back() == 0)r.pop_back();
        for (int x: r)used[x] = 1;
        for (int i = n; i >= 1; i--) {
            if (i % 2 == 0 && !used[i])r.pb(i);
        }
        for (int x: r)cout << x << " ";
    }

    cout << endl;
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
