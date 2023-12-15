MEMORY
{
  ram      (rwx) : ORIGIN = 0x00010000, LENGTH = 0x00100000
}

ENTRY(_entry)
SECTIONS
{
 . = 0x60010000;
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss COMMON) }
 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
 . = . + 0x1000; /* 4kB of irq stack memory */
 irq_stack_top = .;
}
