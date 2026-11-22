
#include "../includes/utils.h"

void copy(int8* dst, int8* src, int16 size) {


    int8 *d, *s;

    int16 n;

    for(n = size, d = dst, s = src; n; n--, d++, s++) {
        *d = *s;
    }

}

int16 nstoh(int16 scrport) {

    int16 dstport = 0;
    int8 x, y;

    x = ((scrport & 0xff00) >> 8);
    y = ((scrport & 0xff));

    dstport = (y << 8) + x;

    return dstport;

}

void printhex(int8* str, int16 size, int8 delim) {

    int8* p;
    int16 n;

    for(p = str, n = size; n; n--, p++) {

        printf("%.02X", *p);
        if(delim)
            printf("%c", delim);
        
        fflush(stdout);
    }

    printf("\n");
}

void zero(int8* str, int16 size) {
    int8* p;
    int16 n;

    for(n = 0, p = str; n < size; n++, p++)
        *p = 0;
}