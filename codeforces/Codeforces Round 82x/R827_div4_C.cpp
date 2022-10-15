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
    vector<string> v(8);
    for (auto &x: v)cin >> x;

    for (int i = 0; i < 8; i++) {
        set<char> a, b;
        for (int j = 0; j < 8; j++) {
            a.insert(v[i][j]);
            b.insert(v[j][i]);
        }
        if (a.size() == 1 && *a.begin() == 'R') {
            cout << "R\n";
            return;
        }
        if (b.size() == 1 && *b.begin() == 'B') {
            cout << "B\n";
            return;
        }
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
