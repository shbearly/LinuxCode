
CC=g++ 
CFLAGS= -g -pthread
LFLAGS= -pthread

usage:
	@echo " make semphore sem sha ioctl msg"

all: semphore sem sha ioctl msg

semphore: semphore

sem: sem

sha: sharemem_r sharemem_w

ioctl: ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice

msg: msgrcv msgsnd

.PHONY : clean
clean: 
	rm -rf sharemem_r sharemem_w semphore ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice msgrcv msgsnd sem
