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
    int n, m;
    string s;
    cin >> n >> s;
    m = n;
    for (char x = 'z'; x >= 'a'; x--) {
        while (true) {
            bool flag = true;
            string t;
            n = s.size();
            for (int i = 0; i < n; i++) {
                bool ok = false;
                if (s[i] == x) {
                    if (i > 0 && s[i - 1] + 1 == x)ok = true;
                    if (i < n - 1 && s[i + 1] + 1 == x)ok = true;
                }
                if (!ok) t += s[i];
                else flag = false;
            }
            s = t;
            if (flag)break;
        }
    }
    cout << m - n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
