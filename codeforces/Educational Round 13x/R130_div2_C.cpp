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
    string a, b;
    cin >> n >> a >> b;

    int b0 = 0, b1 = 0;
    string c, d;
    for (char x: a) {
        if (x == 'b') b0++;
    }
    for (char x: b) {
        if (x == 'b') b1++;
    }

    if (b0 != b1) {
        cout << "NO\n" << endl;
    } else {
        for (int i = 0, j = 0; i < n; i++) {
            if (a[i] == 'b') continue;
            while (b[j] == 'b')j++;
            if (a[i] != b[j] || (a[i] == 'a' && i > j) || (a[i] == 'c' && i < j)) {
                cout << "NO\n";
                return;
            }
            j++;
        }
        cout << "YES" << endl;
    }
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
