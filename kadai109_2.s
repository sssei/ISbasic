	.global mystrcat
	.align 2
mystrcat:
	addi sp, sp, -32
 	sd ra, 24(sp)
	sd a0, 16(sp)
	sd a1, 8(sp)
	jal mystrlen
	sw a0, 4(sp)
	ld a0, 8(sp)
	jal mystrlen
	mv a1, a0
	ld a0, 16(sp)
	mv a2, a0
	ld a3, 8(sp)
	lw a4, 4(sp)
	add a2, a2, a4
label3:
	lb a5, 0(a3)
	sb a5, 0(a2)
	addi a2, a2, 1
	addi a3, a3, 1
	addi a1, a1, -1
	beqz a1, label4
	j label3
label4:
	ld ra, 24(sp)	
	addi sp, sp, 32
	ret
