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
    string s, t, r;
    cin >> s ;
    vi v(255, -1);
    for (int i = 0; i < s.size(); i++)v[s[i]] = i;

    int i = 0;
    for (char a = 'a'; a <= 'z'; a++) {
        for (; i <= v[a]; i++) {
            while(!t.empty() && t.back() <= a){
                r += t.back();
                t.pop_back();
            }
            if (s[i] == a)r += a;
            else t += s[i];
        }
    }
    reverse(t.begin(), t.end());
    cout << r << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
