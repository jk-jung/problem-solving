#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int a[2][100005];

void solve() {
    int n;
    cin >> n;
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[j][i];
            a[j][i] += a[j][i - 1];
        }
    }

    int r = 2100000000;
    for (int i = 1; i <= n; i++) {
        int t = max(a[1][i - 1], a[0][n] - a[0][i]);
        r = min(r, t);
    }

    cout << r << endl;
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
