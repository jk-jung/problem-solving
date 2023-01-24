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

string s = "abcacba";

int f(int x, int a, int b, int c) {
    int r = 0;
    for (int i = 0; i < 7; i++) {
        int k = (i + x) % 7;
        if (s[k] == 'a') a--;
        if (s[k] == 'b') b--;
        if (s[k] == 'c') c--;
        if (a < 0 || b < 0 || c < 0)break;
        r++;
    }
    return r;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int t = min(a / 3, min(b / 2, c / 2));
    int r = 7 * t;
    a -= 3 * t;
    b -= 2 * t;
    c -= 2 * t;

    int rr = 0;
    for (int i = 0; i < 7; i++) {
        rr = max(rr, f(i, a, b, c));
    }
    cout << r + rr<< endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
