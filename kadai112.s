	.global dot
	.align 2
dot:
	fld fa0, 0(a1)
	fsub.d fa0, fa0, fa0
label1:	
	beqz a0, label2
	fld fa1, 0(a1)
	fld fa2, 0(a2)
	fmul.d fa3, fa1, fa2
	fadd.d fa0, fa0, fa3
	addi a1, a1, 8
	addi a2, a2, 8
	addi a0, a0, -1
	j label1
label2:
	ret
