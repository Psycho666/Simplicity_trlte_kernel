cmd_arch/arm/lib/csumpartial.o := /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/arm-cortex_a15-linux-gnueabihf-gcc -Wp,-MD,arch/arm/lib/.csumpartial.o.d  -nostdinc -isystem /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/../lib/gcc/arm-cortex_a15-linux-gnueabihf/4.9.1/include -I/home/justin/android/pok1/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/justin/android/pok1/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/justin/android/pok1/include/uapi -Iinclude/generated/uapi -include /home/justin/android/pok1/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include  -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -mcpu=cortex-a15  -include asm/unified.h -msoft-float -gdwarf-2         -c -o arch/arm/lib/csumpartial.o arch/arm/lib/csumpartial.S

source_arch/arm/lib/csumpartial.o := arch/arm/lib/csumpartial.S

deps_arch/arm/lib/csumpartial.o := \
  /home/justin/android/pok1/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/justin/android/pok1/arch/arm/include/asm/linkage.h \
  /home/justin/android/pok1/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  /home/justin/android/pok1/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /home/justin/android/pok1/arch/arm/include/asm/hwcap.h \
  /home/justin/android/pok1/arch/arm/include/uapi/asm/hwcap.h \
  /home/justin/android/pok1/arch/arm/include/asm/domain.h \
    $(wildcard include/config/verify/permission/fault.h) \
    $(wildcard include/config/io/36.h) \
  /home/justin/android/pok1/arch/arm/include/asm/opcodes-virt.h \
  /home/justin/android/pok1/arch/arm/include/asm/opcodes.h \
    $(wildcard include/config/cpu/endian/be32.h) \

arch/arm/lib/csumpartial.o: $(deps_arch/arm/lib/csumpartial.o)

$(deps_arch/arm/lib/csumpartial.o):
