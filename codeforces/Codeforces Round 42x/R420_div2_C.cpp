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

int c[300005];

void solve() {
    int n;
    cin >> n;
    vi v;
    int cur = 1, r = 0;
    set<int> ck;
    for (int i = 0; i < n * 2; i++) {
        string o;
        cin >> o;
        if (o[0] == 'a') {
            int x;
            cin >> x;
            v.pb(x);
            ck.insert(x);
        } else {
            int x = v.back();
            if (c[x] || v.back() == cur){
                if(!v.empty() && v.back() == cur) v.pop_back();
            }
            else {
                for (auto y: ck)c[y] = 1;
                ck.clear();
                r ++;
            }
            cur++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
