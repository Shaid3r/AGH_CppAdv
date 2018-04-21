#include <iostream>
#include <type_traits>

template <typename T>
auto GetValue(T val) {
    if constexpr (std::is_pointer_v<T>)
        return *val;
    else
        return val;
}

int main() {
    int v = 10;
    std::cout << GetValue(v) << '\n'; // 10
    std::cout << GetValue(&v) << '\n'; // 10
    return 0;
}