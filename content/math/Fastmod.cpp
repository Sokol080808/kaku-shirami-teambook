/**
 * Author: talant
 * Date: 2024-08-09
 * Description: Fast multiplication by modulo(in [0;2b))
*/
struct FastMod {
    ull b, m;
    FastMod(ull b) : b(b), m(-1ULL / b) {}
    ull reduce(ull a) { // a % b + (0 or b)
        return a - (ull)((__uint128_t(m) * a) >> 64) * b;
    }
};
