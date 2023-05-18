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
    ll n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    s = "1" + s + "1";
    int c = 0;
    for (int i = 1; i < n + 2; i++) {
        if (s[i - 1] == '1' && s[i] == '0')c++;
    }
    ll r = c * b;
    if (c >= 2)r = min(r, b + (c - 1) * a);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
