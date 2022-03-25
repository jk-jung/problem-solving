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
    int n, a[4];
    cin >> n >> a[0] >> a[1] >> a[2] >> a[3];

    for (int i = 0; i < 4; i++) {
        int s = (i + 3) % 4;
        int e = (i + 1) % 4;
        int k = (i + 2)  % 4;

        int need = (a[s] == n) + (a[e] == n);
        if (a[i] < need) {
            cout << "NO\n";
            return;
        }

        need = 0;
        if (a[s] == n) need += 2;
        else if (a[s] == n - 1) need++;
        if (a[e] == n) need += 2;
        else if (a[e] == n - 1) need++;

        if (a[i] + a[k] < need) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
