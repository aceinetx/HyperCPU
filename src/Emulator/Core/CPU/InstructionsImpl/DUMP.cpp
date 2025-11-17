#include "Emulator/Core/CPU/CPU.hpp"

void HyperCPU::CPU::ExecDUMP(const IInstruction& /* instr */, OperandContainer /* op1 */, OperandContainer /* op2 */) {
  fmt::println("dump");
}
