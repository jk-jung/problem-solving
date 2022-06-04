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


int check(map<int, int> &ck) {
    vi a(1), b(1);
    bool flag = true;
    for (auto [x, y]: ck) {
        if (a.back() < x && b.back() < x) {
            if (y >= 2) {
                a.pb(x);
                b.pb(x);
            } else if (flag) {
                a.pb(x);
                b.pb(x);
                flag = false;
            } else {
                if (a.size() <= b.size())a.pb(x);
                else b.pb(x);
            }
        }

    }
    return min(a.size(), b.size()) - 1;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    map<int, int> ck;
    for (int &x: v)cin >> x, ck[x]++;

    int r = check(ck);
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
