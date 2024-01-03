#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

// PL190 VIC primary interrupt controller
#define VIC_BASE_ADDR 0x10140000
#define VIC_INTENABLE(x) (HWREG32(VIC_BASE_ADDR + 0x10) = x)
#define VIC_GPIO0 (1 << 6)

void __attribute__((interrupt)) undef_handler();
void __attribute__((interrupt)) swi_handler();
void __attribute__((interrupt)) prefetch_abort_handler();
void __attribute__((interrupt)) data_abort_handler();
void __attribute__((interrupt)) irq_handler();
void __attribute__((interrupt)) fiq_handler();

#endif // EXCEPTIONS_H_
