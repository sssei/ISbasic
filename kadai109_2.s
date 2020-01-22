	.global mystrcat
	.align 2
mystrcat:
	addi sp, sp, -32
 	sd ra, 24(sp)
	sb a0, 20(sp)
	sb a1, 16(sp)
	jal mystrlen
	sw a0, 12(sp)
	lb a0, 20(sp)
	jal mystrlen
	mv a1, a0
	lb a0, 20(sp)
	mv a2, a0
	lb a3, 16(sp)
	lw a4, 12(sp)
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
