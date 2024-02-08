#include "stdio.h" 

void registeration();

typedef struct{
    int user_ph;
    short user_id;
    char user_address[30];
    char user_email[30];
    char user_password[30];
    char user_name[30];
    short user_birYear;
    short user_postal;
    
}users;

global_users = 0;
users user[10];

int main(){
    int input = 0;
   // printf("%d", example(input));
    printf("Please type 1 to register : ");
    scanf("%d", &input);

    if(input == 1)
    registeration();
    else
    printf("invalid input, please type 1");
    
    printf("user contact number : %d", user[0].user_ph);
    
    FILE *fptr = fopen("database.txt", "a");
    if(!fptr)
        perror("Error, unable to open file\n");
    else
        fwrite(&user[0].user_ph, sizeof(user[0].user_ph), 1, fptr); 
        
    fclose(fptr);    

    return 0;
} 

void registeration(){

    int ph_num = 0;
    printf("This is the registeration page");

    printf("\nPlease enter your mobile number : "); 
    scanf("%d", &ph_num);
    user[0].user_ph = ph_num;

    printf("\nPlease enter your email : ");
    scanf(" %[^\n]", &user[global_users].user_email);

    printf("\nPlease enter your username : ");
    scanf(" %[^\n]", &user[global_users].user_name);

    printf("\nPlease enter your address : ");
    scanf(" %[^\n]", &user[global_users].user_address);
    
    printf("\nPlease enter your birthyear : ");
    scanf(" %[^\n]", &user[global_users].user_birYear);
    
    printf("\nPlease enter your postal code : ");
    scanf(" %[^\n]", &user[global_users].user_postal);

    printf("\nPlease enter your password: ");
    scanf(" %[^\n]", &user[global_users].user_password);

}


void copy_arr(char Arr1[30], char Arr2[30]){
    int size = get_arr_size(Arr2);
    int receiver_size = get_arr_size(Arr1);
    for (int i=0; i<receiver_size; i++){
        Arr1[i] = '\0';
    }
    for(int ii=0; ii<size; ii++){
        Arr1[ii] = Arr2[ii];
    }
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