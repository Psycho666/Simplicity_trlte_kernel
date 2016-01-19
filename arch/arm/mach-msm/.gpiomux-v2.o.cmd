cmd_arch/arm/mach-msm/gpiomux-v2.o := /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/arm-cortex_a15-linux-gnueabihf-gcc -Wp,-MD,arch/arm/mach-msm/.gpiomux-v2.o.d  -nostdinc -isystem /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/../lib/gcc/arm-cortex_a15-linux-gnueabihf/4.9.1/include -I/home/justin/android/pok1/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/justin/android/pok1/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/justin/android/pok1/include/uapi -Iinclude/generated/uapi -include /home/justin/android/pok1/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -fno-dwarf2-cfi-asm -fstack-protector -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -mcpu=cortex-a15 -msoft-float -Uarm -Wframe-larger-than=1024 -Wno-unused-but-set-variable -fomit-frame-pointer -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(gpiomux_v2)"  -D"KBUILD_MODNAME=KBUILD_STR(gpiomux_v2)" -c -o arch/arm/mach-msm/.tmp_gpiomux-v2.o arch/arm/mach-msm/gpiomux-v2.c

source_arch/arm/mach-msm/gpiomux-v2.o := arch/arm/mach-msm/gpiomux-v2.c

deps_arch/arm/mach-msm/gpiomux-v2.o := \
  include/linux/bitops.h \
  arch/arm/include/generated/asm/types.h \
  /home/justin/android/pok1/include/uapi/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \
  /home/justin/android/pok1/arch/arm/include/asm/bitops.h \
    $(wildcard include/config/smp.h) \
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
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  include/linux/typecheck.h \
  /home/justin/android/pok1/arch/arm/include/asm/irqflags.h \
  /home/justin/android/pok1/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /home/justin/android/pok1/arch/arm/include/asm/hwcap.h \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/hwcap.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  include/uapi/linux/types.h \
  /home/justin/android/pok1/include/uapi/linux/posix_types.h \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/posix_types.h \
  /home/justin/android/pok1/include/uapi/asm-generic/posix_types.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/lock.h \
  include/asm-generic/bitops/le.h \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/uapi/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  /home/justin/android/pok1/arch/arm/include/asm/swab.h \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/swab.h \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/io.h \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/has/ioport.h) \
  /home/justin/android/pok1/arch/arm/include/asm/io.h \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/need/mach/io/h.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/pcmcia/soc/common.h) \
    $(wildcard include/config/isa.h) \
    $(wildcard include/config/pccard.h) \
  /home/justin/android/pok1/arch/arm/include/asm/memory.h \
    $(wildcard include/config/need/mach/memory/h.h) \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/have/tcm.h) \
    $(wildcard include/config/arm/patch/phys/virt.h) \
    $(wildcard include/config/phys/offset.h) \
    $(wildcard include/config/virt/to/bus.h) \
  /home/justin/android/pok1/include/uapi/linux/const.h \
  include/linux/sizes.h \
  arch/arm/mach-msm/include/mach/memory.h \
    $(wildcard include/config/cache/l2x0.h) \
    $(wildcard include/config/arch/msm/scorpion.h) \
    $(wildcard include/config/arch/msm/krait.h) \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  include/linux/msm_rtb.h \
    $(wildcard include/config/msm/rtb.h) \
  /home/justin/android/pok1/arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arch/has/barriers.h) \
  /home/justin/android/pok1/arch/arm/include/asm/outercache.h \
    $(wildcard include/config/outer/cache/sync.h) \
    $(wildcard include/config/outer/cache.h) \
  arch/arm/mach-msm/include/mach/io.h \
  /home/justin/android/pok1/arch/arm/include/asm/page.h \
    $(wildcard include/config/cpu/copy/v4wt.h) \
    $(wildcard include/config/cpu/copy/v4wb.h) \
    $(wildcard include/config/cpu/copy/feroceon.h) \
    $(wildcard include/config/cpu/copy/fa.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/copy/v6.h) \
    $(wildcard include/config/kuser/helpers.h) \
    $(wildcard include/config/arm/lpae.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/memory/hotplug/sparse.h) \
  /home/justin/android/pok1/arch/arm/include/asm/glue.h \
  /home/justin/android/pok1/arch/arm/include/asm/pgtable-2level-types.h \
  include/asm-generic/getorder.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  arch/arm/mach-msm/include/mach/msm_iomap.h \
    $(wildcard include/config/debug/msm/uart1.h) \
    $(wildcard include/config/debug/msm/uart2.h) \
    $(wildcard include/config/debug/msm/uart3.h) \
    $(wildcard include/config/msm/debug/uart/phys.h) \
  arch/arm/include/generated/asm/sizes.h \
  include/asm-generic/sizes.h \
  arch/arm/mach-msm/include/mach/msm_iomap-8974.h \
    $(wildcard include/config/debug/msm8974/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-8084.h \
    $(wildcard include/config/debug/apq8084/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-8092.h \
    $(wildcard include/config/debug/mpq8092/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-8916.h \
    $(wildcard include/config/debug/msm8916/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-8226.h \
    $(wildcard include/config/debug/msm8226/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-8610.h \
    $(wildcard include/config/debug/msm8610/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-9630.h \
  arch/arm/mach-msm/include/mach/msm_iomap-fsm9900.h \
    $(wildcard include/config/debug/fsm9900/uart.h) \
  arch/arm/mach-msm/include/mach/msm_iomap-samarium.h \
    $(wildcard include/config/debug/msmsamarium/uart.h) \
  arch/arm/mach-msm/include/mach/gpiomux.h \
    $(wildcard include/config/msm/gpiomux.h) \
    $(wildcard include/config/sec/pm/debug.h) \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  arch/arm/include/generated/asm/errno.h \
  /home/justin/android/pok1/include/uapi/asm-generic/errno.h \
  /home/justin/android/pok1/include/uapi/asm-generic/errno-base.h \

arch/arm/mach-msm/gpiomux-v2.o: $(deps_arch/arm/mach-msm/gpiomux-v2.o)

$(deps_arch/arm/mach-msm/gpiomux-v2.o):
