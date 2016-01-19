cmd_arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb := /home/justin/android/toolchains/arm-cortex_a15-linux-gnueabihf-linaro_4.9.1/bin/arm-cortex_a15-linux-gnueabihf-gcc -E -Wp,-MD,arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.d.pre.tmp -nostdinc -I/home/justin/android/pok1/arch/arm/boot/dts -I/home/justin/android/pok1/arch/arm/boot/dts/include -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.dts.tmp arch/arm/boot/dts/qcom/apq8084-sec-trlte-r01.dts ; /home/justin/android/pok1/scripts/dtc/dtc -O dtb -o arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb -b 0 -i arch/arm/boot/dts/qcom/  -d arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.d.dtc.tmp arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.dts.tmp ; /home/justin/android/pok1/scripts/dtc/dtc -O dts -I dtb -o arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb.reverse.dts arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb ; cat arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.d.pre.tmp arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.d.dtc.tmp > arch/arm/boot/dts/qcom/../.apq8084-sec-trlte-r01.dtb.d

source_arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb := arch/arm/boot/dts/qcom/apq8084-sec-trlte-r01.dts

deps_arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb := \
  arch/arm/boot/dts/qcom/apq8084-v1.1.dtsi \
  arch/arm/boot/dts/qcom/apq8084.dtsi \
  arch/arm/boot/dts/qcom/skeleton64.dtsi \
  arch/arm/boot/dts/qcom/msm-gdsc.dtsi \
  arch/arm/boot/dts/qcom/apq8084-ion.dtsi \
  arch/arm/boot/dts/qcom/apq8084-iommu.dtsi \
  arch/arm/boot/dts/qcom/msm-iommu-v1.dtsi \
  arch/arm/boot/dts/qcom/apq8084-iommu-domains.dtsi \
  arch/arm/boot/dts/qcom/apq8084-smp2p.dtsi \
  arch/arm/boot/dts/qcom/apq8084-coresight.dtsi \
  arch/arm/boot/dts/qcom/apq8084-mdss.dtsi \
  arch/arm/boot/dts/qcom/apq8084-gpu.dtsi \
  arch/arm/boot/dts/qcom/apq8084-pm.dtsi \
  arch/arm/boot/dts/qcom/apq8084-bus.dtsi \
  arch/arm/boot/dts/qcom/apq8084-pinctrl.dtsi \
  arch/arm/boot/dts/qcom/apq8084-camera.dtsi \
  arch/arm/boot/dts/qcom/apq8084-ipcrouter.dtsi \
  arch/arm/boot/dts/qcom/msm-rdbg.dtsi \
  arch/arm/boot/dts/qcom/msm-pma8084-rpm-regulator.dtsi \
  arch/arm/boot/dts/qcom/msm-pma8084.dtsi \
  arch/arm/boot/dts/qcom/apq8084-regulator.dtsi \
  arch/arm/boot/dts/qcom/apq8084-mtp.dtsi \
  arch/arm/boot/dts/qcom/external-mdm9x25.dtsi \
  arch/arm/boot/dts/qcom/apq8084-sii8620-mhl3-trlte-r01.dtsi \
  arch/arm/boot/dts/qcom/apq8084-sec-trlte-r01.dtsi \
  arch/arm/boot/dts/qcom/apq8084-camera-sensor-trlte-r01.dtsi \
  arch/arm/boot/dts/qcom/apq8084-max77828-lentis.dtsi \
  arch/arm/boot/dts/qcom/apq8084-w1-t-v1.dtsi \
  /home/justin/android/pok1/arch/arm/boot/dts/../../../../drivers/video/msm/mdss/samsung/S6E3HA2_AMS567DJ01/dsi_panel_S6E3HA2_AMS567DJ01_wqhd_octa_cmd.dtsi \
  arch/arm/boot/dts/qcom/apq8084-sec-trlte-battery-r01.dtsi \

arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb: $(deps_arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb)

$(deps_arch/arm/boot/dts/qcom/../apq8084-sec-trlte-r01.dtb):
