MEMORY
{
  ram      (rwx) : ORIGIN = 0x00010000, LENGTH = 0x00100000
}

ENTRY(_entry)
SECTIONS
{
 . = 0x60010000;
 .startup : { src/startup.o(.text) }
 .text : { *(.text) }
 .data : { *(.data) }
 .bss : { *(.bss COMMON) }
 . = ALIGN(8);
 . = . + 0x10000; /* 64kB of stack memory */
 stack_top = .;
}
