#pragma once

const uint16_t blink_program[] = {
  0x00, LXI_SP,
  0x01, 0x00,
  0x02, 0x10,
  0x03, JMP,
  0x04, 0x44,
  0x05, 0x00,

  0x44, LXI_H,
  0x45, 0xff,
  0x46, 0xff,

  0x47, MVI_A,
  0x48, 0b01000000,
  0x49, SIM,
  0x4a, CALL,
  0x4b, 0x70,
  0x4c, 0x00,

  0x4d, MVI_A,
  0x4e, 0b11000000,
  0x4f, SIM,
  0x50, CALL,
  0x51, 0x70,
  0x52, 0x00,

  0x53, JMP,
  0x54, 0x47,
  0x55, 0x00,

  // variable delay
  0x70, PUSH_PSW,
  0x71, PUSH_H,
  0x72, DCX_H,
  0x73, MVI_A,
  0x74, 0x00,
  0x75, ORA_L,
  0x76, JNZ,
  0x77, 0x72,
  0x78, 0x00,
  0x79, ORA_H,
  0x7a, JNZ,
  0x7b, 0x72,
  0x7c, 0x00,
  0x7d, POP_H,
  0x7e, POP_PSW,
  0x7f, RET,
};