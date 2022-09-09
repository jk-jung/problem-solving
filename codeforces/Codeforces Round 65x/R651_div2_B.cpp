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
    cin >> n;
    vi v(n * 2);
    for (int &x: v)cin >> x;
    queue<int> q, q2;
    for (int i = 0; i < n * 2; i++) {
        if(v[i] % 2) q.push(i + 1);
        else q2.push(i + 1);
    }
    int cnt = 0;
    while(q.size() >= 2) {
        cnt ++;
        if(cnt == n)break;
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        cout << a << " " << b << endl;
    }
    while(q2.size() >= 2) {
        cnt ++;
        if(cnt == n)break;
        int a = q2.front(); q2.pop();
        int b = q2.front(); q2.pop();
        cout << a << " " << b << endl;
    }
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
