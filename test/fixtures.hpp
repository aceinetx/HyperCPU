#pragma once

#include <unistd.h>
#include <pch.hpp>

#define private public
#include <Core/MemoryController/MemoryControllerST.hpp>
#include <Core/CPU/Instructions/Registers.hpp>
#include <Core/CPU/Instructions/Opcodes.hpp>
#include <Core/CPU/Decoders/StdDecoder.hpp>
#include <Core/CPU/Instructions/Flags.hpp>
#include <Core/CPU/Decoders/IDecoder.hpp>
#include <Assembler/Core/Compiler.hpp>
#include <Logger/Logger.hpp>
#include <Core/CPU/CPU.hpp>


static constexpr std::uint64_t MEM_SIZE = 4096;
static constexpr std::uint64_t MEM_FIXTURE_MEM_SIZE = 1024;
static constexpr std::uint64_t MEM_PTR = 0x0102030405060708;

class TempDir {
public:
  TempDir(const char* test_name)  {
    dir_name = "test_";
    dir_name += test_name;
    std::filesystem::create_directory(dir_name);
    [[maybe_unused]] auto t = chdir(dir_name.c_str());
  }

  ~TempDir() {
    [[maybe_unused]] auto t = chdir("..");
    try {
      std::filesystem::remove_all(dir_name);
    } catch (std::filesystem::filesystem_error&) { }
  }
private:
  std::string dir_name;
};

class MC_ST_TEST : public testing::Test {
  protected:
    HyperCPU::MemoryControllerST mcmt;
    char tmp_buffer[MEM_FIXTURE_MEM_SIZE];
    std::uint64_t counter;
    MC_ST_TEST() : mcmt(MEM_FIXTURE_MEM_SIZE), counter(0) {
      std::memset(tmp_buffer, 0x55, MEM_FIXTURE_MEM_SIZE);
    }
};

class MC_ST_FAILTEST : public testing::Test {
  protected:
    HyperCPU::MemoryControllerST mcmt;
    char tmp_buffer[MEM_FIXTURE_MEM_SIZE];
    std::uint64_t counter;
    MC_ST_FAILTEST() : mcmt(MEM_FIXTURE_MEM_SIZE), counter(LONG_MAX) {
      std::memset(tmp_buffer, 0x55, MEM_FIXTURE_MEM_SIZE);
    }
};

class MC_ST_NEARFAILTEST : public testing::Test {
  protected:
    HyperCPU::MemoryControllerST mcmt;
    std::uint64_t counter;
    MC_ST_NEARFAILTEST() : mcmt(MEM_FIXTURE_MEM_SIZE) {}
};

class DECODER_TEST : public ::testing::Test {
protected:
  HyperCPU::Decoder decoder;
  std::uint64_t counter;
  std::unique_ptr<HyperCPU::MemoryControllerST> mem_ctrl;

  DECODER_TEST() = default;

  void SetUp() {
    mem_ctrl = std::make_unique<HyperCPU::MemoryControllerST>(MEM_SIZE);
    decoder = HyperCPU::Decoder(mem_ctrl.get(), &counter, nullptr);
    counter = 0;
  }

  void TearDown() {
    decoder.~Decoder();
  }
};

class CPU_TEST : public ::testing::Test {
protected:
  HyperCPU::Logger logger;
  HyperCPU::CPU cpu;

  CPU_TEST() : logger(HyperCPU::LogLevel::ERROR), cpu(1, 4096) { }
};

class OPERAND_EVAL_TEST : public ::testing::Test {
protected:
  HyperCPU::Logger logger;
  HyperCPU::CPU cpu;
  std::pair<HyperCPU::OperandContainer, HyperCPU::OperandContainer> result;

  OPERAND_EVAL_TEST() : logger(HyperCPU::LogLevel::ERROR), cpu(1, 4096) { }
};

class STACK_TEST : public ::testing::Test {
protected:
  HyperCPU::Logger logger;
  HyperCPU::CPU cpu;

  STACK_TEST() : logger(HyperCPU::LogLevel::ERROR), cpu(1, 4096) {
    *cpu.xbp = 1024;
    *cpu.xsp = 1024;
  }
};

class IVT_INIT_TEST : public ::testing::Test {
protected:
  HyperCPU::Logger logger;
  HyperCPU::CPU cpu;

  IVT_INIT_TEST() : logger(HyperCPU::LogLevel::ERROR), cpu(1, 4096) {

  }
};

class EXCEPTION_TEST : public ::testing::Test {
protected:
  HyperCPU::Logger logger;
  HyperCPU::CPU cpu;

  EXCEPTION_TEST() : logger(HyperCPU::LogLevel::ERROR), cpu(1, 4096) { }

  virtual void SetUp() {
    *cpu.xsp = 512;
    *cpu.xbp = 512;
    *cpu.xivt = 2048;
    cpu.mem_controller->Load64(2048, 1536);
    cpu.mem_controller->Load64(2056, 1536);
    cpu.mem_controller->Load64(2064, 1536);
    cpu.mem_controller->Load64(1536, HyperCPU::Opcode::HALT);
    cpu.mem_controller->Load64(1538, HyperCPU::OperandTypes::NONE);
    cpu.ivt_initialized = true;
  }
};

class ASM_PARSER_TEST : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;
  HCAsm::CompilerState _state;
  pog::Parser<HCAsm::Value>& parser;

  ASM_PARSER_TEST() : compiler(HyperCPU::LogLevel::ERROR), _state(compiler.pool), parser(compiler.parser) {
    parser.set_compiler_state(&_state);
  }
};

class ASM_PARSER_STMT_TEST : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;

  ASM_PARSER_STMT_TEST() : compiler(HyperCPU::LogLevel::ERROR) { }

  virtual void TearDown() {
    HCAsm::current_index = 0;
  }
};

class ASSEMBLER : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;

  ASSEMBLER() : compiler(HyperCPU::LogLevel::ERROR) { }

  virtual void TearDown() {
    HCAsm::current_index = 0;
  }
};

class FULL_ASSEMBLER : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;
  TempDir dir;

  FULL_ASSEMBLER() : compiler(HyperCPU::LogLevel::ERROR), dir(::testing::UnitTest::GetInstance()->current_test_info()->test_case_name()) { }

  virtual void TearDown() {
    HCAsm::current_index = 0;
  }
};

class TWO_OPERANDS_SUCCESS : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;

  TWO_OPERANDS_SUCCESS() : compiler(HyperCPU::LogLevel::ERROR) { }

  virtual void TearDown() {
    HCAsm::current_index = 0;
  }
};

class TWO_OPERANDS_FAILURE : public ::testing::Test {
protected:
  HCAsm::HCAsmCompiler compiler;

  TWO_OPERANDS_FAILURE() : compiler(HyperCPU::LogLevel::ERROR) { }

  virtual void TearDown() {
    HCAsm::current_index = 0;
  }
};
