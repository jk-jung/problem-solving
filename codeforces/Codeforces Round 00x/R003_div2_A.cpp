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


void solve() {
    string a, b;
    cin >> a >> b;
    int x = b[0] - a[0];
    int y = b[1] - a[1];

    vector<string> v;
    while (x != 0 || y != 0) {
        string t;
        if (x < 0)t += 'L', x++;
        else if (x > 0)t += 'R', x--;

        if (y < 0)t += 'D', y++;
        else if (y > 0)t += 'U', y--;

        v.pb(t);
    }
    cout << v.size() << endl;
    for (const string &s: v) {
        cout << s << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
