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

    set<int> aa, bb;
    for (int i = 0; i < n; i++) {
        if (b[i]) aa.insert(a[i] - b[i]);
        else bb.insert(a[i] - b[i]);
    }
    bool r = false;
    if (aa.empty()) r = true;
    else if (aa.size() == 1 && *aa.begin() >= 0) {
        if (bb.empty()) r = true;
        else if (*bb.rbegin() <= *aa.begin()) r = true;
    }
    cout << (r ? "YES\n" : "NO\n");
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
