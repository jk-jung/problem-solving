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
    int s, e;
    cin >> s >> e;
    vi v(e - s + 1);
    for (int &x: v)cin >> x;

    int r = 0;
    for (int bit = 18; bit >= 0; bit--) {
        int a0 = 0, a1 = 0;
        for (int i = s; i <= e; i++) {
            if (i >> bit & 1)a1++;
            else a0++;
        }

        int b1 = 0, b0 = 0;
        for (int x: v) {
            if (x >> bit & 1) b1++;
            else b0++;
        }

        if (a1 != a0) {
            if (a1 == b0) {
                r ^= (1 << bit);
                for (int &x: v)x ^= (1 << bit);
            }
        } else {
            map<int, int> ck;
            int mask = ((1 << 20) - 1) ^ ((1 << bit) - 1);

            for (int i = s; i <= e; i++) ck[i & mask]++;
            for (int x: v)ck[x & mask]--;
            bool ok = true;
            for(auto [x, y]: ck) {
                if(y != 0)ok = false;
            }
            if(!ok) {
                r ^= (1 << bit);
                for (int &x: v)x ^= (1 << bit);
            }
        }
    }

    cout << (r) << endl;
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
