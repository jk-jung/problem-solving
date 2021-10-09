#include <string>
#include <tuple>
#include <type_traits>

using namespace std;

double r = 0;

template <typename T>
void print(T x) {
    if constexpr(is_same_v<T, int>) r += x;
    if constexpr(is_same_v<T, double>) r += x;
}

template <typename... Ts>
double tuple_sum(const tuple<Ts...>& tpl) {
    r = 0;
    std::apply([](auto&&... args) {(print(args), ...);}, tpl);
    return r;
}