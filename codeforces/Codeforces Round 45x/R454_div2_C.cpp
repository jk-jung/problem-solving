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
    set<char> st;
    for (char i = 'a'; i <= 'z'; i++)st.insert(i);
    int r = 0;
    while (n--) {
        string a, b;
        cin >> a >> b;
        if (st.size() == 1) {
            if (a == "?") {
                if (!st.count(b[0])) r++;
            } else if (a == "!") r++;
        } else {
            if (a == "!") {
                for (char i = 'a'; i <= 'z'; i++) {
                    if (b.find(i) == string::npos)st.erase(i);
                }
            } else if (a == ".") {
                for (char i: b)st.erase(i);
            } else if (a == "?") {
                st.erase(b[0]);
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
