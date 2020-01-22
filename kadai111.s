	.global add128
	.align 2
add128:
	ld a3, 0(a0)
	ld a4, 0(a1)
	add a5, a3, a4
	sd a5, 0(a2)
	slt a6, a5, a3
	ld a3, 8(a0)
	ld a4, 8(a1)
	add a5, a3, a6
	add a5, a5, a4
	sd a5, 8(a2)
	ret 
