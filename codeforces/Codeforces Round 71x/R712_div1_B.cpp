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

int a[105][105];
int n;

pi get(int x) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2 == x && a[i][j] == 0)
                return {i, j};
    return {-1, -1};
}

void solve() {

    cin >> n;
    for (int _ = 0, c; _ < n * n; _++) {
        cin >> c;
        if (c != 1) {
            auto[y, x] = get(0);
            if (y != -1) {
                a[y][x] = 1;
                cout << 1 << " " << y + 1 << " " << x + 1 << endl;
            } else {
                auto[y, x] = get(1);
                a[y][x] = (c == 2 ? 3 : 2);
                cout << a[y][x] << " " << y + 1 << " " << x + 1 << endl;
            }
        } else {
            auto[y, x] = get(1);
            if (y != -1) {
                a[y][x] = 2;
                cout << 2 << " " << y + 1 << " " << x + 1 << endl;
            } else {
                auto[y, x] = get(0);
                a[y][x] = 3;
                cout << 3 << " " << y + 1 << " " << x + 1 << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
