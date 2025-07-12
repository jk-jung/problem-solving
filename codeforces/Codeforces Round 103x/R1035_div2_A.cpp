#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b && (a ^ 1) == b) {
        cout << y << endl;
        return;
    }
    if(a > b){
        cout << -1 << endl;
        return;
    }
    int r = 0;
    while (a < b) {
        if (((a & 1) == 0)) {
            r += min(x, y);
        }
        else r += x;
        a++;
    }
    cout << r << endl;
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
