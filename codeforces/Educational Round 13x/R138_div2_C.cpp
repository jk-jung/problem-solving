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


bool can(vi v, int x) {

    while (x) {
        bool ok = false;
        sort(v.begin(), v.end());
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] <= x) {
                v[i] = 1 << 30;
                ok = true;
                break;
            }
        }
        v[0] = 1 << 30;
        if (!ok)return false;
        x--;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    for (int i = 1; can(v, i); i++)r = i;
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
