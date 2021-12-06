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
    int n, a, b;
    cin >> n >> a >> b;
    int m = n / 2;
    vi r(n);
    vi ck(n + 1);

    ck[a] = ck[b] = 1;
    r[0] = a;
    for (int i = 1; i < m; i++) {
        for (int k = n; k > a; k--)
            if (!ck[k]) {
                ck[k] = 1;
                r[i] = k;
                break;
            }
        if (!r[i]) {
            cout << -1 << endl;
            return;
        }
    }

    r[m] = b;
    for (int i = m + 1; i < n; i++) {
        for (int k = 1; k < b; k++)
            if (!ck[k]) {
                ck[k] = 1;
                r[i] = k;
                break;
            }
        if (!r[i]) {
            cout << -1 << endl;
            return;
        }
    }


    for(int x:r)cout << x << " ";
    cout << endl;
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
