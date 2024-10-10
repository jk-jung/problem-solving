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
    string s;
    cin >> s;
    map<char, queue<int>> ck;
    for (int i = 0; i < s.size(); i++)ck[s[i]].push(i);

    string r;
    int idx = -1;
    while (true) {
        bool done = true;
        for (char x = 'z'; x >= 'a'; x--) {
            queue<int> &q = ck[x];
            while (!q.empty() && q.front() <= idx)q.pop();
            if (!q.empty()) {
                r += x;
                idx = q.front();
                done = false;
                break;
            }
        }

        if (done)break;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
