#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;

void* runner( void* param );

int main( int argc, char* argv[] ) {
	pthread_t tid[3];
	if (argc != 2) {
		printf("An integer value is required as an argument.\n");
		return -1;
	}
	if (atoi( argv[1]) < 0) {
		printf("%d must be >= 0.\n", atoi(argv[1]));
	}

	for ( int i = 0; i < 3; ++i ) {
		pthread_create(&tid[i], NULL, runner, argv[1]);
    }
    for ( int j = 0; j < 3; ++j ) {
        pthread_join( tid[j], NULL );
    }
	printf("sum = %d.\n", sum);
	
    pthread_exit( 0 ); 

}

void* runner( void *param ) {
    int upper = atoi( param );
	for (int i = 1; i <= upper; i++ ) {
		sum += i;	
	}
    printf("A thread has finished.\n");
	/*pthread_exit(0);*/
    return 0;
}
