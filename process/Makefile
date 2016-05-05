
CC=g++ 
CFLAGS= -g

all:

sem: semphore

sha: sharemem_r sharemem_w

ioctl: ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice

.PHONY : clean
clean: sharemem_r sharemem_w semphore ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice
	rm -rf $^
