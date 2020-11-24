# add more modules here!
obj-m = make_root.o
KERNEL_VERSION=5.4

all: 
	echo $(OBJECTS)
	make -C ../linux-$(KERNEL_VERSION) M=$(PWD) modules

clean:
	make -C ../linux-$(KERNEL_VERSION) M=$(PWD) clean
