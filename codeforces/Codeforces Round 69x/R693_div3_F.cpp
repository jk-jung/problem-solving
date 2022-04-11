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
    int n, m;
    cin >> n >> m;
    map<int, int> ck;
    while (m--) {
        int y, x;
        cin >> y >> x;
        y--, x--;
        ck[x] |= 1 << y;
    }
    ck[n] = 3;
    int pos = -1, last = 3;
    for (auto[x, st]: ck) {
        int len0 = x - pos + 1;
        int len1 = x - pos + 1;

        if (last >> 0 & 1) len0--;
        if (last >> 1 & 1) len1--;
        if (st >> 0 & 1) len0--;
        if (st >> 1 & 1) len1--;

        if (last == 1) {
            if (st == 3) {
                cout << "NO\n";
                return;
            } else if (st == 2) {
                if (len1 % 2) {
                    cout << "NO\n";
                    return;
                }
                if (len0 % 2 == 0)st = 3;
            } else {
                if (len0 % 2) {
                    cout << "NO\n";
                    return;
                }
                if (len1 % 2 == 0)st = 3;
            }
        } else if (last == 2) {
            if (st == 3) {
                cout << "NO\n";
                return;
            } else if (st == 1) {
                if (len0 % 2) {
                    cout << "NO\n";
                    return;
                }
                if (len1 % 2 == 0)st = 3;
            }else{
                if (len1 % 2) {
                    cout << "NO\n";
                    return;
                }
                if (len0 % 2 == 0)st = 3;
            }
        }
        pos = x;
        last = st;
    }
    cout <<"YES\n";
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
