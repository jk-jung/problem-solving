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
    string s;
    cin >> n >> m >> s;
    int x = 0, y = 0;
    int mx = 0, Mx = 0;
    int my = 0, My = 0;
    int rx = 1, ry = 1;
    for (char d: s) {
        if (d == 'L') x--;
        if (d == 'R') x++;
        if (d == 'U') y--;
        if (d == 'D') y++;

        mx = min(mx, x);
        Mx = max(Mx, x);
        my = min(my, y);
        My = max(My, y);

        if (Mx - mx >= m)break;
        if (My - my >= n)break;

        rx = 1 - mx, ry = 1- my;
    }

    cout << ry << " " << rx << endl;
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
