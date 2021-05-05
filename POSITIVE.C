mov r0,#0ah
mov r1,#00h
mov r2,#00h
mov r3,#00h

mov dptr,#0000h
again: movx a,@dptr
jnz neg
inc r3;  zero
sjmp ahead

neg: rlc a
jnc pos
inc r2;    -tive
sjmp ahead
pos: inc r1;    +tive
ahead: inc dptr
djnz r0,again
mov dptr,#0010h
mov a,r1
movx @dptr,a
inc dptr
mov a,r2
movx @dptr,a
inc dptr
mov a,r3
movx @dptr,a
inc dptr
ret
