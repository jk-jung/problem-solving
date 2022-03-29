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
    int a, b, c;
    cin >> a >> b >> c;
    b--;

    if (c == 0) {
        string r = "1";
        while (b--)r += '1';
        while (a--)r += '0';
        cout << "Yes\n" << r << '\n' << r << '\n';
        return;
    }
    if (a == 0 || b == 0) {
        cout << "No\n";
        return;
    }
    if (a + b - 1 < c) {
        cout << "No\n";
        return;
    }

    a--;
    b--;
    string x, y;

    for (int i = 0; i <= c; i++) {
        if (i == 0) {
            x += '0';
            y += '1';
        } else if (i == c) {
            x += '1';
            y += '0';
        } else {
            if (a > 0) {
                a--;
                x += '0';
                y += '0';
            } else {
                b--;
                x += '1';
                y += '1';
            }
        }
    }
    while (a > 0) {
        x += '0';
        y += '0';
        a--;
    }
    while (b > 0) {
        x += '1';
        y += '1';
        b--;
    }
    x += '1';
    y += '1';
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    cout << "Yes\n" << x << '\n' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
