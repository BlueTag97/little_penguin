obj-m += main.o

BUILD_FOLDER = /lib/modules/$(shell uname -r)/build

all:
	make -C $(BUILD_FOLDER) M=$(PWD) modules

clean:
	make -C $(BUILD_FOLDER) M=$(PWD) clean
