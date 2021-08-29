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

int n;

int calc(int x, vi &v, int mm) {
    int r = 0,c = 0;
    int s = 0, e = n - 1;
    for (int i = 0; i < n; i++) {
        if(v[i] == x) {
            r += ab(i - c * 2);
            c ++;
        }

    }
    return r;
}

void solve() {

    cin >> n;
    int a = 0, b = 0;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= 2;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] % 2)a++;
        else b++;
    }
    if (ab(a - b) >= 2) {
        cout << -1 << '\n';
        return;
    }

    int r = 0;
    if (ab(a - b) == 1) {
        r = calc(a > b ? 1 : 0, v, a > b ? a : b);
    } else {
        r = min(calc(0, v, a), calc(1, v, a));
    }
    cout << r << '\n';
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
