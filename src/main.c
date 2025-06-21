#include <posix.h>
#include <print.h>

int errno;

static void usage();

int main(int argc, char **argv, char **env)
{
    if (argc != 2)
        usage();

    int fd = open(argv[1], O_RDONLY);

    close(fd);
    return 0;
}

static void usage()
{
    eprint("lm: file\n");
    exit(1);
}
