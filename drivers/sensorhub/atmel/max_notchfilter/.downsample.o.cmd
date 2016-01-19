cmd_drivers/sensorhub/atmel/max_notchfilter/downsample.o := /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/arm-cortex_a15-linux-gnueabihf-gcc -Wp,-MD,drivers/sensorhub/atmel/max_notchfilter/.downsample.o.d  -nostdinc -isystem /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/../lib/gcc/arm-cortex_a15-linux-gnueabihf/4.9.1/include -I/home/justin/android/pok1/arch/arm/include -Iarch/arm/include/generated  -Iinclude -I/home/justin/android/pok1/arch/arm/include/uapi -Iarch/arm/include/generated/uapi -I/home/justin/android/pok1/include/uapi -Iinclude/generated/uapi -include /home/justin/android/pok1/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -Os -Wno-maybe-uninitialized -fno-dwarf2-cfi-asm -fstack-protector -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables -marm -D__LINUX_ARM_ARCH__=7 -mcpu=cortex-a15 -msoft-float -Uarm -Wframe-larger-than=1024 -Wno-unused-but-set-variable -fomit-frame-pointer -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(downsample)"  -D"KBUILD_MODNAME=KBUILD_STR(downsample)" -c -o drivers/sensorhub/atmel/max_notchfilter/.tmp_downsample.o drivers/sensorhub/atmel/max_notchfilter/downsample.c

source_drivers/sensorhub/atmel/max_notchfilter/downsample.o := drivers/sensorhub/atmel/max_notchfilter/downsample.c

deps_drivers/sensorhub/atmel/max_notchfilter/downsample.o := \
  drivers/sensorhub/atmel/max_notchfilter/downsample.h \
  drivers/sensorhub/atmel/max_notchfilter/fixed_fir_filter.h \
  drivers/sensorhub/atmel/max_notchfilter/fixed.h \
  drivers/sensorhub/atmel/max_notchfilter/fixed_iir_filter.h \

drivers/sensorhub/atmel/max_notchfilter/downsample.o: $(deps_drivers/sensorhub/atmel/max_notchfilter/downsample.o)

$(deps_drivers/sensorhub/atmel/max_notchfilter/downsample.o):
