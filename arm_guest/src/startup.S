    .text
    .code 32

    .section .vector_table, "ax"
    .global _Reset
_Reset:
    LDR PC, reset_handler_addr
    LDR PC, undef_handler_addr
    LDR PC, swi_handler_addr
    LDR PC, prefetch_abort_handler_addr
    LDR PC, data_abort_handler_addr
    B .
    LDR PC, irq_handler_addr
    LDR PC, fiq_handler_addr

reset_handler_addr: .word reset_handler
undef_handler_addr: .word undef_handler
swi_handler_addr: .word swi_handler
prefetch_abort_handler_addr: .word prefetch_abort_handler
data_abort_handler_addr: .word data_abort_handler
irq_handler_addr: .word irq_handler
fiq_handler_addr: .word fiq_handler

    .section .text

reset_handler:
    /* set Supervisor stack */
    LDR sp, =stack_top
    /* get Program Status Register */
    MRS r0, cpsr
    /* go in IRQ mode */
    BIC r1, r0, #0x1F
    ORR r1, r1, #0x12
    MSR cpsr, r1
    /* set IRQ stack */
    LDR sp, =irq_stack_top
    /* Enable IRQs */
    BIC r0, r0, #0x80
    /* go back in Supervisor mode */
    MSR cpsr, r0
    /* jump to main */
    BL c_entry
    B .

    .end
