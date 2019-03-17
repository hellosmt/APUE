#include "apue.h"
#include <apueerror.h>   //已经放在了/usr/include/文件夹下，是作者自己写的函数，要定义头文件引入进来

int main (int argc , char *argv[]){
    if(argc != 2){
        err_sys("usage:.....");
    }
    int n;
    int BUFFERSIZE = strtol(argv[1], NULL, 10);   //把字符串化成long 第二个参数是用来返回错误字符的 指明为NULL代表不返回错误字符 10代表化成long的基数
    char buf[BUFFERSIZE];

    while(n = read(STDIN_FILENO,buf,BUFFERSIZE)>0){  //返回值大于0 读成功 返回读到的字节数
        if(write(STDOUT_FILENO, buf, BUFFERSIZE)!=n){
            err_sys("write error!");
        }
    }

    if (n<0){
        err_sys("read error!");
    }
}