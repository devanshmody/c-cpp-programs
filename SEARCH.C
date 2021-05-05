mov r3,#00h
mov r2,#0ah
mov dptr,#0000h
movx a,@dptr
mov b,a
mov dptr,#0010h
push dph
push dpl
mov dptr,#0020h
back: movx a,@dptr
cjne a,0f0h, ahead
inc r3
mov r0,dph
mov r1,dpl
pop dpl
pop dph
mov a,r0
movx @dptr,a
inc dptr
mov a,r1
movx @dptr,a
inc dptr
push dph
push dpl
mov dph,r0
mov dpl,r1
ahead: inc dptr
djnz r2,back
mov a,r3
mov dptr,#0030h
movx @dptr,a
ret