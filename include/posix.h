#ifndef __POSIX_H__
#define __POSIX_H__

#define stdin 0
#define stdout 1
#define stderr 2

#define BUFSZ 512

long read(int fd, void *buf, long n);
long write(int fd, void *buffer, long count);

#endif
