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

bool odd(pi &x) { return (x.F + x.S) % 2; }

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    for (auto &x: v)cin >> x.F;
    for (auto &x: v)cin >> x.S;
    sort(v.begin(), v.end());


    pi x = {1, 1};
    ll r = 0;
    for (auto y: v) {
        ll y_dif = y.F - x.F;
        ll x_dif = y.S - x.S;

        if (odd(x)) {
            r += (y_dif - x_dif + 1) / 2;
        } else {
            if(x_dif == y_dif) r += x_dif;
            else {
                y_dif --;
                r += (y_dif - x_dif + 1) / 2;
            }
        }
        x = y;
    }

    cout << r << endl;
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
