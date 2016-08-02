#pragma once

const uint16_t larson_scanner_program[] = {
  SET_SP,

  // set PA out
  0x10, LXI_H,
  0x11, 0x00,
  0x12, 0x01,
  0x13, MVI_M,
  0x14, 0x01,

  //
  0x15, MVI_A,
  0x16, 0x01,

  // set PA high
  0x17, LXI_H,
  0x18, 0x01,
  0x19, 0x01,

  // set output
  0x1a, MOV_M_A,
  0x1b, RAL,

  // delay
  0x1c, CALL,
  0x1d, 0xd0,
  0x1e, 0x00,

  // loop
  0x1f, JMP,
  0x20, 0x1a,
  0x21, 0x00,

  // delay
  0xc0, MVI_C,
  0xc1, 0xff,
  0xc2, DCR_C,
  0xc3, JNZ,
  0xc4, 0xc2,
  0xc5, 0x00,
  0xc6, RET,

  // long delay
  0xd0, MVI_B,
  0xd1, 0x0f,
  0xd2, CALL,
  0xd3, 0xc0,
  0xd4, 0x00,
  0xd5, DCR_B,
  0xd6, JNZ,
  0xd7, 0xd2,
  0xd8, 0x00,
  0xd9, RET,
};
