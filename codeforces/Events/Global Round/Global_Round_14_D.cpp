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
    int n, L, R;
    cin >> n >> L >> R;

    int s1 = 0, s2 = 0;
    vi v1(L), v2(R);
    map<int, int> c1, c2;
    for (int &x: v1)cin >> x;
    for (int &x: v2)cin >> x;

    if (L < R) swap(v1, v2);

    for (int x: v1)c1[x]++, s1++;
    for (int x: v2) {
        if (c1.count(x)) {
            s1--;
            if (--c1[x] == 0)c1.erase(x);
        } else c2[x]++, s2++;
    }

    int r = s2;
    int need = (s1 - s2) / 2;
    for (auto[k, x]: c1) {
        while (x >= 2 && need) {
            x -= 2;
            r++;
            need--;
            s1 -= 2;
        }
    }

    cout << r + need * 2 << endl;
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
