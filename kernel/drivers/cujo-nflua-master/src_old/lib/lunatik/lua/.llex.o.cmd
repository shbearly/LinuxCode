cmd_/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o := /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/sysroots/x86_64-linux/usr/bin/cortexa15hf-vfp-neon-rdk-linux-gnueabi/arm-rdk-linux-gnueabi-gcc -Wp,-MD,/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/.llex.o.d  -nostdinc -isystem /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/sysroots/x86_64-linux/usr/lib/cortexa15hf-vfp-neon-rdk-linux-gnueabi/gcc/arm-rdk-linux-gnueabi/4.8.4/include -I/home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi -Iinclude/generated/uapi -include /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -fno-dwarf2-cfi-asm -mabi=aapcs-linux -mno-thumb-interwork -mfpu=vfp -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -femit-struct-debug-baseonly -fno-var-tracking -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -DCC_HAVE_ASM_GOTO -D_KERNEL -I/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua -I/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/ -I/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/luadata/ -D'CHAR_BIT=(8)' -D'MIN=min' -D'MAX=max' -D'UCHAR_MAX=(255)' -D'UINT64_MAX=((u64)~0ULL)' -Dstrtoll=simple_strtoll  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(llex)"  -c -o /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/.tmp_llex.o /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.c

source_/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o := /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.c

deps_/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o := \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lprefix.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lua.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/sysroots/x86_64-linux/usr/lib/cortexa15hf-vfp-neon-rdk-linux-gnueabi/gcc/arm-rdk-linux-gnueabi/4.8.4/include/stdarg.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/luaconf.h \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/linkage.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/uapi/linux/types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/linux/posix_types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/posix_types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/asm-generic/posix_types.h \
  include/linux/bitops.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/bitops.h \
    $(wildcard include/config/smp.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/irqflags.h \
    $(wildcard include/config/cpu/v7m.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/hwcap.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/hwcap.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/uapi/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/swab.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/printk.h \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
  include/linux/kern_levels.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/uapi/linux/kernel.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/linux/sysinfo.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/cache.h \
    $(wildcard include/config/arm/l1/cache/shift.h) \
    $(wildcard include/config/aeabi.h) \
  include/linux/dynamic_debug.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/div64.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/compiler.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/bug.h \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/debug/bugverbose.h) \
    $(wildcard include/config/arm/lpae.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/opcodes.h \
    $(wildcard include/config/cpu/endian/be32.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  include/generated/uapi/linux/version.h \
  include/linux/ctype.h \
  include/linux/random.h \
    $(wildcard include/config/arch/random.h) \
  include/uapi/linux/random.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/linux/ioctl.h \
  arch/arm/include/generated/asm/ioctl.h \
  include/asm-generic/ioctl.h \
  include/uapi/asm-generic/ioctl.h \
  include/linux/irqnr.h \
  include/uapi/linux/irqnr.h \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/seqlock.h \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/context/tracking.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/linux/const.h \
  arch/arm/include/generated/asm/preempt.h \
  include/asm-generic/preempt.h \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  include/linux/bug.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/crunch.h) \
    $(wildcard include/config/arm/thumbee.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  include/linux/bottom_half.h \
  include/linux/preempt_mask.h \
  include/linux/spinlock_types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/spinlock.h \
  include/linux/prefetch.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/processor.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
    $(wildcard include/config/arm/errata/754327.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/hw_breakpoint.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/atomic.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/cmpxchg.h \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/atomic-long.h \
  include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  include/uapi/linux/time.h \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/uapi/linux/timex.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/linux/param.h \
  arch/arm/include/generated/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  include/uapi/asm-generic/param.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/timex.h \
    $(wildcard include/config/arch/multiplatform.h) \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  include/uapi/linux/string.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/string.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/cma.h) \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/wait.h \
  arch/arm/include/generated/asm/current.h \
  include/asm-generic/current.h \
  include/uapi/linux/wait.h \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/nodemask.h \
    $(wildcard include/config/movable/node.h) \
  include/linux/bitmap.h \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/linux/page-flags-layout.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  include/generated/bounds.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/kuser/helpers.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/glue.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/pgtable-3level-types.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/memory.h \
    $(wildcard include/config/need/mach/memory/h.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/phys/offset.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/virt/to/bus.h) \
  include/linux/sizes.h \
  include/asm-generic/memory_model.h \
  include/asm-generic/getorder.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  include/linux/notifier.h \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/arm/include/generated/asm/errno.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/asm-generic/errno.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/include/uapi/asm-generic/errno-base.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/mutex/spin/on/owner.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/user/qs.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/no/hz/full/sysidle.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/completion.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/rcutree.h \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/smp.h \
  include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/smp.h \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/pfn.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/percpu.h \
  include/asm-generic/percpu.h \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/asm/topology.h \
    $(wildcard include/config/arm/cpu/topology.h) \
  include/asm-generic/topology.h \
  include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  include/linux/slub_def.h \
    $(wildcard include/config/slub/stats.h) \
    $(wildcard include/config/memcg/kmem.h) \
  include/linux/kobject.h \
    $(wildcard include/config/debug/kobject/release.h) \
  include/linux/sysfs.h \
  include/linux/kernfs.h \
  include/linux/err.h \
  include/linux/idr.h \
  include/linux/rbtree.h \
  include/linux/kobject_ns.h \
  include/linux/stat.h \
  /home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux/arch/arm/include/uapi/asm/stat.h \
  include/uapi/linux/stat.h \
  include/linux/uidgid.h \
    $(wildcard include/config/user/ns.h) \
  include/linux/highuid.h \
  include/linux/kref.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lctype.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llimits.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/ldebug.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lstate.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lobject.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/ltm.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lzio.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lmem.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/ldo.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lgc.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lparser.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/lstring.h \
  /home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/ltable.h \

/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o: $(deps_/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o)

$(deps_/home/yanli/cga4233tca/cujo/cujo-nflua-master/src/lib/lunatik/lua/llex.o):
