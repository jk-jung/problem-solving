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
    int m;
    cin >> s >> m;

    while (m--) {
        int a, b, k;
        cin >> a >> b >> k;
        a--, b--;
        string t = s;
        int n = b - a + 1;
        k %= n;
        for (int i = a; i <= b; i++) {
            int j = i - k;
            if (j < a)j += n;
            t[i] = s[j];
        }
        s = t;
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
