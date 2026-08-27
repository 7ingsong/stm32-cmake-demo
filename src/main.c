#include <stdint.h>
#include <stdio.h>

#include "transport.h"
#include "utils.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE* f)
#endif

PUTCHAR_PROTOTYPE {
    transport_send((uint8_t*)&ch, 1);
    return ch;
}

int main() {
    clock_init();
    transport_init();

    while (1) {
        printf("Hello, world!\n");
        delay_ms(1000);
    }
    return 0;
}