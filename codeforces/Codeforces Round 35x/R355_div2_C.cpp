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
    ll r = 1;
    for (char x: s) {
        int y;
        if (x == '-') y = 62;
        else if (x == '_') y = 63;
        else if (x >= 'a') y = x - 'a' + 36;
        else if (x >= 'A') y = x - 'A' + 10;
        else y = x - '0';

        for (int i = 0; i < 6; i++) {
            if (y >> i & 1);
            else r = r * 3 % 1000000007;
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
