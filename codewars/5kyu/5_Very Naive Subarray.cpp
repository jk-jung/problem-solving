#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cstring>

template<std::size_t S>
int solve(std::array<int, S> a0) {
    int r = 0;

    for (int i = 0; i < a0.size(); i++) {
        std::set<int> ck1, ck2;
        for (int j = i; j >= 0; j--) {
            int k = a0[j];
            if (ck1.find(k) != ck1.end()) {
                ck1.erase(k);
                ck2.insert(k);
            } else if (ck2.find(k) != ck2.end()) {
                ck2.erase(k);
                ck1.insert(k);
            } else {
                ck1.insert(k);
            }
            if (ck2.size() == 0) r++;
        }
    }
    return r;
}
