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

string s;

int calc(int idx) {
    queue<int> q;
    vi cnt(10, 0);
    int check = 0, r = 0, di = 0, m =0;
    for (char x: s) {
        x -= '0';
        q.push(x);
        ++cnt[x];
        if (cnt[x] == 1)di++;
        if (q.size() > idx) {
            --cnt[q.front()];
            if (cnt[q.front()] == 0)di--;
            q.pop();
        }
        m =0;
        for(int y:cnt)m = max(m, y);
        if (q.size() == idx && m <= di)r++;
    }
    return r;
}

void solve() {
    int n;
    cin >> n >> s;
    int r = 0;
    for (int i = 1; i <= 100; i++)r += calc(i);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
