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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    int x = c - a, y = d - b;
    int r = -1, p = 0;
    for (char k: s) {
        p++;
        if (k == 'N' && y > 0)y--;
        if (k == 'S' && y < 0)y++;
        if (k == 'E' && x > 0)x--;
        if (k == 'W' && x < 0)x++;


        if (x == 0 && y == 0) {
            r = p;
            break;
        }
    }
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
