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


bool sf(string &a, string &b) { return a.size() > b.size(); }

void solve() {
    int n;
    cin >> n;
    map<string, vector<string>> v;

    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;
        for (int j = 0; j < m; j++) {
            string x;
            cin >> x;
            v[s].pb(x);
        }
    }


    cout << v.size() << endl;
    for (auto &[x, y]: v) {
        vector<string> r;
        sort(y.begin(), y.end(), sf);
        for(auto &t: y) {
            bool ok = true;
            for(auto &z: r) {
                if(z.substr(z.size() - t.size()) == t) {
                    ok = false;
                    break;
                }
            }
            if(ok) r.pb(t);
        }
        cout << x << " " << r.size() << " ";
        for (auto z: r)cout << z << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
