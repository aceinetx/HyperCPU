#pragma once

namespace HyperCPU {
  class CPU;
  class Dumper {
  public:
    Dumper() = default;
    ~Dumper() = default;

    static Dumper& getInstance();
    void DumpCPUState(HyperCPU::CPU* cpu);

    Dumper(const Dumper&) = delete;
    Dumper(Dumper&& other) = delete;
    Dumper& operator=(const Dumper&) = delete;
    Dumper& operator=(Dumper&& other) = delete;
  };
} // namespace HyperCPU
