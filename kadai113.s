	.global itoa10
	.align 2
	
itoa10:
	bltz a0, label4
	beqz a0, label5
	mv a2, a0
	li a3, 0
	li a4, 1
	li a5, 10
label0:
	blez a2, label1
	div a2, a2, a5
	addi a3, a3, 1
	mul a4, a4, a5
	j label0
label1:
	div a4, a4, a5
	li a6, 0
	mv a2, a1
label2:
	bge a6, a3, label3
	div a7, a0, a4
	rem a7, a7, a5
	addi a7, a7, 48
	sb a7, 0(a2)
	div a4, a4, a5
	addi a2, a2, 1
	addi a6, a6, 1
	j label2
label3:
	li a7, 0
	sb a7, 0(a2)
	mv a0, a1
	ret 
label4:
	li a2, 45
	sb a2, 0(a1)
	addi a1, a1, 1
	li a2, 0
	sub a0, a2, a0
	addi sp, sp, -16
	sd ra, 0(sp)
	jal itoa10
	ld ra, 0(sp)
	addi sp, sp, 16
	addi a0, a0, -1
	ret
label5:
	li a2, 48
	sb a2, 0(a1)
	li a2, 0
	sb a2, 1(a1)
	mv a0, a1
	ret 
	
