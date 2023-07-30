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
    string s;
    cin >> n >> s;

    bool r = false;
    for (int i = 0; i < s.size(); i++) {
        if (i && s[i] != '?' && s[i] == s[i - 1]) {
            r = false;
            break;
        }
        if ((i == 0 || i == n - 1) && s[i] == '?')r = true;
        if (i > 0 && i < n - 2 && s[i] == '?') {
            if(s[i - 1] != '?' && s[i + 1] != '?' && s[i - 1] != s[i + 1]);
            else r = true;
        }
    }

    cout << (r ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
