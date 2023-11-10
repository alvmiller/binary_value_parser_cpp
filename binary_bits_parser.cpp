#include <cassert>
#include <iostream>

template<typename ... Ts> constexpr unsigned long long 
binary_bits_parser (unsigned long long res, char symbol, Ts ... symbols) {
    unsigned digit = (symbol == '1') ? 1 : (symbol == '0') ? 0 : throw "Out of range";
    if constexpr (sizeof ... (Ts) != 0) {
        return binary_bits_parser(res * 2 + digit, symbols ...);
    }
    return res * 2 + digit;
}

template<char ... Symbols>
constexpr unsigned long long operator""_bin()
{
    return binary_bits_parser(0ull, Symbols ...);
}

int main()
{
    constexpr unsigned long long x = 10001111_bin;
    assert(x == 143);

    return 0;
}
