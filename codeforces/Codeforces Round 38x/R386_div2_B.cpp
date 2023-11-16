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
    deque<char> q;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (n % 2) {
            if (i % 2)q.push_front(s[i]);
            else q.push_back(s[i]);
        } else {
            if (i % 2 == 0)q.push_front(s[i]);
            else q.push_back(s[i]);
        }
    }
    for (char x: q)cout << x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
