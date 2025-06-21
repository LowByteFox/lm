#include <print.h>
#include <posix.h>

struct buf {
    char buffer[BUFSZ];
    int offset;
};

static struct buf buffers[] = {
    { 0 }, /* stdout */
    { 0 }, /* stderr */
};

static int fprint(const char *text, int buf)
{
    int i = 0;
    for (; *text != 0; buffers[buf].offset++, text++, i++) {
        char c = *text;
        buffers[buf].buffer[buffers[buf].offset] = c;
        if (c == '\n') {
            write(stdout, buffers[buf].buffer, buffers[buf].offset + 1);
            buffers[buf].offset = -1;
        } else if (buffers[buf].offset == BUFSZ - 1) {
            write(stdout, buffers[buf].buffer, BUFSZ);
            buffers[buf].offset = -1;
        }
    }
    return i;
}

int print(const char *text)
{
    return fprint(text, 0);
}

int eprint(const char *text)
{
    return fprint(text, 1);
}

void flush()
{
    for (int i = 0; i < 2; i++) {
        if (buffers[i].offset > 0) {
            write(stdout, buffers[i].buffer, buffers[i].offset);
            buffers[i].offset = 0;
        }
    }
}
