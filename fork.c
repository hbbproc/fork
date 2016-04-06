#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int g_val = 8;
int main()
{
    int val = 10;
    char *str = "hello bit!\n";
    write(1,str,strlen(str));
    pid_t id = fork();
    if(id < 0){
        perror("fork");
        exit(2);
    }else if(id == 0){
        g_val++;
        val++;
        printf("child -> g_val:%d val:%d\n",g_val,val);
        printf("child-> pid:%d ppid:%d\n",getpid(),getppid());
    }else{
        printf("father-> g_val:%d val:%d\n",g_val,val);
        printf("father-> pid:%d ppid:%d\n",getpid(),getppid());
        sleep(4);
    }
    
 //   printf("g_val:%d val:%d\n",g_val,val);  
    return 0;
}
