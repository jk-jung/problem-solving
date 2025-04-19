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
    cin >> s;
    int n = s.size();
    int r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            string a = s.substr(i, j);
            for (int k = i + 1; k <= n - j; k++) {
                string b = s.substr(k, j);
                if (a == b) {
                    r = max(r, j);
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
