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

int a[25];
int b[25];
int c[3][8] = {
        {1,  3,  5,  7,  9,  11, 24, 22},
        {13, 14, 5,  6,  17, 18, 21, 22},
        {2,  1,  13, 15, 11, 12, 20, 18},
};

bool check(int k, int cnt) {
    memcpy(b, a, sizeof(b));

    for (int i = 0; i < 8; i++) {
        b[c[k][i]] = a[c[k][(i + cnt) % 8]];
    }

    for (int i = 1; i <= 24; i += 4) {
        int x = b[i];
        for (int j = 1; j < 4; j++) {
            if (b[i + j] != x)return false;
        }
    }
    return true;
}

void solve() {
    for (int i = 1; i <= 24; i++)cin >> a[i];

    for (int i = 0; i < 3; i++) {
        if (check(i, 2) || check(i, 6)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
