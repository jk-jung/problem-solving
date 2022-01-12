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

    for (int &x: v)cin >> x;

    int r = 1 << 30;
    for (int a = 0; a <= 2; a++) {
        for (int b = 0; b <= 2; b++) {
            int t = 0;
            for (int x: v) {
                int tt = 1 << 30;
                for (int aa = 0; aa <= a; aa++) {
                    for (int bb = 0; bb <= b; bb++) {
                        int rest = x - aa - bb - bb;
                        if(rest < 0 || rest % 3) continue;
                        tt = min(tt, rest / 3);
                    }
                }
                t = max(t, tt);
            }
            r = min(r, t + a + b);
        }
    }
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
