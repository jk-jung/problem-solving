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
    int n, m;
    cin >> n >> m;
    if (n - 1 <= m && m <= 2 * (n + 1)) {
        if (m == n - 1) {
            while (n > 0 || m > 0) {
                if (n-- > 0)cout << 0;
                if (m-- > 0)cout << 1;
            }
        } else if (m == n) {
            for (int i = 0; i < n; i++) {
                cout << "10";
            }
        } else {
            while (m != n) {
                cout << "110";
                m -= 2;
                n--;
                if(n == 0)break;
            }
            while (n > 0 || m > 0) {
                if (m-- > 0)cout << 1;
                if (n-- > 0)cout << 0;
            }
        }
    } else {
        cout << -1;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
