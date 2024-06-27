#include <stdio.h>

#include <math.h>

#define u 20

double hailee ( int V [ ] , int N )

{

    double m = 0 ;
    
    for ( int i = 0 ; i < N ; i ++ )
        m += V [ i ] ;
        
    return m / N ;
    
}

double steinfeld ( int V [ ] , int N )

{

    double v = 0, h = hailee ( V , N ) ;

    for ( int i = 0 ; i < N ; i ++ )
        v += pow ( ( V [ i ] - h ) , 2 ) ;

    return v / N ;    

}

int starving ( int V [ ] , int N )

{

    double h = hailee ( V , N ) ;

    int k = N ;

    for ( int i = 0 ; i < N ; i ++ )
        if ( V [ i ] <= h )
        {

            k -- ;

            if ( V [ i ] < h )
                V [ i ] = 0 ;

        }

    return k ;    

}

int main ( )

{

    int N , V [ u ] ;

    printf ( " size: " ) ;

    scanf ( "%d" , & N ) ;

    printf ( " elements: " ) ;

    for ( int i = 0 ; i < N ; i ++ )
        scanf ( "%d" , & V [ i ] ) ;

    printf ( " mean %.2lf \n " , hailee ( V , N ) ) ;

    printf ( " variance %.2lf \n " , steinfeld ( V , N ) ) ;

    printf ( " %d elements great then mean \n " , starving ( V , N ) ) ;

    for ( int i = 0 ; i < N ; i ++ )
        printf ( " V [ %d ] = %d " , i , V [ i ] ) ;

    return 0 ;

}
