#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdlib>

#include <Misc/print.hpp>

#define mem_ctlr_assert(expr)                       \
  do {                                              \
    if (!(expr) && (!cpu || !cpu->CanExecuteInterrupts())) [[unlikely]] { \
      HyperCPU::println("Assertion failed: {}", #expr);  \
      std::abort();                                 \
    } else if (!(expr) && cpu && cpu->CanExecuteInterrupts()) { \
      cpu->TriggerInterrupt(HyperCPU::cpu_exceptions::SEGF); \
    } else [[likely]] {  }                          \
  } while (false)

namespace HyperCPU {
  class IMemoryController {
  public:
    virtual std::uint8_t Fetch8(std::size_t&) = 0;
    virtual std::uint16_t Fetch16(std::size_t&) = 0;
    virtual std::uint32_t Fetch32(std::size_t&) = 0;
    virtual std::uint64_t Fetch64(std::size_t&) = 0;

    virtual std::uint8_t Read8(std::size_t) = 0;
    virtual std::uint16_t Read16(std::size_t) = 0;
    virtual std::uint32_t Read32(std::size_t) = 0;
    virtual std::uint64_t Read64(std::size_t) = 0;

    virtual void Load8(std::size_t, std::uint8_t) = 0;
    virtual void Load16(std::size_t, std::uint16_t) = 0;
    virtual void Load32(std::size_t, std::uint32_t) = 0;
    virtual void Load64(std::size_t, std::uint64_t) = 0;

    virtual std::uint8_t* get_ptr() const noexcept = 0;

    virtual ~IMemoryController() { };
  };

}
