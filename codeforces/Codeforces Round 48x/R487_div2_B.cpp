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
    int n, p;
    string s;
    cin >> n >> p >> s;

    int no = 0, tar = 0;
    for (int i = 0; i < p; i++) {
        bool a = false, b = false, c = false;
        int cc = 0;
        for (int j = i; j < n; j += p) {
            cc++;
            if (s[j] == '1') a = true;
            if (s[j] == '0') b = true;
            if (s[j] == '.') c = true;
        }
        if (cc > 1) {
            if (!c && (a ^ b))no++;
            tar++;
        }

        char t = a ? '0' : '1';
        for (int j = i; j < n; j += p)
            if (s[j] == '.') {
                s[j] = t;
                t = t == '0' ? '1' : '0';
            }
    }
    if (no == tar)cout << "NO";
    else cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
