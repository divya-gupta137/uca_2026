#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		printf("Usage: %s <file_path>\n", argv[0]);
        	return 1;   
	}

	struct stat fileinfo;
	if(stat(argv[1], &fileinfo)==-1){
		perror("stat failed");
		return 1;
	}

	 printf("=== File Attributes for: %s ===\n", argv[1]);


//file type
	if(S_ISREG(fileinfo.st_mode))
		printf("File type:		 Regular file\n");
	else if(S_ISDIR(fileinfo.st_mode))
		printf("File type:		 Directory\n");
	else
		printf("File type:		 Other\n");
	

//permission
	printf("permissions:		%04o\n", fileinfo.st_mode & 0777);

//size
	printf("Size			%ld byter\n", fileinfo.st_size);

//hard links
	printf("Hard links count:	%ld\n", fileinfo.st_nlink);

//owner
	printf("Owner (UID):		%d\n", fileinfo.st_uid);

//group 
	printf("Group (GID):		%d\n", fileinfo.st_gid);

//times
	printf("Last Access Time:     %s", ctime(&fileinfo.st_atime));
	printf("Last Modification:    %s", ctime(&fileinfo.st_mtime));
	printf("Status Change Time:   %s", ctime(&fileinfo.st_ctime));
	return 0;

}
