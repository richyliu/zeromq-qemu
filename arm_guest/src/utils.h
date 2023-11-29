#ifndef UTILS_H_
#define UTILS_H_

#define ONE_SECOND 500000
void delay(const int milliseconds);

#define HWREG8(x) (*((volatile unsigned char *)(x)))
#define HWREG16(x) (*((volatile unsigned short *)(x)))
#define HWREG32(x) (*((volatile unsigned int *)(x)))

#endif // UTILS_H_
