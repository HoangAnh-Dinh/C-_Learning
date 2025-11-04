#include <stdio.h>

int main()
{
    char buffer[10];
    char *symbol =  &buffer[1];

buffer[1] = 'H';
buffer[2] = 'A';
buffer[3] = 'P';
printf("[LINE:%d]%s:%s\n",__LINE__,__FILE__,__FUNCTION__);
buffer[4] = 'A';

    printf("%s",symbol);

    return 0;
}