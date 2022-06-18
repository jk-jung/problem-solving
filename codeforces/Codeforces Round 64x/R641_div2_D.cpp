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

int n, k;

void solve() {
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    bool ok = false, can = false;
    for (int x: v) ok |= x == k;

    if(n == 1)can = true;
    for (int i = 0; i < n - 1; i++) {
        int c = 0;
        if (v[i] >= k) c++;
        if (v[i + 1] >= k)c++;
        if(c >= 2) can = true;
    }
    for (int i = 0; i < n - 2; i++) {
        int c = 0;
        if (v[i] >= k) c++;
        if (v[i + 1] >= k)c++;
        if (v[i + 2] >= k) c++;
        if(c >= 2) can = true;
    }
    cout << (ok && can ? "yes\n" : "no\n");
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
