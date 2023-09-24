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
    int r = 9;
    for (int i = 0; i <= 999999; i++) {
        if (i / 1000 != i % 1000);
        string t = to_string(i);
        while (t.size() < 6)t = "0" + t;

        int e = 0;
        for (int k = 0; k < 3; k++)e += t[k];
        for (int k = 3; k < 6; k++)e -= t[k];
        if (e)continue;
        for (int k = 0; k < t.size(); k++) {
            if (t[k] != s[k])e++;
        }
        r = min(r, e);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
