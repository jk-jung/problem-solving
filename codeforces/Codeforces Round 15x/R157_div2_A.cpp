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
    string s;
    bool ok = true;

    for (int i = 0; i < 8; i++) {
        bool no = true;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            bool good = true;
            for (int k = 0; k < 8; k++) {
                char x = s[(j + k) % 8];
                if (k % 2 == 0 && x == 'W');
                else if (k % 2 == 1 && x == 'B');
                else good = false;
            }
            if (good)no = false;
        }
        if (no)ok = false;
    }

    cout << (ok ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
