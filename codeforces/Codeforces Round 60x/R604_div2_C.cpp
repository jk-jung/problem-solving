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
    vi v(n);
    map<int, int> ck;
    for (int &x: v)cin >> x, ck[-x]++;

    int a = 0, b = 0, c = 0;
    for (auto [x, y]: ck) {
        if (a == 0)a = y;
        else if (b <= a) b += y;
        else if (a + b + c + y <= n / 2)c += y;
        else break;
    }
    if (c == 0 || c <= a)a = b = c = 0;
    cout << a << " " << b << " " << c << endl;
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
