#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

//gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o a
//./a

int main(void)
{
    int fd = open("text.txt", O_RDONLY); // Abrir archivo en modo lectura
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Archivo abierto correctamente.\n");

    char *line;

//    line = get_next_line(fd);
//    printf("%s", line);

    
    while ((line = get_next_line(fd)) != NULL) // Leer línea por línea
    {
        printf("%s", line);
        free(line);
    }
    

    printf("Fin");

    close(fd); // Cerrar el archivo
    return (0);
}
