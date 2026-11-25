#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>


#include "../includes/utils.h"

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char*)
#define $i (int*)

struct s_icmp{

    int8 type_;
    int8 code_;
    int16 checksum_;
    int8 data[];

};

typedef struct s_icmp icmp;
icmp* make_icmp(int8, int8, int8*, int16);  // int16 is data size


int main(int, char**);