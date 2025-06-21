#ifndef __POSIX_H__
#define __POSIX_H__

#define stdin 0
#define stdout 1
#define stderr 2

#define BUFSZ 512

#define O_RDONLY	00000
#define O_WRONLY	00001
#define O_RDWR		00002
#define O_ACCMODE	00003
#define O_CREAT		00100
#define O_EXCL		00200
#define O_NOCTTY	00400
#define O_TRUNC		01000
#define O_APPEND	02000
#define O_NONBLOCK	04000
#define O_SYNC		0010000
#define FASYNC		0020000
#define O_DIRECT	0040000
#define O_LARGEFILE	0100000
#define O_DIRECTORY	0200000
#define O_NOFOLLOW	0400000
#define O_NOATIME	001000000

#define S_IRWXU		00700
#define S_IRUSR		00400
#define S_IWUSR		00200
#define S_IXUSR		00100

#define S_IRWXG		00070
#define S_IRGRP		00040
#define S_IWGRP		00020
#define S_IXGRP		00010

#define S_IRWXO		00007
#define S_IROTH		00004
#define S_IWOTH		00002
#define S_IXOTH		00001

long read(unsigned int fd, void *buf, long count);
long write(unsigned int fd, void *buffer, long count);
int open(const char *filename, int flags, ...);
int close(unsigned int fd);

void exit(int status);

#endif
