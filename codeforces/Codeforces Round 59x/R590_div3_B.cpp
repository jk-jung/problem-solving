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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    deque<int> q;
    set<int> s;
    for (int x: v) {
        if (!s.count(x) && q.size() < k) {
            q.push_front(x);
            s.insert(x);
        } else if (!s.count(x)) {
            s.erase(q.back());
            q.pop_back();

            s.insert(x);
            q.push_front(x);
        }
    }
    cout << q.size() << endl;
    for (int x: q)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
