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
    int k;
    string s;
    int t = 0;
    cin >> k >> s;

    sort(s.begin(), s.end());
    for (char x: s)t += x - '0';
    int tt = k - t;
    if (k - t <= 0)cout << 0 << endl;
    else {
        int r = 0;
        for (char x: s) {
            int y = 9 - (x - '0');
            tt -= y;
            r++;
            if (tt <= 0)break;
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
