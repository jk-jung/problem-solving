#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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

int n;
int v[3000];
vi r;

int pos(int x) {
    for (int i = 1; i <= n; i++)if (v[i] == x) return i;
}

void move(int x) {
    if (x == 1) return;
    r.pb(x);
    int m = x / 2;
    for (int i = 1; i <= m; i++) {
        swap(v[i], v[x - i + 1]);
    }
}

void solve() {
    r.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> v[i];

    for (int i = 1; i <= n; i++) {
        if (i % 2 != v[i] % 2) {
            cout << -1 << endl;
            return;
        }
    }


    for (int i = n; i >= 3; i -= 2) {
        int odd = pos(i);
        int even = pos(i - 1);
        int diff = ab(odd - even);

        if (diff >= 2) {
            if (odd < even) {
                move(odd);
                move(even - 1);
            } else {
                move(odd);
                move(pos(i - 1) - 1);
            }
        }

        odd = pos(i);
        even = pos(i - 1);
        diff = ab(odd - even);

        if (odd == i && even == i - 1) continue;

        if (diff == 1) {
            if (odd < even) {
                move(even + 1);
                move(pos(i));
                move(i);
            } else {
                move(odd);
                move(i);
            }
        }
    }
    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;
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
