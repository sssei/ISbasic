	.global maxof2
	.align 2
maxof2: ble a1, a0, label
	mv a0, a1
label:	ret
