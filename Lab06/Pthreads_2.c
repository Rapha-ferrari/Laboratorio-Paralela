# inclui < stdio.h >
# inclui < pthread.h >
# inclui < math.h >
# inclui < stdlib.h >
# inclui < unistd.h >

# define  NUM_THREADS  8

 estrutura typedef {
	classificação interna ;
    soma dupla ;
} thread_data;

thread_data td[NUM_THREADS];

void * help_pi ( void * rank) {
	int thread_rank = *( int *)rank;
	double incr = 0 ;
	sinal int ;
    int k = thread_rank;

	if (k % 2 ) {
		sinal = - 1 ;
	} senão {
		sinal = 1 ;
	}

	td[thread_rank]. soma = 4 *(( double )sign / ( 2 * thread_rank + 1 ));

	fazer {
		k += NUM_THREADS;

		if (k % 2 ) {
			sinal = - 1 ;
		} senão {
			sinal = 1 ;
		}

		incr = ( double )sinal / ( 2 * k + 1 );
		td[thread_rank]. soma += 4 * incr;
	}
  enquanto ( fabs (incr) > 1e-6 );

	retorna  NULL ;
}

int  main (){
	int posto = 0 ;
	erro ;
	duplo  pi = 0 ;
	pthread_t thread_ids[NUM_THREADS];

	while (classificação < NUM_THREADS) {
		td[classificação]. posto = posto;

		err = pthread_create (&(thread_ids[rank]), NULL , help_pi, ( void *)&td[rank]. rank );
		if (erro != 0 ) {
			printf ( " Não foi possível criar o erro de thread = %d \n " , err);
			retorno  1 ;
		}
		classificação++;
	}

	posto = 0 ;
	while (classificação < NUM_THREADS) {
		pthread_join (thread_ids[rank], NULL );
		classificação++;
	}

	posto = 0 ;
	while (classificação < NUM_THREADS) {
        pi += td[rank]. soma ;
		classificação++;
	}


  printf ( " %f \n " , pi );

  retorna  0 ;
}
