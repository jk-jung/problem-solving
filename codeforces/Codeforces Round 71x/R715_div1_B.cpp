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

ll d[100005];
ll MAX = 1e18 + 10;

void solve() {
    ll n, k;
    int a = 1;
    cin >> n >> k;

    if(d[n] < k) {
        cout << -1 << endl;
        return;
    }
    vi r;
    while (k > 1) {
        int b = a;
        while (a <= n && d[n - a] < k) {
            k -= d[n - a];
            a++;
        }

        for (int i = a; i >= b; i--)r.pb(i);
        a++;
    }
    while (a <= n)r.pb(a++);

    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    d[0] = 1;
    d[1] = 1;
    ll s = 2;
    for (int i = 2; i <= 100000; i++) {
        d[i] = s;
        s += d[i];
        if(s > MAX) s = MAX;
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
