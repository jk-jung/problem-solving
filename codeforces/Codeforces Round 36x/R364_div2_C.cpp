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
    map<char, int> a, b;
    for (char x: s)a[x]++;
    int r = n;
    for (int i = 0, j = 0; i < n; i++) {
        b[s[i]]++;
        while (b.size() == a.size()) {
            if(b[s[j]] == 1)break;
            b[s[j]]--;
            if (b[s[j]] == 0)b.erase(s[j]);
            j ++;
        }
        if(b.size() == a.size())
            r = min(r, i - j + 1);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
