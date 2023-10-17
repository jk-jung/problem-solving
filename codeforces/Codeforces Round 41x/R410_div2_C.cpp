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
    // 3 7
    // -4 10
    // 2 5
    // -3 7
    int n;
    cin >> n;
    vi v(n);
    int g = 0;
    for (int &x: v)cin >> x, g = gcd(g, x);
    if (g != 1) {
        cout <<"YES\n";
        cout << 0 << endl;
    } else {
        int r = 0, c = 0;
        for (int x: v) {
            if (x % 2) c++;
            else {
                r += (c / 2) + 2 * (c % 2);
                c = 0;
            }
        }
        r += (c / 2) + 2 * (c % 2);
        cout <<"YES\n";
        cout << r << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
