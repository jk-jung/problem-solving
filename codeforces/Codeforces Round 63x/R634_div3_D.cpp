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
    string s[9];
    vi ck(9);
    for (auto &x: s)cin >> x;
    for (int ox = 0; ox < 9; ox += 3) {
        vi xx, yy;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i][j + ox] == '1')xx.pb(j + ox), yy.pb(i);
            }
        }

        for (int i = 0; i < 3; i++) {
            s[yy[i]][xx[(i + 1) % 3]] = '1';
        }
    }
    for (auto &x: s)cout << x << '\n';
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
