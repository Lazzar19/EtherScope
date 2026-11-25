
#include "../includes/main.h"

icmp* make_icmp(int8 type, int8 code, int8* data, int16 size) {

    int16 n;
    icmp* p;

    if(!data || size == 0) 
        return (icmp*)0;

    n = sizeof(struct s_icmp) + size; 
    p = (icmp*) malloc($i n);
    assert(p); 

    zero($1 p, n);
    copy($1 &p->data, data, size);

    p->type_ = type;
    p->code_ = code;
    p->checksum_ = checksum_func(p);


    return p;
}

int main(int argc, char** argv) {


    

    return 0;
}