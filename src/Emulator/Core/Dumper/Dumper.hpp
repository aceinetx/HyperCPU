#pragma once
#include "Emulator/Core/CPU/Interrupts/ReservedInterrupts.hpp"
#include <PCH/CStd.hpp>

namespace HyperCPU {
  class CPU;
  class Dumper {
  public:
    Dumper() = default;
    ~Dumper() = default;

    static Dumper& GetInstance();

    Dumper(const Dumper&) = delete;
    Dumper(Dumper&& other) = delete;
    Dumper& operator=(const Dumper&) = delete;
    Dumper& operator=(Dumper&& other) = delete;

  public:
    std::optional<std::string> DumpCPUState(HyperCPU::CPU* cpu, std::optional<HyperCPU::cpu_exceptions> exception);

  protected:
    std::string GetExceptionName(std::uint64_t index);
    std::string GetExceptionName(HyperCPU::cpu_exceptions exception);
  };
} // namespace HyperCPU
