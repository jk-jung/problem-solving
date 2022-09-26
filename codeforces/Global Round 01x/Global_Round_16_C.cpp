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

int cost(char a, char b) {
    if (a > b) swap(a, b);
    if (a == '0' && b == '1') return 2;
    if (a == '1' && b == '1') return 0;
    return 1;
}

void solve() {
    int n, r = 0;
    string a, b;
    cin >> n >> a >> b;
    vi d(n), v(n);

    for (int i = 0; i < n; i++)v[i] = cost(a[i], b[i]);

    for (int i = 1; i < n; i++) {
        if (v[i - 1] + v[i] == 1) v[i] = 2, v[i-1] = 0;
    }
    for (int i = 0; i < n; i++)r += v[i];
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
