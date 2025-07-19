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


void solve() {
    string s, r;
    cin >> s;

    int st = 0;
    // st = 0: need char
    // st = 1: need @
    // st = 2: need char
    vector<string> v;
    for (char x: s) {
        if (x == '@') {
            if (st == 0 || st == 2) {
                cout << "No solution";
                return;
            }
            st = 2;
            r += x;
        } else {
            if(st != 1)
                st++;
            r += x;
            if (st == 3) {
                v.pb(r);
                r = "";
                st = 0;
            }
        }

    }
//    if(r.back() == ',')r.pop_back();
    if(!r.empty()){
        if(v.empty() || r.back() == '@'){
            cout << "No solution";
            return;
        }
        v.back() += r;
    }

    for (int i = 0; i < v.size(); i++) {
        if (i)cout << ",";
        cout << v[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
