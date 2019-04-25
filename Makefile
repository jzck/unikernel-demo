all:
	$(MAKE) -C ../../../whiterose/ UKL=$(CURDIR) bzImage

../../disk.img:
	qemu-img create ../../disk.img 0g
	mkfs.ext2 ../../disk.img
	mkdir tmp_mnt
	sudo mount -o loop ../../disk.img tmp_mnt
	sudo debootstrap --arch amd64 jessie tmp_mnt
	sudo umount tmp_mnt
	rmdir tmp_mnt

qemu: ../../disk.img
	qemu-system-x86_64 -enable-kvm -s -m 1G -nographic -cpu host\
		-kernel ../../../whiterose/arch/x86/boot/bzImage\
		-append "console=ttyS0 ukl-hybrid quiet root=/dev/sda"\
		-hda ../../disk.img

qemu-ukl: ../../disk.img
	qemu-system-x86_64 -enable-kvm -s -m 1G -nographic -cpu host\
		-kernel ../../../whiterose/arch/x86/boot/bzImage\
		-append "console=ttyS0 ukl quiet root=/dev/sda"\
		-hda ../../disk.img
