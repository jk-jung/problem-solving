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

int a[10][10];

void solve() {
    for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)cin >> a[i][j];

    for (int k = 1; k <= 100000; k++) {
        int tot = k + a[0][1] + a[0][2];
        int v1 = tot - a[1][0] - a[1][2];
        int v2 = tot - a[2][0] - a[2][1];

        if (v1 > 0 && v2 > 0 && k + v1 + v2 == tot) {
            a[0][0] = k;
            a[1][1] = v1;
            a[2][2] = v2;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
