/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


float average(list l) {
    
    float r = 0.0;
    float elem;
    list aux = l;
    
    int largo = len(aux);
    
    while(!is_empty(aux)){
        elem = head(aux);
        r = r + elem;
        aux = tail(aux);
    }
       
    if (largo !=0){
        r = r/largo;
    }
    else
    {
        r = 0.0;
    }
    
    return r;
}


list array_to_list(int array[], unsigned int length) {

    
    list l = empty();// malloc(sizeof(struct Node));
    
    for (unsigned int i = 0u; i < length; ++i) {
        l = addr(l, array[i]);
        
    }
    
    
    return l;
}

void printlist(list l, char comment[50]){
    list aux = l;
    printf("%s ",comment);
    while(aux != NULL){ 
        printf("%d ",aux->elem); 
        aux = aux->next;
    }
     
    printf("\n\n");
}

void try_list_ops(list l){
    /*call list functions*/
    list aux = copy(l);

    printf("Length of l: %d\n",len(aux));
    printf("Head of l: %d\n",head(aux));
 
    printlist(tail(aux),"Tail of l:");
    
    printlist(aux,"Copy of l:");

    list p = addl(aux,20);
    printlist(p,"Add 20 at l's first position:");
        
    list q = copy(l);
    q = addr(q,30);
    printlist(q, "Add 30 at l's last position:");
    
    list t = empty();
    int i = 0;
    while (i<10){
      t = addl(t, i);
      i++;
    }
    printlist(l,"l:");
    printlist(t,"t:");
    list r = concat(t,l);
    printlist(r,"Concat t and l:");
    
    printf("Index 4 of l: %d\n", index(aux,4));
       
    list taken = copy(l);
    taken = take(taken, 3);
    printlist(taken,"Take 3 elements from l:");
    
    list d = drop(l,3);
    printlist(d,"Drop 3 elements from l:");
    
    free(p);
    destroy_list(q);
    destroy_list(taken);
    destroy_list(r);
    destroy_list(aux);
}
int main(int argc, char *argv[]) {
    char *filepath = NULL;
   // FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* call the average function */
    printf("The average is: %.2f \n", average(l));
    
    try_list_ops(l);
    
    destroy_list(l);
    
    return (EXIT_SUCCESS);
}
