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
    string v;
    cin >> v;
    int s = 1, e = v.size(), r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        map<char, int> st;
        for (int i = 0; i < m; i++)st[v[i]]++;
        for (int i = m; i < v.size(); i++) {
            char x = v[i];
            if (st.count(x))st[x]++;
            if (st.count(v[i - m]) && --st[v[i - m]] == 0)st.erase(v[i - m]);
        }
        if (!st.empty())e = m - 1, r = m;
        else s = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
