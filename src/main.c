
#include "../includes/main.h"

int16 checksum_calc(int8* pkt, int16 size) {

    int16 *ptr;
    int16 a,b;


    

}


icmp* make_icmp(icmp_type kind, const int8* data, int16 size) {

    int16 n;
    icmp* p;

    if(!data || size == 0) 
        return (icmp*)0;

    n = sizeof(struct s_icmp) + size; 
    p = (icmp*) malloc($i n);

    assert(p); 
    zero($1 p, n);
    

    p->kind = kind;
    p->size = size;
    p->data = data;
    

    return p;
}

int8* eval_icmp(icmp* icmp_packet) {

    if(!icmp_packet || !icmp_packet->data)
        return $1 -1;

    int8 *ptr, *ret;
    int16 size;
    int16 check;
    struct s_icmp_raw raw_packet;
    struct s_icmp_raw* raw_ptr;

    switch(icmp_packet->kind) {

        case echo:
            raw_packet.type_ = 8; // that is a standard for icmp packets
            raw_packet.code_ = 0;
            break;

        case echo_reply:
            raw_packet.type_ = 0;
            raw_packet.code_ = 0;
            break;


        default:
            return $1 0;
            break;

    }

    raw_packet.checksum_ = 0; // at the beggining 0

    size = sizeof(struct s_icmp_raw) + icmp_packet->size;
    if(size % 2)
        size++;

    ptr = $1 malloc($i size);
    ret = ptr;
    assert(ptr);
    zero($1 ptr, size);

    copy(ptr, $1 &raw_packet, sizeof(struct s_icmp_raw)); // headers

    ptr += sizeof(struct s_icmp_raw);
    copy(ptr, icmp_packet->data,  icmp_packet->size); // data
    
    check = checksum_calc(ret, size);
    raw_ptr = (struct s_icmp_raw *)ret;
    raw_ptr->checksum_ = check;

    return ret;
}



void show_icmp(icmp* icmp_packet) {
    if(!icmp_packet)
        return;

    printf("Kind:\t %s\nsize:\t %d\ndata:\n", (icmp_packet->kind == echo) ? "echo" : "echo reply", $i icmp_packet->size);

    if(icmp_packet->data)
        prinhex(icmp_packet->data, icmp_packet->size, 0);

    printf('\n');
}


int main(int argc, char** argv) {


    

    return 0;
}