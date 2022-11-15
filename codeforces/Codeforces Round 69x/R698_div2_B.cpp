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

int n, k;
int d[100];

bool go(int x) {
    if (x >= 11 * k)return true;
    if(x == 0)return true;

    int &r = d[x];
    if (r != -1)return r;
    r = 0;
    for (int i = k; i <= x; i++) {
        if (to_string(i).find(to_string(k)) != -1) {
            if (go(x - i)) {
                r = 1;
                break;
            }
        }
    }
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> n >> k;
    while (n--) {
        int x;
        cin >> x;
        if (x >= k * 11) cout << "YES\n";
        else cout << (go(x) ? "YES" : "NO") << endl;
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
