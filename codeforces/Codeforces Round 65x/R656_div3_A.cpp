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
    int x, y, z;
    cin >> x >> y >> z;

    map<int, int> c;
    c[x]++, c[y]++, c[z]++;

    if (c.size() == 1) {
        cout << "YES\n";
        cout << x << " " << x << " " << x << " " << endl;
    } else if (c.size() == 2 && c[c.rbegin()->F] == 2) {
        x = c.begin()->F;
        y = c.rbegin()->F;
        cout << "YES\n";
        cout << x << " " << x <<" " << y << endl;
    } else {
        cout << "NO\n";
    }
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
