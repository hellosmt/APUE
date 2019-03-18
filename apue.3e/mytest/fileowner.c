#include "apue.h"
#include "apueerror.h"

int
main(int argc, char *argv[])
{
	int			i;
	struct stat	buf;
	//char		*ptr;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (lstat(argv[i], &buf) < 0) {    //填充buf指向的结构 后面可以看buf里的st_mode看该文件是什么类型的
			err_ret("lstat error");
			continue;
		}
		printf("%d\n", buf.st_uid);
	}
	exit(0);
}
