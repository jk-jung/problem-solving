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
    string s;
    int x, a, b;
    cin >> s >> x;

    a = s[0] * 10 + s[1] - '0' * 11;
    b = s[3] * 10 + s[4] - '0' * 11;

    int c = a, d = b, r = 0;
    do {
        if (c == d % 10 * 10 + d / 10)r++;

        d += x;
        c += d / 60;
        d %= 60;
        c %= 24;
    } while (a != c || b != d);
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
