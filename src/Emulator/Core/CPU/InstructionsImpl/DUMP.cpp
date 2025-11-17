#include "Emulator/Core/CPU/CPU.hpp"
#include <fmt/chrono.h>

static std::string string_replace_all(const std::string& str, const std::string& from, const std::string& to) {
  if (from.empty())
    return str;

  std::string result = str;
  size_t start_pos = 0;
  while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
    result.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
  return result;
}

void HyperCPU::CPU::ExecDUMP(const IInstruction& /* instr */, OperandContainer /* op1 */, OperandContainer /* op2 */) {
  // Template
  std::string dump_text = R"(
================ HyperCPU dump (%time%) ================
Registers:
	GP:
	x0 = %x0% | xl0 = %xl0% | xh0 = %xh0% | xll0 = %xll0% | xllh0 = %xllh0% | xlll0 = %xlll0%
	x1 = %x1% | xl1 = %xl1% | xh1 = %xh1% | xll1 = %xll1% | xllh1 = %xllh1% | xlll1 = %xlll1%
	x2 = %x2% | xl2 = %xl2% | xh2 = %xh2% | xll2 = %xll2% | xllh2 = %xllh2% | xlll2 = %xlll2%
	x3 = %x3% | xl3 = %xl3% | xh3 = %xh3% | xll3 = %xll3% | xllh3 = %xllh3% | xlll3 = %xlll3%
	x4 = %x4% | xl4 = %xl4% | xh4 = %xh4% | xll4 = %xll4% | xllh4 = %xllh4% | xlll4 = %xlll4%
	x5 = %x5% | xl5 = %xl5% | xh5 = %xh5% | xll5 = %xll5% | xllh5 = %xllh5% | xlll5 = %xlll5%
	x6 = %x6% | xl6 = %xl6% | xh6 = %xh6% | xll6 = %xll6% | xllh6 = %xllh6% | xlll6 = %xlll6%
	x7 = %x7% | xl7 = %xl7% | xh7 = %xh7% | xll7 = %xll7% | xllh7 = %xllh7% | xlll7 = %xlll7%
	Stack:
	xsp = %xsp% | xbp = %xbp%
	Other:
	xgdp = %xgdp%
	xivt = %xivt%
	xip = %xip%
	)";
  // TODO: Show memory around xip

  // Replace placeholders
  auto now = std::chrono::system_clock::now();
  std::string now_text = fmt::format("{:%Y-%m-%d %H:%M:%S}", now);
  dump_text = string_replace_all(dump_text, "%time%", now_text);
  for (uint8_t i = 0; i <= 7; i++) {
    std::array<std::string_view, 6> regs = {"xN", "xlN", "xhN", "xllN", "xllhN", "xlllN"};
    for (std::string_view reg_n : regs) {
      std::string reg = string_replace_all(std::string(reg_n), "N", std::to_string(i));
      dump_text = string_replace_all(dump_text, fmt::format("%{}%", reg), *x);
    }
  }
  fmt::println("{}", dump_text);

  // TODO: write to file
}
