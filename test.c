#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(int ac, char **av)
{
    char NameArr[1000][1000];
    DIR *dir;

    int i = 0;
    int k = 0;
    int j = 0;

    struct dirent *ent;
    struct stat buf;
    dir = opendir (av[1]);
    if (dir != NULL) {
    while ((ent = readdir (dir)) != NULL) {
        if (ent->d_name[0] != '.' && ent->d_name[strlen(ent->d_name)-1] != '~'){
            strcpy(NameArr[i],ent->d_name);
            i++;
        }
    }
    closedir (dir);
    }
    for (k=0;(k < (i)) && (k < 1000);k++) {
        if (k < i - 1)
            printf("%s  ",NameArr[k]);
        else 
            printf("%s",NameArr[k]);
    }

    for (j = 0;(j < (i)) && (j < 1000); j++) {
        if (j < i - 1)
            printf("%s  ",NameArr[k]);
        else 
            printf("%s",NameArr[k]);
    }
    //print the filenames on the screen
        //printf("%s\n",NameArr[0]);
    //printf("%d\n", );
    return 0;
}