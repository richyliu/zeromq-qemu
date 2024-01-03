MEMORY
{
  rom      (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00010000
  ram      (rwx) : ORIGIN = 0x00010000, LENGTH = 0x00100000
}

PHDRS
{
  text PT_LOAD ;
  rodata PT_LOAD ;
  vector_table PT_LOAD ;
}

ENTRY(_Reset)
SECTIONS
{
 .vector_table 0x0 : { *(.vector_table) } :vector_table
 .text 0x00010000 : { *(.text) } :text
 .data : AT (ADDR(.text) + SIZEOF(.text)) { *(.data) } :text
 .bss : AT (ADDR(.data) + SIZEOF(.data)) { *(.bss COMMON) } :text
 .rodata 0x00020000 : { *(.rodata*) *(.ARM.extab) } :rodata
 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
 . = . + 0x1000; /* 4kB of irq stack memory */
 irq_stack_top = .;

 /DISCARD/ : { *(.ARM.exidx) }

}
