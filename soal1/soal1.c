  GNU nano 2.9.3                                                                          soal1.c                                                                                     

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

unsigned long long int n[100];

void *factorial( void *ptr )
{
    int x, res, *arg;
    arg = (int*) ptr;
    res = 1;

    for(x = 1; x <= *arg; x++) res = res * x;

    n[*arg] = res;
    // index[in] = arg;
    // in++;
}


int main(int argc, char** argv)
{
    pthread_t threads[argc];
    int a[100];
        int x;
        for(x = 1; x <=argc - 1;x++){
         a[x]  = atoi (argv[x]);
        }

        for(x = 1; x <= argc - 1; x++)
        {
                pthread_create(&threads[x], NULL, &factorial, (void *)&a[x]);
        }

    for(x = 1; x <= argc - 1; x++)
       pthread_join(threads[x], NULL);
    
    for(x = 0; x < 100; x++)
        if(n[x] != 0) printf("%d! = %llu\n", x, n[x]);
                                                                                  [ Read 40 lines ]
^G Get Help     ^O Write Out    ^W Where Is     ^K Cut Text     ^J Justify      ^C Cur Pos      M-U Undo        M-A Mark Text   M-] To Bracket  M-▲ Previous    ^B Back
^X Exit         ^R Read File    ^\ Replace      ^U Uncut Text   ^T To Spell     ^_ Go To Line   M-E Redo        M-6 Copy Text   M-W WhereIs NextM-▼ Next        ^F Forward
