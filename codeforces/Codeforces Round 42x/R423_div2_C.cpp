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
    int n, m = -1;
    cin >> n;
    set<int> c;
    string r(21000000, 'a');
    for (int i = 0; i <= 2100000; i++)c.insert(i);

    while (n--) {
        string s;
        int t;
        cin >> s >> t;
        while (t--) {
            int x;
            cin >> x;
            x--;
            auto it = c.lower_bound(x);
            int e = x + s.size() - 1;
            vi rm;
            while (it != c.end() && *it <= e) {
                rm.pb(*it);
                r[*it] = s[*it - x];
                m = max(m, *it);
                it ++;
            }
            for (int y: rm)c.erase(y);
        }
    }
    while (r.size() > m + 1)r.pop_back();
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
