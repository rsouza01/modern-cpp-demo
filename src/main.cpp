#include <fmt/core.h>
#include <fmt/format.h>

#include <charconv>
#include <cstdint>
#include <optional>
#include <string_view>
#include <vector>

// Parse an integer from argv using std::from_chars (fast, locale-free).
std::optional<std::int64_t> parse_int(std::string_view s) {
    std::int64_t value{};
    auto* begin = s.data();
    auto* end   = s.data() + s.size();
    auto [ptr, ec] = std::from_chars(begin, end, value);
    if (ec != std::errc{} || ptr != end) return std::nullopt;
    return value;
}

std::optional<std::uint64_t> factorial(std::int64_t n) {
    if (n < 0) return std::nullopt;
    std::uint64_t acc = 1;
    for (std::int64_t i = 2; i <= n; ++i) {
        // very small demo: ignore overflow handling for huge n
        acc *= static_cast<std::uint64_t>(i);
    }
    return acc;
}

std::uint64_t sum_of_squares(std::int64_t n) {
    // sum_{i=1..n} i^2
    std::uint64_t acc = 0;
    for (std::int64_t i = 1; i <= n; ++i) {
        acc += static_cast<std::uint64_t>(i * i);
    }
    return acc;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fmt::print("Usage: {} <integer>\n", argv[0]);
        fmt::print("Example: {} 10\n", argv[0]);
        return 2;
    }

    auto n = parse_int(argv[1]);
    if (!n) {
        fmt::print(stderr, "Error: '{}' is not a valid integer.\n", argv[1]);
        return 2;
    }

    auto f = factorial(*n);
    if (!f) {
        fmt::print(stderr, "Error: factorial is undefined for negative numbers (n={}).\n", *n);
        return 2;
    }

    auto s = sum_of_squares(*n);

    fmt::print("n = {}\n", *n);
    fmt::print("factorial(n)    = {}\n", *f);
    fmt::print("sum_of_squares(n) = {}\n", s);

    return 0;
}