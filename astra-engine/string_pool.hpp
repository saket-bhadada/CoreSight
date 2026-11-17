#pragma once
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
        [[nodiscard]] std::string_view view(Id id) const noexcept { return views_[id]; }
        [[nodiscard]] std::size_t size() const noexcept { return views_.size(); }
        [[nodiscard]] bool sealed() const noexcept { return sealed_; }
        [[nodiscard]] std::size_t approx_bytes();

    private:
        static constexpr std::size_t kBlockSize = 4096;
        std::string_view store(std::string_view s);
        std::vector<std::unique_ptr<char[]>> blocks_;
        std::size_t cap_ = 0;
        std::size_t used_ = 0;
        std::size_t reserved_ = 0;
        std::unordered_map<std::string_view, Id> map_;
        std::vector<std::string_view> views_;
        bool sealed_ = false;
    };
}