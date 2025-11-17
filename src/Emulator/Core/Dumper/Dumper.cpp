#include "Emulator/Core/Dumper/Dumper.hpp"
#include "Emulator/Core/CPU/CPU.hpp"
#include <PCH/CStd.hpp>
#include <absl/strings/str_replace.h>
#include <fmt/chrono.h>

HyperCPU::Dumper& HyperCPU::Dumper::getInstance() {
  static HyperCPU::Dumper instance;
  return instance;
}

void HyperCPU::Dumper::DumpCPUState(HyperCPU::CPU* cpu) {
  // Template
  std::string dump_text = R"(
================ HyperCPU dump (%time%) ================
Registers:
	GP:
	x0 = %x0% | x1 = %x1% | x2 = %x2% | x3 = %x3% | x4 = %x4% | x5 = %x5% | x6 = %x6% | x7 = %x7%
	Stack:
	xsp = %xsp% | xbp = %xbp%
	Other:
	xgdp = %xgdp%
	xivt = %xivt%
	xip = %xip%
	)";
  // TODO: Show memory around xip

  // Map registers to their values
  std::map<std::string, std::variant<uint64_t*>> registerMapping = {
      {"x0", cpu->x0},
      {"x1", cpu->x1},
      {"x2", cpu->x2},
      {"x3", cpu->x3},
      {"x4", cpu->x4},
      {"x5", cpu->x5},
      {"x6", cpu->x6},
      {"x7", cpu->x7},
      {"xsp", cpu->xsp},
      {"xbp", cpu->xbp},
      {"xgdp", cpu->xgdp},
      {"xivt", cpu->xivt},
      {"xip", cpu->xip},
  };

  // Replace placeholders
  auto now = std::chrono::system_clock::now();
  std::string now_text = fmt::format("{:%Y-%m-%d %H:%M:%S}", now);
  dump_text = absl::StrReplaceAll(dump_text, {{"%time%", now_text}});

  for (const auto& [name, value] : registerMapping) {
    std::string name_placeholder = fmt::format("%{}%", name);

    std::visit([&dump_text, name_placeholder](auto&& arg) {
      dump_text = absl::StrReplaceAll(dump_text, {{name_placeholder, std::to_string(*std::forward<decltype(arg)>(arg))}});
    },
               value);
  }
  fmt::println("{}", dump_text);

  // TODO: write to file
}
