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

void solve() {
    int n;
    cin >> n;
    string a[2];
    cin >> a[0] >> a[1];

    bool ok[2] = {true, true};

    for (int i = 0; i < n; i++) {
        if (a[0][i] == 'B' && a[1][i] == 'B') {
            if (ok[0] && ok[1]);
            else if (ok[0] || ok[1]) swap(ok[0], ok[1]);
            else {
                cout << "NO\n";
                return;
            }
        } else if (a[0][i] == 'B') {
            if (ok[0]) ok[0] = true, ok[1] = false;
            else {
                cout << "NO\n";
                return;
            }
        } else {
            if (ok[1]) ok[1] = true, ok[0] = false;
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << ((ok[0] || ok[1]) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
