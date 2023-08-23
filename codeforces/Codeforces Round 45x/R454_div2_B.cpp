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

char a[105][105];

void solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    int y, x;
    cin >> y >> x;
    y--;
    x--;
    y = y % 3;
    x = x % 3;

    bool ok = false;
    for (int i = y * 3; i < y * 3 + 3; i++) {
        for (int j = x * 3; j < x * 3 + 3; j++) {
            if (a[i][j] == '.') {
                ok = true;
                a[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i && i % 3 == 0)cout << endl;
        for (int j = 0; j < 9; j++) {
            if (j && j % 3 == 0)cout << " ";
            if (!ok) cout << (a[i][j] == '.' ? '!' : a[i][j]);
            else cout << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
