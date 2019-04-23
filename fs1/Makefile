export ukl-obj-m := main.o
    
all:
	$(MAKE) -C ../../whiterose/ UKL=$(PWD) bzImage

qemu:
	qemu-system-x86_64 -enable-kvm -s -m 1G -nographic -cpu host\
	       	-kernel ../whiterose/arch/x86/boot/bzImage\
		-append "console=ttyS0 ukl quiet"\
