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

char x[55][55];
char y[55][55];

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    memset(x, 'C', sizeof(x));
    memset(y, 'D', sizeof(y));
    c--, d--;

    for (int i = 0; i < 25; i += 2) {
        for (int j = 0; j < 50; j += 2) {
            if (a) x[i][j] = 'A', a--;
            else if (b) x[i][j] = 'B', b--;
            else if (d) x[i][j] = 'D', d--;
        }
    }
    for (int i = 1; i < 25; i += 2) {
        for (int j = 0; j < 50; j += 2) {
            if (c) y[i][j] = 'C', c--;
        }
    }
    cout << "50 50\n";
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++)cout << x[i][j];
        cout << endl;
    }
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++)cout << y[i][j];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
