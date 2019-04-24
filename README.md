# unikernel-demo

### setup

##### Requirements
- qemu
- debootstrap

##### Clone & Configure the kernel
```
git clone https://github.com/ne02ptzero/whiterose
cd whiterose && make defconfig
```

It will apply the default of the linux kernel, with UKL support. If you're
trying to run this on exotic hardware, now is a good time to change the
configuration. As long as you keep `CONFIG_UKL_LINUX` to `true`, you should be
fine.

##### Clone && Running the examples
```
git clone https://github.com/jzck/unikernel-demo
cd unikernel-demo
```

Each example come with a Makefile. For example, if you want to run the unistd
example, simply do:
```
make -C fs1/unistd all qemu
```

Or stdio:
```
make -C fs1/stdio all qemu
```
