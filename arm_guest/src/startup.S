    .global _entry
_entry:
    ldr sp, =stack_top
    bl c_entry
    b .
