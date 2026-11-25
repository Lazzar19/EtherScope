#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>


#include "../includes/utils.h"

#define PACKED __attributes__((packed))

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

enum icmp_type {
    unassigned,
    echo, 
    echo_reply
};
typedef enum icmp_type icmp_type;

// represents icmp structure obtained directly from network
struct s_icmp_raw{
    int8 type_;
    int8 code_;
    int16 checksum_;
    int8 data[];
}packed;

// internal representation of icmp packets
struct s_icmp{
    icmp_type kind;
    int8* data;
    int16 size;
};
typedef struct s_icmp icmp;



icmp* make_icmp(icmp_type,const int8*, int16);  // int16 is data size
int8* eval_icmp(icmp*);
void show_icmp(icmp*);


int16 checksum_calc(int8*, int16);
int main(int, char**);


