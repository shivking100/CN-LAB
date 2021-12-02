#include <stdio.h>
#include <string.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

void printDetails(struct pkt *number)
{
    printf("%x\n", number->ch1);
    printf("%x\n", number->ch2[0]);
    printf("%x\n", number->ch2[1]);
    printf("%x\n", number->ch3);
};

int main()
{
    unsigned int x = 0x12345678;
    struct pkt number;
    number.ch1 = x ;
    number.ch2[0] = (x >> 8) ;
    number.ch2[1] = (x >> 16) ;
    number.ch3 = (x >> 24) ;
    printDetails(&number);
    return 0;
}
