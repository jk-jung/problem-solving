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
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    int pos = n - 1, last = -1;
    map<int, int> ck;
    for (int i = n - 1; i >= 0; i--) {
        int x = a[pos], y = b[i];
        if (x == y) {
            pos--;
            last = y;
        } else if (last == y) {
            ck[y]++;
            last = y;
        } else if (ck.count(x)) {
            if (--ck[x] == 0)
                ck.erase(x);
            pos--;
            i++;
        } else {
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
