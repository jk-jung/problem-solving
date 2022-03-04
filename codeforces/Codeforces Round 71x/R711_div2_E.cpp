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

int a[505];
vi v[505];


bool q(int x, int y) {
    cout << "? " << x << " " << y << endl;
    string s;
    cin >> s;
    return s[0] == 'Y';
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a[i] = n - 1 - x;
        v[a[i]].pb(i);
    }

    for (int dif = 500; dif >= 0; dif--) {
        for (int i = n; i >= 0; i--) {
            int j = i - dif;
            if (j < 0)break;
            if (v[i].empty() || v[j].empty())continue;

            for (int x: v[i]) {
                for (int y: v[j]) {
                    if (x == y)continue;
                    if (q(y, x)) {
                        cout << "! " << x << " " << y << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "! " << 0 << " " << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
