export ukl-obj-m := fs1.o
    
all:
	$(MAKE) -C ../whiterose/ UKL=$(PWD) bzImage
qemu:
	qemu-system-x86_64 -enable-kvm -m 1G -s -kernel ../whiterose/arch/x86/boot/bzImage -append "console=ttyS0 ukl quiet" -nographic
