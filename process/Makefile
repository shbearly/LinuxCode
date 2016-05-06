
CC=g++ 
CFLAGS= -g
LFLAGS= -pthread

all:

sem1: semphore

sem2: 
	$(CC) $(CFLAGS) $(LFLAGS) -o sem sem.c

sha: sharemem_r sharemem_w

ioctl: ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice

msg: msgrcv msgsnd

.PHONY : clean
clean: sharemem_r sharemem_w semphore ioctl_intf ioctl_phyconn ioctl_phyconn2 ioctl_voice msgrcv msgsnd sem
	rm -rf $^
