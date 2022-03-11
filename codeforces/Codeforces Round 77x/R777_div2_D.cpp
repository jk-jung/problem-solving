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

bool can(int factor_count, map<int, int> &ck, int cnt, int x) {
    if (factor_count == 1) return false;
    if (cnt == 2) return false;
    if (!ck.count(x)) return true;

    if (ck.size() == 1 && ck.begin()->S == 2 && cnt == 3) return false;
    return true;
}

void solve() {
    int x, d, c = 0;
    cin >> x >> d;
    while (x % d == 0) {
        c++;
        x /= d;
    }
    if (c == 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            cout << "YES\n";
            return;
        }
    }

    // x is prime
    int ff = 0;
    map<int, int> ck;
    for (int i = 2; i * i <= d; i++) {
        while (d % i == 0) {
            ck[i]++;
            d /= i;
            ff++;
        }
    }
    if (d > 1)ck[d]++, ff++;

    if (can(ff, ck, c, x)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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
