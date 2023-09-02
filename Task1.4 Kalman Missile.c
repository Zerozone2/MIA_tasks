#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
    float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
    float result[10];

    memset( result, 0.0, sizeof(result) );

    float gain = 0.79 / ( 0.79 + 0.92 );
    
    for( int i=0; i<10 ; i++ ){
        result[i] = bno55[i] + gain * ( mpu6050[i] - bno55[i] );
    }

    for( int i=0; i<10 ; i++ ){
        printf( "%f ", result[i] );
    }

    return 0;
}
