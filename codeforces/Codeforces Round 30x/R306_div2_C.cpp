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
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (x % 8 == 0) {
            cout << "YES\n";
            cout << x << '\n';
            return;
        }
        for (int j = i + 1; j < n; j++) {
            int y = x * 10 + s[j] - '0';
            if (y % 8 == 0) {
                cout << "YES\n";
                cout << y << '\n';
                return;
            }
            for (int k = j + 1; k < n; k++) {
                int z = y * 10 + s[k] - '0';
                if (z % 8 == 0) {
                    cout << "YES\n";
                    cout << z << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
