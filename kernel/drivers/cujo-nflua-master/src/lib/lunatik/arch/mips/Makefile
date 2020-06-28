ifeq ($(CONFIG_64BIT),y)
	ifeq ($(CONFIG_MIPS32_N32),y)
		# 64-bit ISA, 32-bit pointers.
		AFLAGS_setjmp.o = -D_CUJO -D__mips_n32 -D_MIPS_ISA_MIPS64 \
			-D_MIPS_ISA=_MIPS_ISA_MIPS64
	else
		# 64-bit ISA, 64-bit pointers.
		AFLAGS_setjmp.o = -D_CUJO -D__mips_n64 -D_MIPS_ISA_MIPS64 \
			-D_MIPS_ISA=_MIPS_ISA_MIPS64
	endif
else
	# 32-bit ISA, 32-bit pointers.
	AFLAGS_setjmp.o = -D_CUJO -D__mips_o32 -D_MIPS_ISA_MIPS32 \
		-D_MIPS_ISA=_MIPS_ISA_MIPS32
endif
obj-y += setjmp.o
