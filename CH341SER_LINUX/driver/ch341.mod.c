#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\xae\xb3\x17\x8e"
	"idr_destroy\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x10\x00\x00\x00\x38\xdf\xac\x69"
	"memcpy\0\0"
	"\x28\x00\x00\x00\x0f\x65\x1d\xe9"
	"usb_autopm_get_interface_async\0\0"
	"\x18\x00\x00\x00\x20\x1a\x79\x30"
	"usb_anchor_urb\0\0"
	"\x24\x00\x00\x00\xac\x84\x27\x62"
	"usb_autopm_get_interface\0\0\0\0"
	"\x18\x00\x00\x00\xae\x4d\x7a\x07"
	"usb_control_msg\0"
	"\x1c\x00\x00\x00\x63\xa5\x03\x4c"
	"random_kmalloc_seed\0"
	"\x18\x00\x00\x00\xd4\x9c\x99\xf2"
	"kmalloc_caches\0\0"
	"\x18\x00\x00\x00\x3a\xdc\x24\x45"
	"kmalloc_trace\0\0\0"
	"\x10\x00\x00\x00\xba\x0c\x7a\x03"
	"kfree\0\0\0"
	"\x18\x00\x00\x00\x11\x70\xd0\xe7"
	"usb_ifnum_to_if\0"
	"\x14\x00\x00\x00\x4b\x8d\xfa\x4d"
	"mutex_lock\0\0"
	"\x14\x00\x00\x00\x03\x16\xf1\xb8"
	"idr_alloc\0\0\0"
	"\x18\x00\x00\x00\x38\xf0\x13\x32"
	"mutex_unlock\0\0\0\0"
	"\x20\x00\x00\x00\x54\xea\xa5\xd9"
	"__init_waitqueue_head\0\0\0"
	"\x18\x00\x00\x00\x9f\x0c\xfb\xce"
	"__mutex_init\0\0\0\0"
	"\x18\x00\x00\x00\x41\xa8\xde\xf9"
	"tty_port_init\0\0\0"
	"\x1c\x00\x00\x00\x72\x78\x44\x57"
	"usb_alloc_coherent\0\0"
	"\x18\x00\x00\x00\x7b\x60\xa9\xd0"
	"usb_alloc_urb\0\0\0"
	"\x14\x00\x00\x00\x5b\xa9\x65\x76"
	"idr_remove\0\0"
	"\x1c\x00\x00\x00\x11\x5e\xac\x4a"
	"usb_free_coherent\0\0\0"
	"\x14\x00\x00\x00\xa3\x59\x98\x7e"
	"_dev_info\0\0\0"
	"\x24\x00\x00\x00\x7e\xc3\xfc\xb2"
	"usb_driver_claim_interface\0\0"
	"\x18\x00\x00\x00\xba\x4d\xbf\x82"
	"usb_get_intf\0\0\0\0"
	"\x24\x00\x00\x00\x81\x89\x8e\xa0"
	"tty_port_register_device\0\0\0\0"
	"\x18\x00\x00\x00\x1e\x75\x25\x4b"
	"usb_free_urb\0\0\0\0"
	"\x28\x00\x00\x00\x7d\x23\x9e\x6d"
	"__tty_insert_flip_string_flags\0\0"
	"\x20\x00\x00\x00\x50\x5f\xa0\xc8"
	"tty_flip_buffer_push\0\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x14\x00\x00\x00\xb9\x8f\x97\x20"
	"idr_find\0\0\0\0"
	"\x20\x00\x00\x00\xce\x92\x81\x71"
	"tty_standard_install\0\0\0\0"
	"\x20\x00\x00\x00\x5f\x69\x96\x02"
	"refcount_warn_saturate\0\0"
	"\x14\x00\x00\x00\xd3\x85\x33\x2d"
	"system_wq\0\0\0"
	"\x18\x00\x00\x00\x36\xf2\xb6\xc5"
	"queue_work_on\0\0\0"
	"\x18\x00\x00\x00\xc2\x9c\xc4\x13"
	"_copy_from_user\0"
	"\x10\x00\x00\x00\x89\xbc\xcb\xc6"
	"capable\0"
	"\x18\x00\x00\x00\xe1\xbe\x10\x6b"
	"_copy_to_user\0\0\0"
	"\x20\x00\x00\x00\xd6\xc7\xd8\xaa"
	"default_wake_function\0\0\0"
	"\x14\x00\x00\x00\x45\xb5\x25\x20"
	"pcpu_hot\0\0\0\0"
	"\x18\x00\x00\x00\x38\x22\xfb\x4a"
	"add_wait_queue\0\0"
	"\x14\x00\x00\x00\x51\x0e\x00\x01"
	"schedule\0\0\0\0"
	"\x1c\x00\x00\x00\x88\x00\x11\x37"
	"remove_wait_queue\0\0\0"
	"\x20\x00\x00\x00\xa3\x13\x9c\xcd"
	"tty_termios_hw_change\0\0\0"
	"\x20\x00\x00\x00\xd8\x94\xd3\x0b"
	"tty_termios_baud_rate\0\0\0"
	"\x18\x00\x00\x00\xaa\x15\xdb\xfd"
	"usb_put_intf\0\0\0\0"
	"\x1c\x00\x00\x00\xfc\x32\x89\x72"
	"tty_port_tty_get\0\0\0\0"
	"\x14\x00\x00\x00\x9d\x91\xc4\xe1"
	"tty_vhangup\0"
	"\x18\x00\x00\x00\x4d\xbe\xb6\xbf"
	"tty_kref_put\0\0\0\0"
	"\x20\x00\x00\x00\x9a\xf1\x35\xf9"
	"tty_unregister_device\0\0\0"
	"\x28\x00\x00\x00\x0f\x4e\x0a\x74"
	"usb_driver_release_interface\0\0\0\0"
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x20\x00\x00\x00\x0b\x05\xdb\x34"
	"_raw_spin_lock_irqsave\0\0"
	"\x24\x00\x00\x00\x70\xce\x5c\xd3"
	"_raw_spin_unlock_irqrestore\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x18\x00\x00\x00\x53\x5a\x22\xd2"
	"usb_submit_urb\0\0"
	"\x14\x00\x00\x00\x36\x7e\x04\xf0"
	"_dev_err\0\0\0\0"
	"\x28\x00\x00\x00\xb3\x1c\xa2\x87"
	"__ubsan_handle_out_of_bounds\0\0\0\0"
	"\x28\x00\x00\x00\x78\x1f\xcb\x0a"
	"usb_autopm_put_interface_async\0\0"
	"\x18\x00\x00\x00\x75\xa4\x0b\x3a"
	"usb_kill_urb\0\0\0\0"
	"\x1c\x00\x00\x00\xfe\x2d\xc1\x03"
	"cancel_work_sync\0\0\0\0"
	"\x1c\x00\x00\x00\x7b\xcc\x27\x84"
	"_raw_spin_lock_irq\0\0"
	"\x20\x00\x00\x00\x53\x0f\x75\x4b"
	"_raw_spin_unlock_irq\0\0\0\0"
	"\x18\x00\x00\x00\xf1\x71\xcc\x47"
	"tty_port_put\0\0\0\0"
	"\x1c\x00\x00\x00\x9f\x20\x18\xe4"
	"__tty_alloc_driver\0\0"
	"\x18\x00\x00\x00\xc1\x7e\xb2\x67"
	"tty_std_termios\0"
	"\x1c\x00\x00\x00\xe6\x98\x01\xea"
	"tty_register_driver\0"
	"\x1c\x00\x00\x00\x62\x29\x5e\x04"
	"usb_register_driver\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x20\x00\x00\x00\x15\xfa\xc0\x6f"
	"tty_unregister_driver\0\0\0"
	"\x1c\x00\x00\x00\x7f\x8f\x09\xf9"
	"tty_driver_kref_put\0"
	"\x20\x00\x00\x00\x6f\x36\xbe\x6e"
	"ktime_get_mono_fast_ns\0\0"
	"\x14\x00\x00\x00\x44\x43\x96\xe2"
	"__wake_up\0\0\0"
	"\x1c\x00\x00\x00\x11\x0d\x4f\x64"
	"__dynamic_dev_dbg\0\0\0"
	"\x1c\x00\x00\x00\x1f\x66\x2e\xa7"
	"tty_port_tty_hangup\0"
	"\x2c\x00\x00\x00\x2d\xa2\x86\x4a"
	"usb_autopm_get_interface_no_resume\0\0"
	"\x24\x00\x00\x00\xf2\xb7\x21\x7c"
	"usb_autopm_put_interface\0\0\0\0"
	"\x1c\x00\x00\x00\x6e\x7b\xa4\xb0"
	"usb_get_from_anchor\0"
	"\x1c\x00\x00\x00\x53\x45\x6d\xae"
	"tty_port_tty_wakeup\0"
	"\x18\x00\x00\x00\x75\x6f\x9d\x11"
	"tty_port_hangup\0"
	"\x18\x00\x00\x00\xef\x1a\x47\x6d"
	"tty_port_close\0\0"
	"\x18\x00\x00\x00\xcb\x11\xf5\x80"
	"tty_port_open\0\0\0"
	"\x18\x00\x00\x00\x32\x73\x3b\xa9"
	"usb_deregister\0\0"
	"\x18\x00\x00\x00\xe8\xd8\x3d\xf5"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v1A86p7523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p7522d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p5523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86pE523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v4348p5523d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "6D8981BF1DFE599E38AE848");
