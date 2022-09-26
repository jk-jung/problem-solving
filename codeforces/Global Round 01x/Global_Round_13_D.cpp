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


vi f(int x) {
    vi r;
    while (x)r.pb(x % 2), x /= 2;
    return r;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (a > b) {
        cout << "NO\n";
        return;
    }

    vi x = f(a);
    vi y = f(b);

    int pos = x.size() - 1;
    for (int i = y.size() - 1; i >= 0; i--) {
        if (y[i] == 1) {
            while(pos > i) pos --;
            while (pos >= 0 && x[pos] != 1) pos--;
            if (pos == -1) {
                cout << "NO\n";
                return;
            }
            pos--;
        }
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
