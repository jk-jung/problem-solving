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
    int a, b, c, t, ok = 0;
    cin >> a >> b >> c;
    t = b + b - a;
    if (t > 0 && (t - c) % c == 0) ok = 1;
    t = b + b - c;
    if (t > 0 && (t - a) % a == 0)ok = 1;
    t = a + (c - a) / 2;
    if (t > 0 && (t - b) % b == 0 && a - t == t - c)ok = 1;
    cout << (ok ? "YES" : "NO") << endl;
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
