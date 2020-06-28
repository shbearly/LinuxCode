#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x6f2bf954, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x4404db0e, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x5e57270d, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x48f8933d, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x72f9dcaa, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x60f91800, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x2a6cfe58, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x17b86049, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x164c2641, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x37b504e3, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x2256fafa, __VMLINUX_SYMBOL_STR(div64_u64_rem) },
	{ 0xa735db59, __VMLINUX_SYMBOL_STR(prandom_u32) },
	{ 0x4411c503, __VMLINUX_SYMBOL_STR(prandom_seed) },
	{ 0x9a1dfd65, __VMLINUX_SYMBOL_STR(strpbrk) },
	{ 0xdd27fa87, __VMLINUX_SYMBOL_STR(memchr) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
	{ 0xc7ec6c27, __VMLINUX_SYMBOL_STR(strspn) },
	{ 0x1e6d26a8, __VMLINUX_SYMBOL_STR(strstr) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xb859f38b, __VMLINUX_SYMBOL_STR(krealloc) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x84b183ae, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x7593d385, __VMLINUX_SYMBOL_STR(div64_s64) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
	{ 0x71c90087, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x46608fa0, __VMLINUX_SYMBOL_STR(getnstimeofday) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x97255bdf, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0xe707d823, __VMLINUX_SYMBOL_STR(__aeabi_uidiv) },
	{ 0x2196324, __VMLINUX_SYMBOL_STR(__aeabi_idiv) },
	{ 0x7c1372e8, __VMLINUX_SYMBOL_STR(panic) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

