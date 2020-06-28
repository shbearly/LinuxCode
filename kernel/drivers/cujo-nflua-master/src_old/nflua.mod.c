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
	{ 0xeaeca58d, __VMLINUX_SYMBOL_STR(xt_unregister_match) },
	{ 0x63b84363, __VMLINUX_SYMBOL_STR(unregister_pernet_subsys) },
	{ 0xbdc904cb, __VMLINUX_SYMBOL_STR(xt_register_match) },
	{ 0xf16fc5f4, __VMLINUX_SYMBOL_STR(register_pernet_subsys) },
	{ 0xc5068fc7, __VMLINUX_SYMBOL_STR(skb_copy) },
	{ 0x98494326, __VMLINUX_SYMBOL_STR(__netlink_kernel_create) },
	{        0, __VMLINUX_SYMBOL_STR(ns_capable) },
	{ 0xd9ce8f0c, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0x3cd08a60, __VMLINUX_SYMBOL_STR(netlink_kernel_release) },
	{ 0xdd3916ac, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xa1d55e90, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x29be714c, __VMLINUX_SYMBOL_STR(netlink_unicast) },
	{ 0x103c4cee, __VMLINUX_SYMBOL_STR(netlink_broadcast) },
	{ 0xe1b4fffa, __VMLINUX_SYMBOL_STR(__nlmsg_put) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xc8fd727e, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0xfa2bcf10, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xcca27eeb, __VMLINUX_SYMBOL_STR(del_timer) },
	{ 0x2fbfa4bf, __VMLINUX_SYMBOL_STR(ip6_route_me_harder) },
	{ 0x1ab34ca0, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x896136dc, __VMLINUX_SYMBOL_STR(__skb_gso_segment) },
	{ 0xc6a5597e, __VMLINUX_SYMBOL_STR(netif_skb_dev_features) },
	{ 0xf072904d, __VMLINUX_SYMBOL_STR(skb_gso_transport_seglen) },
	{ 0x2124474, __VMLINUX_SYMBOL_STR(ip_send_check) },
	{ 0xe6103647, __VMLINUX_SYMBOL_STR(dst_release) },
	{ 0xd58466de, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x41346fb9, __VMLINUX_SYMBOL_STR(ip6_local_out) },
	{ 0xd986441d, __VMLINUX_SYMBOL_STR(ip6_dst_hoplimit) },
	{ 0x435f634e, __VMLINUX_SYMBOL_STR(xfrm_lookup) },
	{ 0x24c92acd, __VMLINUX_SYMBOL_STR(ip6_route_output) },
	{ 0x44da5d0f, __VMLINUX_SYMBOL_STR(__csum_ipv6_magic) },
	{ 0x7430bdad, __VMLINUX_SYMBOL_STR(skb_checksum) },
	{ 0x682eff38, __VMLINUX_SYMBOL_STR(ipv6_skip_exthdr) },
	{ 0xd542439, __VMLINUX_SYMBOL_STR(__ipv6_addr_type) },
	{ 0x95905d1e, __VMLINUX_SYMBOL_STR(skb_copy_bits) },
	{ 0xfc2efccb, __VMLINUX_SYMBOL_STR(ip_local_out) },
	{ 0x1417586c, __VMLINUX_SYMBOL_STR(nf_ct_attach) },
	{ 0xf6388c56, __VMLINUX_SYMBOL_STR(sysctl_ip_default_ttl) },
	{ 0x7cda8d6b, __VMLINUX_SYMBOL_STR(ip_route_me_harder) },
	{ 0x23b5a96a, __VMLINUX_SYMBOL_STR(__skb_dst_set_noref) },
	{ 0xe113bbbc, __VMLINUX_SYMBOL_STR(csum_partial) },
	{ 0xd3cb60e6, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xd0d0a45d, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0x83442670, __VMLINUX_SYMBOL_STR(nf_ip_checksum) },
	{ 0xe007de41, __VMLINUX_SYMBOL_STR(kallsyms_lookup_name) },
	{ 0xd7e56a4e, __VMLINUX_SYMBOL_STR(simple_strtoll) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
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

