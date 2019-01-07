/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <dirent.h> 


void my_putchar(char c)
{
    write(1, &c, 1);
}
int my_strlen2(char const *str)
{
    int counter = 0;

    while (str[counter])
        counter++;
    return (counter);
}

int my_putstr2(char const *str)
{
    int counter = 0;

    while (str[counter]) {
        my_putchar(str[counter]);
        counter++;
    }
    return (0);
}

char *my_revstr(char *str)
{
    int counter = my_strlen2(str) - 1;
    int i = 0;
    char temp;

    while (i < counter) {
        temp = str[i];
        str[i] = str[counter];
        str[counter] = temp;
        counter--;
        i++;
    }
    return (str);
}

char my_putstr(char const *str)
{
    int counter = 0;
    char test[100];

    while (str[counter]) {
        //my_putchar(str[counter]);
        counter++;
    }
    my_putchar('\n');
    while (str[counter] != '/') {
        test[counter] = str[counter];
        //my_putchar(test[counter]);
        //my_putchar(str[counter]);
        counter--;
    //my_
    }

    return (test);
}


int main(int ac, char **av)

/*{
    struct stat buf;

    if (ac != 2)
        return (0);
    char str[1000];

    stat(av[1], &buf);
        


    switch (buf.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }
        //my_strcpy(str, av[1]);
        //my_putstr(av[1]);



        //my_putstr2(str);

        printf("File Size: \t\t%d bytes\n",buf.st_size);
        printf("Number of Links: \t%d\n",buf.st_nlink);
        printf("Types : \t%o\n", buf.st_mode);
        printf("File inode: \t%d\n",buf.st_ino);
        printf("Allocated: \t%d\n",buf.st_blocks);
        printf("UID: \t\t%d\n",buf.st_uid);
        printf("GID: \t\t%d\n",buf.st_gid);
        //printf("Types : \t%s\n", buf.st_dev);
        return (0);
 
}*/
/*{
    char str[100000];
    int i = 0;
    DIR * rep = opendir("."); 
  
    if (rep != NULL) 
    { 
        struct dirent *ent; 
  
        while ((ent = readdir(rep)) != 0) { 
            ent->d_name = str[i];
            printf("%s\n", ent->d_name);
            i++;
        } 
  
        closedir(rep); 
    } 
  
    return 0; 
}*/

{
    DIR *dir;
    struct dirent *dp;
    char *file_name;
    dir = opendir(av[1]);
    int counter = 0;
    int i = 0;
    while ((dp=readdir(dir)) != NULL) {
        //printf("debug: %s\n", dp->d_name);
        if (dp->d_name[0] != '.' && dp->d_name[strlen(dp->d_name)-1] != '~'){
            file_name = dp->d_name;
            printf("%s  ",file_name);
        } 

        /*else {
            file_name = dp->d_name; // use it
            printf("%s\n",file_name);
        }*/
    }
        printf("\b");
        printf("\b");
    while (file_name[counter] != '\0') {
        //printf("%s", file_name);
        counter++;
        return (0);
    }
    closedir(dir);
    return 0;
}