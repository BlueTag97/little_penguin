obj-m += main.o

BUILD_FOLDER = /lib/modules/$(shell uname -r)/build

all:
	make -C $(BUILD_FOLDER) M=$(PWD) modules

modules_install:
	make -C $(BUILD_FOLDER) M=$(PWD) modules_install

clean:
	make -C $(BUILD_FOLDER) M=$(PWD) clean

.PHONY: all modules_install clean
