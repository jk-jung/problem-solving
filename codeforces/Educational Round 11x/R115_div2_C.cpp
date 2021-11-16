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
    ll n;
    cin >> n;
    vi v(n);
    ll s = 0;
    map<int, int> ck;
    for (int &x: v)cin >> x, s += x, ck[x]++;

    ll r = 0;
    for (int x: v) {
        ll t = s * n - n * x - s * (n - 2);
        if (t % n == 0) {
            int y = t / n;
            r += ck[y];
            if (x == y)r--;
        }
    }

    cout << r / 2<< endl;
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
