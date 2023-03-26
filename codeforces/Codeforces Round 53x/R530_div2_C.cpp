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
    int k;
    string v;
    cin >> v >> k;
    int s = 0, e = 0, c = 0, d = 0, t = 0;
    for (char x: v) {
        if (x == '?')s--, c++;
        else if (x == '*')s--, e = max(e, 1 << 30), d++;
        else s++, e++, t++;
    }
    if (s <= k && k <= e) {
        if (d) {
            string r, r1;
            for (int i = 0; i < v.size(); i++) {
                char x = v[i];
                if (x == '?') r.pop_back();
                else if (x == '*') {
                    for (int j = i + 1; j < v.size(); j++) {
                        char y = v[j];
                        if (y == '?' || y == '*') r1.pop_back();
                        else r1 += y;
                    }
                    while (r.size() + r1.size() < k) {
                        r += r.back();
                    }
                    if(r.size() + r1.size() > k) {
                        r.pop_back();
                    }
                    cout << r + r1 << endl;
                    return;
                } else r += x;
            }
        } else {
            string r;
            for (char x: v) {
                if (x == '?') {
                    if (t > k) {
                        t--;
                        r.pop_back();
                    }
                } else r += x;
            }
            cout << r << endl;
            return;
        }
    } else cout << "Impossible\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
