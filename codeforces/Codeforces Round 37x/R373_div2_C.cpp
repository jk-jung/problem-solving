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

int n, t;
char s[200005];
int d[200005];

int go(int x) {
    int &r = d[x];
    if (r != -1) return r;
    r = 0;

    if (x == n || s[x + 1] <= '3') r = 1 << 30;
    else if (s[x + 1] == '4')r = go(x + 1);
    else if (s[x + 1] >= '5')r = 1;
    r += 1;
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> n >> t >> s;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) {
            if (s[i] >= '5' || (s[i] == '4' && go(i) <= t)) {
                s[i] = 0;
                int k = 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (s[j] == '.') {
                        s[j - 1] += k;
                        k = 0;
                    } else {
                        s[j] += k;
                        k = 0;
                        if (s[j] > '9')k = 1, s[j] = '0';
                    }
                }
                string r= s;
                if(k) r = "1" + r;
                if(r.back() == '.')r.pop_back();
                cout << r << endl;
                return;
            }
        }
        if (s[i] == '.') {
            flag = true;
        }
    }
    cout << s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
