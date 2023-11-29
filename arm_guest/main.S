start:
    # mmio base
    ldr r9, =0x090c0000
    ldr r4, [r9, #4]
    str r4, [r9, #0]

    # delay loop
    mov r0, #0x30000000
delay:
    subs r0, r0, #1
    bne delay

    b start
