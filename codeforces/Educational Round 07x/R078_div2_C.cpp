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
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    reverse(a.begin(), a.end());
    map<int, int> ck;
    int diff = 0;
    for (int x: a)diff += x == 1 ? -1 : 1;
    ck[diff] = 0;
    for (int i = 0; i < n; i++) {
        diff -= a[i] == 1 ? -1 : 1;
        if (!ck.count(diff))ck[diff] = i + 1;
    }
    int r = n * 2;
    int d2 = 0;
    for (int x: b)d2 += x == 1 ? 1 : -1;
    if(ck.count(d2)) r = min(r, ck[d2]);
    for (int i = 0; i < n; i++) {
        d2 -= b[i] == 1 ? 1 : -1;
        if (ck.count(d2))r = min(r, ck[d2] + i + 1);
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
