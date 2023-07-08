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
    vector<string> v(3);
    for (int i = 0; i < 3; i++)cin >> v[i];

    set<int> r;
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] != '.') {
            cout << v[i][0] << endl;
            return;
        }
        if (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != '.') {
            cout << v[0][i] << endl;
            return;
        }
    }
    if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[1][1] != '.') {
        cout << v[0][0] << endl;
    } else if (v[2][0] == v[1][1] && v[1][1] == v[0][2] && v[1][1] != '.') {
        cout << v[1][1] << endl;
    } else {
        cout << "DRAW" << endl;
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
