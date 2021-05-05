mov r2,#0ah
mov r3,#00h
mov r4,#00h
mov dptr,#0000h
again: movx a,@dptr
rrc a
jc odd
inc r3
sjmp ahead
odd: inc r4
ahead: inc dptr
djnz r2,again
mov a,r3
mov dptr,#0010h
movx @dptr,a
mov a,r4
inc dptr
movx @dptr,a
ret