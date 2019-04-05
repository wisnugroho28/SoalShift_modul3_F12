#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


pthread_t tid[2];

void* solve(void *arg)
{
        pthread_t id = pthread_self();
        if (pthread_equal(id, tid[0])) {
                system("mkdir /home/jendralhoki/Documents/FolderProses1");
                system("ps -aux | head > /home/jendralhoki/Documents/FolderProses1/SimpanProses1.txt");
                system("zip -mj /home/jendralhoki/Documents/FolderProses1/KompresProses1.zip /home/jendralhoki/Documents/FolderProses1/SimpanProses1.txt");
                sleep(15);
                system("unzip /home/jendralhoki/Documents/FolderProses1/KompresProses1.zip -d /home/jendralhoki/Documents/FolderProses1/");
        } else  {
                system("mkdir /home/jendralhoki/Documents/FolderProses2");
                system("ps -aux | head > /home/jendralhoki/Documents/FolderProses2/SimpanProses2.txt");
                system("zip -mj /home/jendralhoki/Documents/FolderProses2/KompresProses2.zip /home/jendralhoki/Documents/FolderProses2/SimpanProses2.txt");
                sleep(15);
                system("unzip /home/jendralhoki/Documents/FolderProses2/KompresProses2.zip -d /home/jendralhoki/Documents/FolderProses2/");
        }
        return NULL;
}

int main(void)
{
        int x = 0;
        while(x < 2) // loop sejumlah thread
        {
                int failure=pthread_create(&(tid[x]),NULL,&solve,NULL); //membuat thread
                if(failure!=0) //cek error
                {
                        printf("\n fail to create thread : [%s]",strerror(failure));
                }
                else
                {
                        printf("\n thread created.\n");
                }
                x++;
        }
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
        exit(0);
        return 0;
}

