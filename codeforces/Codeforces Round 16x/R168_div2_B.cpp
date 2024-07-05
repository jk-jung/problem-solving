#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


int a[33][33];
int r[55][55];

void solve() {
    int n = 3;
    for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)cin >> a[i][j];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int k = a[i][j] % 2;
            if (k) {
                r[i][j] ^= 1;
                if (i - 1 >= 0)r[i - 1][j] ^= 1;
                if (i + 1 < 3)r[i + 1][j] ^= 1;
                if (j - 1 >= 0)r[i][j - 1] ^= 1;
                if (j + 1 < 3)r[i][j + 1] ^= 1;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)cout << (r[i][j] ^ 1);
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
