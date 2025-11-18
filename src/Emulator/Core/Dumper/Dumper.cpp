#include "Emulator/Core/Dumper/Dumper.hpp"
#include "Emulator/Core/CPU/CPU.hpp"
#include <absl/strings/str_replace.h>
#include <fmt/chrono.h>
#include <spdlog/spdlog.h>

HyperCPU::Dumper& HyperCPU::Dumper::GetInstance() {
  static HyperCPU::Dumper instance;
  return instance;
}

std::optional<std::string> HyperCPU::Dumper::DumpCPUState(HyperCPU::CPU* cpu, std::optional<HyperCPU::cpu_exceptions> exception) {
  // Template
  std::string dump_text = R"(================ HyperCPU dump (%time%) ================
Registers:
- GP:
	x0 = %x0% | xh0 = %xh0% | xl0 = %xh0% | xll0 = %xll0% | xllh0 = %xllh0% | xlll0 = %xlll0%
	x1 = %x1% | xh1 = %xh1% | xl1 = %xh1% | xll1 = %xll1% | xllh1 = %xllh1% | xlll1 = %xlll1%
	x2 = %x2% | xh2 = %xh2% | xl2 = %xh2% | xll2 = %xll2% | xllh2 = %xllh2% | xlll2 = %xlll2%
	x3 = %x3% | xh3 = %xh3% | xl3 = %xh3% | xll3 = %xll3% | xllh3 = %xllh3% | xlll3 = %xlll3%
	x4 = %x4% | xh4 = %xh4% | xl4 = %xh4%
	x5 = %x5% | xh5 = %xh5% | xl5 = %xh5%
	x6 = %x6% | xh6 = %xh6% | xl6 = %xh6%
	x7 = %x7% | xh7 = %xh7% | xl7 = %xh7%
- Stack:
	xsp = %xsp% | xbp = %xbp%
- Other:
	xgdp = %xgdp%
	xivt = %xivt%
	xip = %xip%
Exception: %exc%
)";
  // TODO: Show memory around xip

  // Map registers to their values
  std::map<std::string, std::variant<uint64_t*, uint32_t*, uint16_t*, uint8_t*>> registerMapping = {
      {"x0", cpu->x0},
      {"xh0", cpu->xh0},
      {"xl0", cpu->xl0},
      {"xll0", cpu->xll0},
      {"xllh0", cpu->xllh0},
      {"xlll0", cpu->xlll0},
      {"x1", cpu->x1},
      {"xh1", cpu->xh1},
      {"xl1", cpu->xl1},
      {"xll1", cpu->xll1},
      {"xllh1", cpu->xllh1},
      {"xlll1", cpu->xlll1},
      {"x2", cpu->x2},
      {"xh2", cpu->xh2},
      {"xl2", cpu->xl2},
      {"xll2", cpu->xll2},
      {"xllh2", cpu->xllh2},
      {"xlll2", cpu->xlll2},
      {"x3", cpu->x3},
      {"xh3", cpu->xh3},
      {"xl3", cpu->xl3},
      {"xll3", cpu->xll3},
      {"xllh3", cpu->xllh3},
      {"xlll3", cpu->xlll3},
      {"x4", cpu->x4},
      {"xh4", cpu->xh4},
      {"xl4", cpu->xl4},
      {"x5", cpu->x5},
      {"xh5", cpu->xh5},
      {"xl5", cpu->xl5},
      {"x6", cpu->x6},
      {"xh6", cpu->xh6},
      {"xl6", cpu->xl6},
      {"x7", cpu->x7},
      {"xh7", cpu->xh7},
      {"xl7", cpu->xl7},
      {"xsp", cpu->xsp},
      {"xbp", cpu->xbp},
      {"xgdp", cpu->xgdp},
      {"xivt", cpu->xivt},
      {"xip", cpu->xip},
  };

  auto now = std::chrono::system_clock::now();
  std::string now_text = fmt::format("{:%Y-%m-%d %H:%M:%S}", now);

  std::map<std::string, std::variant<std::string>> placeholderMapping = {
      {"time", now_text},
      {"exc", "<No exception>"}};
  if (exception.has_value()) {
    placeholderMapping["exc"] = GetExceptionName(exception.value());
  }

  // Replace placeholders
  dump_text = absl::StrReplaceAll(dump_text, {{"%time%", now_text}});

  for (const auto& [name, value] : registerMapping) {
    std::string name_placeholder = fmt::format("%{}%", name);

    std::visit([&dump_text, name_placeholder](auto&& arg) {
      dump_text = absl::StrReplaceAll(dump_text, {{name_placeholder, std::to_string(*std::forward<decltype(arg)>(arg))}});
    },
               value);
  }
  for (const auto& [name, value] : placeholderMapping) {
    std::string name_placeholder = fmt::format("%{}%", name);

    std::visit([&dump_text, name_placeholder](auto&& arg) {
      dump_text = absl::StrReplaceAll(dump_text, {{name_placeholder, std::forward<decltype(arg)>(arg)}});
    },
               value);
  }
  fmt::println("{}", dump_text);

  // Write to file
  const std::string output("hcpu_dump.txt");
  std::ofstream file(output, std::ios::app);
  if (!file.is_open()) {
    fmt::println("{}: open failed", output);
    return {};
  }

  file << dump_text;

  file.close();
  fmt::println("(This dump has been written to hcpu_dump.txt)");

  return dump_text;
}

std::string HyperCPU::Dumper::GetExceptionName(std::uint64_t index) {
  switch (index) {
  case static_cast<std::uint64_t>(HyperCPU::cpu_exceptions::IA):
    return "IA <InvalidAccess>";
  case static_cast<std::uint64_t>(HyperCPU::cpu_exceptions::IO):
    return "IO <InvalidOpcode>";
  case static_cast<std::uint64_t>(HyperCPU::cpu_exceptions::ZRDIV):
    return "ZRDIV <ZeroDivision>";
  case static_cast<std::uint64_t>(HyperCPU::cpu_exceptions::SEGF):
    return "SEGF";
  default:
    return fmt::format("{} <Undocumented>", index);
  }
}

std::string HyperCPU::Dumper::GetExceptionName(HyperCPU::cpu_exceptions exception) {
  return GetExceptionName(static_cast<std::uint64_t>(exception));
}
