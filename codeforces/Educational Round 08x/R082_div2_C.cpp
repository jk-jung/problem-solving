#include <string.h>
#include <stdio.h>
#include <math.h>
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


int ck[66], no = 0;
set<int> v[55];

void dfs(int x, int z, string &t) {
    ck[x] = 1;
    char c = 'a' + x;
    for (int y: v[x]) {
        if (y == z)continue;
        if(ck[y]) {no = 1; return;}
        if (t[0] == c) t = string(1, 'a' + y) + t;
        else t += string(1, 'a' + y);
        dfs(y, x, t);
    }
}

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)v[i].clear();
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int x = s[i] - 'a';
        int y = s[i - 1] - 'a';

        v[x].insert(y);
        v[y].insert(x);
    }
    for (int i = 0; i < 26; i++) {
        if (v[i].size() > 2) {
            cout << "NO\n";
            return;
        }
    }
    string r;
    no = 0;
    memset(ck, 0, sizeof(ck));
    for (int i = 0; i < 26; i++) {
        if(!ck[i]) {
            string t(1, 'a' + i);
            dfs(i, -1, t);
            r += t;
        }
    }
    if(no) {
        cout <<"NO\n";
        return;
    }
    cout << "YES\n";
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
