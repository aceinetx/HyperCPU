#include <mapbox/eternal.hpp>

#include <emulator/core/cpu/instructions/registers.hpp>

using namespace mapbox::eternal;

static const auto register_assoc = mapbox::eternal::hash_map<mapbox::eternal::string, hypercpu::registers>({
    {"x0", hypercpu::registers::X0},
    {"x1", hypercpu::registers::X1},
    {"x2", hypercpu::registers::X2},
    {"x3", hypercpu::registers::X3},
    {"x4", hypercpu::registers::X4},
    {"x5", hypercpu::registers::X5},
    {"x6", hypercpu::registers::X6},
    {"x7", hypercpu::registers::X7},
    {"xh0", hypercpu::registers::XH0},
    {"xh1", hypercpu::registers::XH1},
    {"xh2", hypercpu::registers::XH2},
    {"xh3", hypercpu::registers::XH3},
    {"xh4", hypercpu::registers::XH4},
    {"xh5", hypercpu::registers::XH5},
    {"xh6", hypercpu::registers::XH6},
    {"xh7", hypercpu::registers::XH7},
    {"xl0", hypercpu::registers::XL0},
    {"xl1", hypercpu::registers::XL1},
    {"xl2", hypercpu::registers::XL2},
    {"xl3", hypercpu::registers::XL3},
    {"xl4", hypercpu::registers::XL4},
    {"xl5", hypercpu::registers::XL5},
    {"xl6", hypercpu::registers::XL6},
    {"xl7", hypercpu::registers::XL7},
    {"xll0", hypercpu::registers::XLL0},
    {"xll1", hypercpu::registers::XLL1},
    {"xll2", hypercpu::registers::XLL2},
    {"xll3", hypercpu::registers::XLL3},
    {"xllh0", hypercpu::registers::XLLH0},
    {"xllh1", hypercpu::registers::XLLH1},
    {"xllh2", hypercpu::registers::XLLH2},
    {"xllh3", hypercpu::registers::XLLH3},
    {"xlll0", hypercpu::registers::XLLL0},
    {"xlll1", hypercpu::registers::XLLL1},
    {"xlll2", hypercpu::registers::XLLL2},
    {"xlll3", hypercpu::registers::XLLL3},
    {"xbp", hypercpu::registers::XBP},
    {"xsp", hypercpu::registers::XSP},
    {"xip", hypercpu::registers::XIP},
    {"xgdp", hypercpu::registers::XGDP},
    {"xivt", hypercpu::registers::XIVT}
});