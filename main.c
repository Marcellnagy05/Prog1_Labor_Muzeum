#include <stdio.h>
#include <stdlib.h>

int main(){
    int days,customers; //! Vars we read into
    int *daysArr = NULL; //! Dynamic array to store the days
    int *customersArr = NULL; //! Dynamic array to store the customers
    int count = 0; //! The size of the arrays
    char *daysOfTheWeek[7] = {"Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; //* Storing the days of the week only for style purposes

    //! Always runs but the break in line [16] will exit this loop on the desired condition
    while(1){
        //! Reading the values
        printf("Enter two numbers (space between), Enter -1 -1 to exit\t");
        if(scanf("%d %d",&days,&customers) != 2) break;

        //! This is the exit condition of the while loop
        if(days == -1 && customers == -1) break;

        //if(days == -1 || customers == -1 && days != customers) break;
        
        //! Check if element already present in the array
        for(int i = 0; i < count; i++){
            if(days == daysArr[i]) customersArr[i] += customers;
        }
        
        //! Reallocating arrays to have space for 1 more element
        int *tmpDays = realloc(daysArr, (count + 1) * sizeof(int));
        int *tmpCustomers = realloc(customersArr, (count + 1) * sizeof(int));

        //! Checking if the memory allocation succeded if not throws an error
        if(!tmpDays || !tmpCustomers){
            printf("Memory allocation failed\n");
            free(daysArr); //! On faliure free any memory in line[34,35]
            free(customersArr);
            return 1;
        }

        //! Assigning the resized arrays to the main pointers
        daysArr = tmpDays;
        customersArr = tmpCustomers;

        daysArr[count] = days;
        customersArr[count] = customers;
        count++;
    }

    //* Print all the stored elements of both arrays
    printf("Stored numbers: ");
    for(int i = 0; i < count; i++){
        printf("%3d.day: %d customer(s) ", daysArr[i], customersArr[i]);
    }

    int index = 0; //! Helper index to access the [index] element in line[64]
    int max = customersArr[0]; //! Assigning the max var the first element of the customer array
    for(int i = 0; i < count; i++){ //! Looping through the array to find the biggest element 
        if(max < customersArr[i]){
            max = customersArr[i];
            index = i;
            //printf("\nindex: %d",i);
        }
    }

    //! Printing out the max day of the week(its index) and the number of customers
    printf("\nThe most profitable day was %s(%d.index) with %d customer", daysOfTheWeek[daysArr[index]],daysArr[index],customersArr[index]);

    //! Free both arrays in line[67,68]
    free(daysArr);
    free(customersArr);
    return 0;
}