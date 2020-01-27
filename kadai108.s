	.global maxof3
	.align 2
maxof3:
	addi sp, sp, -16
	sd ra, 8(sp)
	sw a2, 0(sp)
	jal maxof2
	ld ra, 8(sp)
	lw a1, 0(sp)
	addi sp, sp, 16
	addi sp, sp, -16
	sd ra, 8(sp)
	jal maxof2
	ld ra, 8(sp)
	addi sp, sp, 16
	ret 
	
	
