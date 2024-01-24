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
    map<char, int> c;
    string s;
    cin >> s;
    for (char x: s)c[x]++;
    vector<char> v;
    for (auto [x, y]: c)if (y % 2)v.pb(x);

    if (v.size() >= 2) {
        int i = 0, j = v.size() - 1;
        while (i < j) {
            c[v[i]]++;
            c[v[j]]--;
            i++;
            j--;
        }
    }
    string r;
    for (auto [x, y]: c) {
        for (int i = 0; i < y / 2; i++)r += x;
    }
    string t = r;
    reverse(t.begin(), t.end());
    if (v.size() % 2) r += v[v.size() / 2];
    r += t;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
