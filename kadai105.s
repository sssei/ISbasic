	.global swap_gt
	.align 2
swap_gt:
	lw a2, 0(a0)
	lw a3, 0(a1)
	ble a3, a2, label1
	j label2
label1:
	sw a3, 0(a0)
	sw a2, 0(a1)
	ret
label2:
	ret
	
