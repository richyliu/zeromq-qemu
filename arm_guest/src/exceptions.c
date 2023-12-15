#include "exceptions.h"

#include <stdint.h>
#include "printf.h"

void __attribute__((interrupt)) undef_handler() {
    puts("undef_handler");
}
void __attribute__((interrupt)) swi_handler() {
    puts("swi_handler");
}
void __attribute__((interrupt)) prefetch_abort_handler() {
    puts("prefetch_abort_handler");
}
void __attribute__((interrupt)) data_abort_handler() {
    puts("data_abort_handler");
}
void __attribute__((interrupt)) fiq_handler() {
    puts("fiq_handler");
}

void __attribute__((interrupt("IRQ"))) irq_handler() {
    puts("received IRQ");
}

void copy_vectors() {
  extern uint32_t vectors_start;
  extern uint32_t vectors_end;
  uint32_t *vectors_src = &vectors_start;
  uint32_t *vectors_dst = (uint32_t *)0;

  while (vectors_src < &vectors_end)
    *vectors_dst++ = *vectors_src++;
}
