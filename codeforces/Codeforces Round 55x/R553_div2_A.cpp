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
    string s, t = "ACTG";
    cin >> n >> s;
    int r = 999999;
    for (int i = 0; i <= n - 4; i++) {
        int d =0;
        for (int j = 0; j < 4; j++) {
            int x = s[i + j] - 'A';
            int y = t[j] - 'A';
            d += min(ab(x - y), min(ab(x + 26 - y), ab(y + 26 - x)));
        }
        r = min(r, d);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
