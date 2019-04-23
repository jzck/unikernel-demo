PACKAGES = bash coreutils iputils net-tools strace util-linux iproute pciutils 
TARGET = min-initrd.d
SMD = supermin.d
bzImage = ../../whiterose/x86/boot/bzImage

export ukl-obj-m := main.o
    
all: $(target)/root
	$(MAKE) -C ../../whiterose/ UKL=$(PWD) bzImage

supermin.d/packages:
	supermin --prepare $(PACKAGES) -o $(SMD)

supermin.d/init.tar.gz: init
	tar zcf $@ $^

$(TARGET)/root: supermin.d/packages supermin.d/init.tar.gz 
	supermin --build -v -v -v --size 8G --if-newer --format ext2 supermin.d -o ${@D}

qemu:
	qemu-system-x86_64 -enable-kvm -s -m 1G -nographic -cpu host\
	       	-kernel $(bzImage)\
		-initrd min-initrd.d/initrd\
		-hda min-initrd.d/root\
		-append "console=ttyS0 ukl quiet"\
	       	--device  virtio-net,netdev=usernet -netdev user,id=usernet,hostfwd=tcp::5555-:5555
