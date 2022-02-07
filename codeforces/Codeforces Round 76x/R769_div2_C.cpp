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

int calc(int a, int b) {
    int r = 0;
    for (int i = 30; i >=0; i--) {
        if ((a >> i & 1) && !(b >> i & 1)) {
            int mask = (1 << (i + 1)) - 1;
            r = (a & mask) - (b & mask);
            break;
        }
    }
    return r;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int r = b - a;
    for (int i = a; i <= b; i++)
        r = min(r, i - a + 1 + calc(i, b));
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
