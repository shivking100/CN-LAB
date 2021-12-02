#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    int roll_no;
    char name[50];
    float CGPA;
} obj;

struct info *assignValue(char nam[50], float value, int roll)
{
    struct info *new1 = (struct info *)malloc(sizeof(struct info *));
    new1->roll_no = roll;
    strcpy(new1->name, nam);
    new1->CGPA = value;
    return new1;
}

void display(struct info *node)
{
    printf("name=%s/\n", node->name);
    printf("roll no.=%d\n", node->roll_no);
    printf("CGPA=%f\n", node->CGPA);

}

int main()
{

    struct info *node = NULL;
    node = assignValue("SIVNARAYAN", 9.0, 286);
    display(node);
    return 0;
}