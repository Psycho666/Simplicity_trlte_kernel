cmd_firmware/epen/W9012_tr_239.bin.gen.o := /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/arm-cortex_a15-linux-gnueabihf-gcc -Wp,-MD,firmware/epen/.W9012_tr_239.bin.gen.o.d  -nostdinc -isystem /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/../lib/gcc/arm-cortex_a15-linux-gnueabihf/4.9.1/include -I/home/justin/android/pok1/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/justin/android/pok1/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/justin/android/pok1/include/uapi -Iinclude/generated/uapi -include /home/justin/android/pok1/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include  -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -mcpu=cortex-a15  -include asm/unified.h -msoft-float -gdwarf-2         -c -o firmware/epen/W9012_tr_239.bin.gen.o firmware/epen/W9012_tr_239.bin.gen.S

source_firmware/epen/W9012_tr_239.bin.gen.o := firmware/epen/W9012_tr_239.bin.gen.S

deps_firmware/epen/W9012_tr_239.bin.gen.o := \
  /home/justin/android/pok1/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \

firmware/epen/W9012_tr_239.bin.gen.o: $(deps_firmware/epen/W9012_tr_239.bin.gen.o)

$(deps_firmware/epen/W9012_tr_239.bin.gen.o):
