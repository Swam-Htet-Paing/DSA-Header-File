#include "stdio.h"

int get_arr_size(char arr[]);
void copy_arr(char Arr1[30], char Arr2[30]);

char array2[] = {'N','i','c','e','!'};
int a = 0;
char simple_array[] = {'L','i','n','u','x','x'};


int main(){

    printf("size is %d\n", get_arr_size(array2));
    copy_arr(simple_array, array2);

    printf("%c", simple_array[0]);
    printf("%c", simple_array[1]);
    printf("%c", simple_array[2]);
    printf("%c", simple_array[3]);
    printf("%c", simple_array[4]);
    printf("\n");
    return 0;

}

int get_arr_size(char arr[]){
    int size=0;
    int index = 0;

    while(arr[index]!='\0'){
        size++;
        index++;
    }

    return size;
}

void copy_arr(char Arr1[30], char Arr2[30]){
    int size = get_arr_size(Arr2);
    int receiver_size = get_arr_size(Arr1);
    for (int i=0; i<receiver_size; i++){
        Arr1[i] == '\0';
    }
    for(int ii=0; ii<size; ii++){
        Arr1[ii] = Arr2[ii];
    }
}