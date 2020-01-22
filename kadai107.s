	.global mystrcmp
	.align 2
mystrcmp:
	mv a2, a1
	mv a1, a0
label1:
	lb a3, 0(a1)
	lb a4, 0(a2)
	sub a0, a3, a4
	beqz a3, label2
	addi a1, a1, 1
	addi a2, a2, 1
	beqz a0, label1
	j label2
label2:
	ret
