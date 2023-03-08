#include "rapidcheck/detail/FrequencyMap.h"

#include <algorithm>

namespace rc {
namespace detail {

FrequencyMap::FrequencyMap(const std::vector<std::size_t> &frequencies)
    : m_sum(0) {
  m_table.reserve(frequencies.size());
  for (auto x : frequencies) {
    m_sum += x;
    m_table.push_back(m_sum);
  }
}

std::size_t FrequencyMap::lookup(std::size_t x) const {
  // upper_bound(first, last, x) will always return in the range [first, last]
  // Therefore upper_bound(begin(m_table), ...) - begin(m_table) will be >= 0
  return static_cast<std::size_t>(
    std::upper_bound(begin(m_table), end(m_table), x) - begin(m_table));
}

std::size_t FrequencyMap::sum() const { return m_sum; }

} // namespace detail
} // namespace rc
