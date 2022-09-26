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
    string a, b;
    cin >> n >> a >> b;
    int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0') a1++;
        if (a[i] == '0' && b[i] == '1') a0++;
        if (a[i] == '1' && b[i] == '1') b1++;
        if (a[i] == '0' && b[i] == '0') b0++;
    }
    int r = 1 << 30;
    if (a0 == a1) r = a0 + a1;
    if (b1 == b0 + 1) r = min(r, b1 + b0);
    if (r == (1 << 30))r = -1;
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
