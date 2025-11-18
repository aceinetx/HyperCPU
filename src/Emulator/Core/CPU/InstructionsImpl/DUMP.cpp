#include "Emulator/Core/CPU/CPU.hpp"
#include "Emulator/Core/Dumper/Dumper.hpp"
#include <absl/strings/str_replace.h>
#include <fmt/chrono.h>

void HyperCPU::CPU::ExecDUMP(const IInstruction& /* instr */, OperandContainer /* op1 */, OperandContainer /* op2 */) {
  Dumper::GetInstance().DumpCPUState(this, {});
}
