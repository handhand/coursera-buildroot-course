#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char* argv[]) {
    if(argc != 3){
        printf("invalid number of arguments: %d", argc-1);
        openlog(NULL, 0, LOG_USER);
        syslog(LOG_ERR, "invalid number of arguments: %d", argc-1);
        exit(1);
    }
    FILE *fptr;
    fptr = fopen(argv[1], "w");
    if (fptr == NULL) {
        printf("error open the file: %s", argv[1]);
        openlog(NULL, 0, LOG_USER);
        syslog(LOG_ERR, "error open the file: %s", argv[1]);
        exit(1);
    }
    fputs(argv[2], fptr);
    fclose(fptr);
    openlog(NULL, 0, LOG_USER);
    syslog(LOG_DEBUG, "Write %s to %s", argv[2], argv[1]);
    return 0;
}
