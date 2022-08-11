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
    string s;
    map<int, char> v;
    cin >> s;
    for (int i = 0; i < s.size(); i++)v[i + 1] = s[i];

    vector<vi> r;
    while (true) {
        while (!v.empty() && v.begin()->S == ')')v.erase(v.begin()->F);
        while (!v.empty() && v.rbegin()->S == '(')v.erase(v.rbegin()->F);

        vi tmp;
        auto a = v.begin();
        auto b = v.rbegin();
        while (true) {
            while (a != v.end() && a->S != '(')a++;
            while (b != v.rend() && b->S != ')')b++;
            if (a == v.end() || b == v.rend() || a->F > b->F)break;
            tmp.pb(a->F);
            tmp.pb(b->F);
            a++;
            b++;
        }
        if (tmp.empty())break;
        r.pb(tmp);
        for (int x: tmp)v.erase(x);
    }
    cout << r.size() << endl;
    for (auto &t: r) {
        cout << t.size() << endl;
        sort(t.begin(), t.end());
        for (int x: t)cout << x << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
