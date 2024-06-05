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
    ll t = 0;
    ll r = 0;
    for (int i = 4; i < s.size(); i++) {
        if (s[i - 4] == 'h' && s[i - 3] == 'e' && s[i - 2] == 'a' && s[i - 1] == 'v' && s[i] == 'y')t++;
        if (s[i - 4] == 'm' && s[i - 3] == 'e' && s[i - 2] == 't' && s[i - 1] == 'a' && s[i] == 'l')r += t;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
