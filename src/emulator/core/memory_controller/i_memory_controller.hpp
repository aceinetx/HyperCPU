#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#define mem_ctlr_assert(expr)                       \
  do {                                              \
    if (!(expr) && !cpu) [[unlikely]] {             \
      std::println("Assertion failed: {}", #expr);  \
      std::abort();                                 \
    } else if (!(expr) && cpu) [[unlikely]] {       \
      cpu->trigger_interrupt(hypercpu::cpu_exceptions::SEGF); \
    } else [[likely]] {  }                          \
  } while (false)

namespace hypercpu {
  class i_memory_controller {
  public:
    virtual std::uint8_t fetch8(std::size_t&) = 0;
    virtual std::uint16_t fetch16(std::size_t&) = 0;
    virtual std::uint32_t fetch32(std::size_t&) = 0;
    virtual std::uint64_t fetch64(std::size_t&) = 0;

    virtual std::uint8_t read8(std::size_t) = 0;
    virtual std::uint16_t read16(std::size_t) = 0;
    virtual std::uint32_t read32(std::size_t) = 0;
    virtual std::uint64_t read64(std::size_t) = 0;

    virtual void load8(std::size_t, std::uint8_t) = 0;
    virtual void load16(std::size_t, std::uint16_t) = 0;
    virtual void load32(std::size_t, std::uint32_t) = 0;
    virtual void load64(std::size_t, std::uint64_t) = 0;

    virtual std::uint8_t* get_ptr() const noexcept = 0;

    virtual ~i_memory_controller() { };
  };

}