#include <stdio.h>
#include <string.h>
unsigned int convert_to_big(unsigned int x);
int main(void)
{
    unsigned int value = 1929286;
    char *c = (char *)&value;
    if (*c)
    {
        printf("Little endian\n");
        printf("\nBig Endian Converted Value = 0x%x\n", convert_to_big(value));
    }
    else
        printf("Big endian\n");
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("Address of 0x%x = %d \n", c[i], &c[i]);
    }

    return 0;
}
unsigned int convert_to_big(unsigned int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff0) | ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}
