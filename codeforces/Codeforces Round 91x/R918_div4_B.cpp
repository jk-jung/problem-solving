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
    for (auto &x: v)cin >> x;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] == '?') {
                bool a = false, b = false, c = false;
                for (int k = 0; k < 3; k++) {
                    if (v[i][k] == 'A')a = true;
                    if (v[i][k] == 'B')b = true;
                    if (v[i][k] == 'C')c = true;
                }
                if (!a)cout << "A\n";
                if (!b)cout << "B\n";
                if (!c)cout << "C\n";
                return;
            }
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
