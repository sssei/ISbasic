	.global fact
	.align 2
fact:
	beqz a0, label
	addi sp, sp, -16
	sd ra, 8(sp)
	sw a0, 0(sp)
	addi a0, a0, -1
	jal fact
	ld ra, 8(sp)
	lw a1, 0(sp)
	addi sp, sp, 16
	mul a0, a0, a1
	ret 
label:
	li a0, 1
	ret
