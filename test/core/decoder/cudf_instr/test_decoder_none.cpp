#include <gtest/gtest.h>

#include <cstring>

#include <fixtures.hpp>

TEST_F(decoder_test, CUDF_INSTR_NONE) {
  decoder.mem_controller->load16(counter, hypercpu::CUDF);
  counter += 2;
  decoder.mem_controller->load8(counter, hypercpu::operand_types::NONE);
  counter = 0;
  
  hypercpu::i_instruction instr = decoder.fetch_and_decode();

  ASSERT_EQ(instr.m_opcode, hypercpu::opcode::CUDF);
  ASSERT_EQ(instr.m_op_types, hypercpu::operand_types::NONE);
}