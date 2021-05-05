mov r2,#0ah
mov dptr,#0000h
again: movx a,@dptr
mov 0f0h,#09h
mov r4,a
div ab
mov a,b
jnz ahead
acall mul
clr c
mov a,r4
subb a,#0c8h
jc ahead
acall div
ahead: inc dptr
djnz r2,again
ret


mul: movx a,@dptr
mov b,#04h
mul ab
movx @dptr,a
ret

div: movx a,@dptr
	mov b,#07h
	div ab
	movx @dptr,a
	ret