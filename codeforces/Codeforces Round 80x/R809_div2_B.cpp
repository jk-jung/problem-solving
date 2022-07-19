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
    vector<vi> v(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x - 1].pb(i);
    }

    for (int i = 0; i < n; i++) {
        vi &t = v[i];
        int r = 0, y = 0;
        for (int x: t) {
            if (r == 0 || x % 2 != y % 2) r++, y = x;
        }
        cout << r << " ";
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
