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
    int n;
    cin >> n;
    vi v(n);
    map<int, int> ck;
    for (int &x: v)cin >> x, ck[x]++;
    int one = 0, three = 0;
    for (auto [x, y]: ck) {
        if (y == 1)one++;
        else if (y >= 3) three++;
    }

    if (one % 2 == 0) {
        cout << "YES\n";
        for (int x: v) {
            if (ck[x] == 1) {
                cout << (one % 2 ? 'A' : 'B');
                one--;
            } else cout << "A";
        }
    } else if (three > 0) {
        cout << "YES\n";
        bool flag = true;
        for (int x: v) {
            if (ck[x] == 1) {
                cout << (one % 2 ? 'A' : 'B');
                one--;
            } else if (ck[x] >= 3 && flag) {
                flag = false;
                cout << "B";
            } else cout << "A";
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
