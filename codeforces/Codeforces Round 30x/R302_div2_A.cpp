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
    int n;
    string s;
    cin >> n >> s;
    vector<string> r;
    r.pb("");
    r.back() += s[0];
    set<char> c;
    c.insert(s[0]);
    for (int i = 1; i < s.size(); i++) {
        char x = s[i];
        if(r.size() < n && c.find(x) == c.end()){
            r.pb("");
            c.insert(x);
        }
        r.back() += x;
    }

    if(r.size() < n)cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < r.size(); i++) {
            cout << r[i] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
