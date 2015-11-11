//Original:/testcases/core/c_dsp32mac_dr_a1/c_dsp32mac_dr_a1.dsp
// Spec Reference: dsp32mac dr_a1
# mach: bfin

.include "testutils.inc"
	start



A1 = A0 = 0;

// The result accumulated in A1 , and stored to a reg half
imm32 r0, 0x13545abd;
imm32 r1, 0xadbcfec7;
imm32 r2, 0xa1245679;
imm32 r3, 0x00060007;
imm32 r4, 0xefbc4569;
imm32 r5, 0x1235000b;
imm32 r6, 0x000c000d;
imm32 r7, 0x678e000f;
R0.H = ( A1 += R1.L * R0.L ), A0 = R1.L * R0.L;
R1 = A1.w;
R2.H = ( A1 = R2.L * R3.L ), A0 = R2.H * R3.L;
R3 = A1.w;
R4.H = ( A1 = R4.L * R5.L ), A0 += R4.H * R5.H;
R5 = A1.w;
R6.H = ( A1 += R6.L * R7.L ), A0 += R6.L * R7.H;
R7 = A1.w;
CHECKREG r0, 0xFF225ABD;
CHECKREG r1, 0xFF221DD6;
CHECKREG r2, 0x00055679;
CHECKREG r3, 0x0004BA9E;
CHECKREG r4, 0x00064569;
CHECKREG r5, 0x0005F706;
CHECKREG r6, 0x0006000D;
CHECKREG r7, 0x0005F88C;

imm32 r0, 0x13545abd;
imm32 r1, 0xa1bcfec7;
imm32 r2, 0xa1145679;
imm32 r3, 0x00010007;
imm32 r4, 0xefbc1569;
imm32 r5, 0x1235010b;
imm32 r6, 0x000c001d;
imm32 r7, 0x678e0001;
R4.H = ( A1 += R1.L * R0.H ), A0 = R1.L * R0.L;
R5 = A1.w;
R0.H = ( A1 = R2.L * R3.H ), A0 = R2.H * R3.L;
R1 = A1.w;
R2.H = ( A1 = R4.L * R5.H ), A0 += R4.H * R5.H;
R3 = A1.w;
R6.H = ( A1 += R6.L * R7.H ), A0 += R6.L * R7.H;
R7 = A1.w;
CHECKREG r0, 0x00015ABD;
CHECKREG r1, 0x0000ACF2;
CHECKREG r2, 0xFFF95679;
CHECKREG r3, 0xFFF8F98C;
CHECKREG r4, 0xFFD71569;
CHECKREG r5, 0xFFD6B524;
CHECKREG r6, 0x0010001D;
CHECKREG r7, 0x00106FB8;

imm32 r0, 0x83545abd;
imm32 r1, 0xa8bcfec7;
imm32 r2, 0xa1845679;
imm32 r3, 0x00080007;
imm32 r4, 0xefbc8569;
imm32 r5, 0x1235080b;
imm32 r6, 0x000c008d;
imm32 r7, 0x678e0008;
R6.H = ( A1 += R1.H * R0.L ), A0 = R1.L * R0.L;
R7 = A1.w;
R2.H = ( A1 = R2.H * R3.L ), A0 = R2.H * R3.L;
R3 = A1.w;
R4.H = ( A1 = R4.H * R5.L ), A0 += R4.H * R5.H;
R5 = A1.w;
R0.H = ( A1 += R6.H * R7.L ), A0 += R6.L * R7.H;
R1 = A1.w;
CHECKREG r0, 0x1B505ABD;
CHECKREG r1, 0x1B4FC2A8;
CHECKREG r2, 0xFFFB5679;
CHECKREG r3, 0xFFFAD538;
CHECKREG r4, 0xFEFA8569;
CHECKREG r5, 0xFEFA5A28;
CHECKREG r6, 0xC234008D;
CHECKREG r7, 0xC233C550;

imm32 r0, 0xc3545abd;
imm32 r1, 0xacbcfec7;
imm32 r2, 0xa1c45679;
imm32 r3, 0x000c0007;
imm32 r4, 0xefbcc569;
imm32 r5, 0x12350c0b;
imm32 r6, 0x000c00cd;
imm32 r7, 0x678e000c;
R6.H = ( A1 += R1.H * R0.H ), A0 = R1.L * R0.L;
R7 = A1.w;
R0.H = ( A1 = R2.H * R3.H ), A0 = R2.H * R3.L;
R1 = A1.w;
R4.H = ( A1 = R4.H * R5.H ), A0 += R4.H * R5.H;
R5 = A1.w;
R2.H = ( A1 += R6.H * R7.H ), A0 += R6.L * R7.H;
R3 = A1.w;
CHECKREG r0, 0xFFF75ABD;
CHECKREG r1, 0xFFF72A60;
CHECKREG r2, 0x20875679;
CHECKREG r3, 0x2086A6C8;
CHECKREG r4, 0xFDB0C569;
CHECKREG r5, 0xFDAFB3D8;
CHECKREG r6, 0x42C800CD;
CHECKREG r7, 0x42C78608;

imm32 r0, 0x01542abd;
imm32 r1, 0x02bc4ec7;
imm32 r2, 0x03240679;
imm32 r3, 0x04061007;
imm32 r4, 0x05bc2569;
imm32 r5, 0x0635300b;
imm32 r6, 0x070c200d;
imm32 r7, 0x088e100f;
R0.H = ( A1 -= R1.L * R0.L ), A0 = R1.L * R0.L;
R1 = A1.w;
R2.H = ( A1 -= R2.L * R3.L ), A0 -= R2.H * R3.L;
R3 = A1.w;
R4.H = ( A1 -= R4.L * R5.L ), A0 += R4.H * R5.H;
R5 = A1.w;
R6.H = ( A1 += R6.L * R7.L ), A0 -= R6.L * R7.H;
R7 = A1.w;
CHECKREG r0, 0x06392ABD;
CHECKREG r1, 0x063908F2;
CHECKREG r2, 0x056A0679;
CHECKREG r3, 0x05698E54;
CHECKREG r4, 0xF75F2569;
CHECKREG r5, 0xF75EF74E;
CHECKREG r6, 0xFB64200D;
CHECKREG r7, 0xFB6458D4;

imm32 r0, 0x03545abd;
imm32 r1, 0x31bcfec7;
imm32 r2, 0x11145679;
imm32 r3, 0x00010007;
imm32 r4, 0xefbc1569;
imm32 r5, 0x1235010b;
imm32 r6, 0x000c001d;
imm32 r7, 0x678e0001;
R4.H = ( A1 += R1.L * R0.H ), A0 -= R1.L * R0.L;
R5 = A1.w;
R0.H = ( A1 -= R2.L * R3.H ), A0 = R2.H * R3.L;
R1 = A1.w;
R2.H = ( A1 -= R4.L * R5.H ), A0 += R4.H * R5.H;
R3 = A1.w;
R6.H = ( A1 += R6.L * R7.H ), A0 -= R6.L * R7.H;
R7 = A1.w;
CHECKREG r0, 0xFB5C5ABD;
CHECKREG r1, 0xFB5B887A;
CHECKREG r2, 0xFC225679;
CHECKREG r3, 0xFC223F02;
CHECKREG r4, 0xFB5C1569;
CHECKREG r5, 0xFB5C356C;
CHECKREG r6, 0xFC3A001D;
CHECKREG r7, 0xFC39B52E;

imm32 r0, 0x83545abd;
imm32 r1, 0xa8bcfec7;
imm32 r2, 0xa1845679;
imm32 r3, 0x00080007;
imm32 r4, 0xefbc8569;
imm32 r5, 0x1235080b;
imm32 r6, 0x000c008d;
imm32 r7, 0x678e0008;
R6.H = ( A1 += R1.H * R0.L ), A0 -= R1.L * R0.L;
R7 = A1.w;
R2.H = ( A1 -= R2.H * R3.L ), A0 -= R2.H * R3.L;
R3 = A1.w;
R4.H = ( A1 = R4.H * R5.L ), A0 -= R4.H * R5.H;
R5 = A1.w;
R0.H = ( A1 += R6.H * R7.L ), A0 -= R6.L * R7.H;
R1 = A1.w;
CHECKREG r0, 0xF9745ABD;
CHECKREG r1, 0xF9741604;
CHECKREG r2, 0xBE625679;
CHECKREG r3, 0xBE62358E;
CHECKREG r4, 0xFEFA8569;
CHECKREG r5, 0xFEFA5A28;
CHECKREG r6, 0xBE5D008D;
CHECKREG r7, 0xBE5D0AC6;

imm32 r0, 0xc3545abd;
imm32 r1, 0xacbcfec7;
imm32 r2, 0xa1c45679;
imm32 r3, 0x000c0007;
imm32 r4, 0xefbcc569;
imm32 r5, 0x12350c0b;
imm32 r6, 0x000c00cd;
imm32 r7, 0x678e000c;
R6.H = ( A1 += R1.H * R0.H ), A0 -= R1.L * R0.L;
R7 = A1.w;
R0.H = ( A1 = R2.H * R3.H ), A0 -= R2.H * R3.L;
R1 = A1.w;
R4.H = ( A1 -= R4.H * R5.H ), A0 += R4.H * R5.H;
R5 = A1.w;
R2.H = ( A1 -= R6.H * R7.H ), A0 += R6.L * R7.H;
R3 = A1.w;
CHECKREG r0, 0xFFF75ABD;
CHECKREG r1, 0xFFF72A60;
CHECKREG r2, 0xF9D05679;
CHECKREG r3, 0xF9D00540;
CHECKREG r4, 0x0247C569;
CHECKREG r5, 0x02477688;
CHECKREG r6, 0x20EC00CD;
CHECKREG r7, 0x20EBD964;

pass
