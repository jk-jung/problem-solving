#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void process(vi &v, bool done=true) {
    vector<pi> t;
    for (int i = 0; i < v.size(); i++)t.pb(mp(v[i], i));
    sort(t.rbegin(), t.rend());
    set<int> idx;
    for (int i = 0; i < min(3, (int) t.size()); i++)idx.insert(t[i].S);

    int st = 0;
    for (int i = 0; i < v.size(); i++) {
        if (idx.count(i)) {
            if (st == 0) {
                cout << "pushQueue" << endl;
            } else if (st == 1) {
                cout << "pushStack" << endl;
            } else if (st == 2) {
                cout << "pushFront" << endl;
            }
            st++;
        } else {
            if (st == 0) {
                cout << "pushStack" << endl;
            } else {
                cout << "pushQueue" << endl;
            }
        }
    }

    vector<string> r = {
            "popQueue",
            "popStack",
            "popFront",
    };
    if(done){
        cout << idx.size();
        for (int i = 0; i < idx.size(); i++) {
            cout <<" " << r[i];
        }
        cout << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    vi t;
    for (int x: v) {
        if (x == 0) {
            process(t);
            t.clear();
        } else t.pb(x);
    }
    process(t, false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
