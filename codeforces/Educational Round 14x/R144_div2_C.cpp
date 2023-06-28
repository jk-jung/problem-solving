#include <cstring>
#include <cstdio>
#include <cmath>
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
    int a, b;
    cin >> a >> b;
    int c = 0, d = a;
    while (d <= b) {
        c++;
        d *= 2;
    }
    int k = 1 << (c - 1);
    int r = b / k - a + 1;
    if (k >= 2) {
        k = k / 2 * 3;
        int t = b / k;
        if(t >= a) {
            r += (t - a + 1) * (c - 1);
        }
    }

    cout << c << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
