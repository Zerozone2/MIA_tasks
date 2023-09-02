#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no; scanf( "%d", &no );

    while( no )
        printf( "%d\n", no-- );

    printf( "Blast off to the moon!" );

    return 0;
}
