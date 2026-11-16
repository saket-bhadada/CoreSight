#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <vector>
#include <memory>
#include <string_view>

namespace astra
{
    class StringPool
    {
    public:
        using Id = std::uint32_t;

        StringPool() = default;
        StringPool(StringPool &&) noexcept = default;
        StringPool &operator=(StringPool &&) noexcept = default;
        StringPool(const StringPool &) = delete;
        StringPool &operator=(const StringPool &) = delete;

        Id intern(std::string_view s);
        void seal();
        std::string_view view(Id id);
    };
}