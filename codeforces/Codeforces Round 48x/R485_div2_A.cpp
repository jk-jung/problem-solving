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

vector<pair<string, string>> v = {
        {"Power",   "purple"},
        {"Time",    "green"},
        {"Space",   "blue"},
        {"Soul",    "orange"},
        {"Reality", "red"},
        {"Mind",    "yellow"}
};

void solve() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int idx = -1;
        for (int i = 0; i < v.size(); i++)if (s == v[i].S)idx = i;
        v.erase(v.begin() + idx);
    }
    cout << v.size() << endl;
    for (auto [x, y]: v)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
