#!/bin/sh

#WORKSPACE_DIR="${HOME}/workspace-homeware/183r-ax"

#[ -z "$WORKSPACE_DIR" ] && echo "Set WORKSPACE_DIR to Homeware's workspace" && exit 1

#LINUX_DIR="${WORKSPACE_DIR}/openwrt/build_dir/target-arm_armv7-a_glibc-2.24_eabi/linux-brcm68xx-tch_GBNTQ/linux-4.1.52"
LINUX_DIR="/home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/work/cga4233_pc15_mgcp_tlc-rdk-linux-gnueabi/rglinux/3.14-1.2-r0/linux"
TOOLCHAIN="/home/yanli/cga4233tca/build-cga4233_pc15_mgcp_tlc/tmp/sysroots/x86_64-linux/usr/bin/cortexa15hf-vfp-neon-rdk-linux-gnueabi/"

make -C ${LINUX_DIR} \
    ARCH="arm" \
    CROSS_COMPILE="$TOOLCHAIN""arm-rdk-linux-gnueabi-" \
    SUBDIRS="${PWD}/src" \
    CONFIG_NFLUA=m \
    modules 
    CONFIG_LUADATA_DEBUG=m \
#    CONFIG_LUADATA_DEBUG=m \
#    CONFIG_LUNATIK_DEBUG=m \
#    CONFIG_LUAJSON_DEBUG=m \
#    CONFIG_LUABASE64_DEBUG=m \
