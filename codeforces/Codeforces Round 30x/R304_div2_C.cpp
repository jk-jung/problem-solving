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


deque<int> read() {
    int n;
    cin >> n;
    deque<int> v(n);
    for (int &x: v)cin >> x;
    return v;
}

void solve() {
    int n;
    cin >> n;
    deque<int> a = read();
    deque<int> b = read();

    set<pair<deque<int>, deque<int> > > s;
    int r = 0, rr = 0;
    while (true) {
        if (a.empty()) {
            rr = 2;
            break;
        }
        if (b.empty()) {
            rr = 1;
            break;
        }
        r++;
        if (s.count(mp(a, b))) {
            cout << -1 << endl;
            return;
        }
        s.insert(mp(a, b));

        int x = a.front();
        a.pop_front();
        int y = b.front();
        b.pop_front();

        if (x > y) {
            a.push_back(y);
            a.push_back(x);
        } else {
            b.push_back(x);
            b.push_back(y);
        }
    }
    cout << r << " " << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
