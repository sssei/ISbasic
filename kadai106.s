	.global fact
	.align 2
fact:
	mv a1, a0
	li a0, 1
label1:
	beqz a1, label2
	mul a0, a0, a1
	addi a1, a1, -1
	j label1
label2:
	ret
	
