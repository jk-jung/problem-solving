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
    int n;
    cin >> n;
    vi v(n), a(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    for (int k = n; k >= 1; k--) {
        bool ok = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i])continue;
            int x = v[i];
            while (x && x != k) x /= 2;
            if(x == k) {
                a[i] = 1;
                ok = true;
                break;
            }
        }
        if(!ok) {
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
