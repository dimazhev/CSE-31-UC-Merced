#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// DO NOT INCLUDE OTHER LIBRARY!

// Declarations of the two functions you will implement
// Feel free to declare any helper functions
void printPuzzle(char** arr, int n);
void searchPuzzle(char** arr, int n, char** list, int listSize);
int LeftToRight(char** arr, int n, char* word);
int RightToLeft(char** arr, int n, char* word);
int TopToBottom(char** arr, int n, char* word);
int BottomToTop(char** arr, int n, char* word);
int TopleftToBotright(char** arr, int n, char* word);
int BotleftToTopright(char** arr, int n, char* word);
void convertToLowerCase(char** arr, int wordSize, int arrSize, int row, int col, int type);
// Main function, DO NOT MODIFY!!!
int main(int argc, char **argv) {
    int bSize = 15;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;
    char **block = (char**)malloc(bSize * sizeof(char*));
    char **words = (char**)malloc(50 * sizeof(char*));

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read puzzle block into 2D arrays
    for(i=0; i<bSize; i++){
        *(block+i) = (char*)malloc(bSize * sizeof(char));

        fscanf(fptr, "%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(block+i), *(block+i)+1, *(block+i)+2, *(block+i)+3, *(block+i)+4, *(block+i)+5, *(block+i)+6, *(block+i)+7, *(block+i)+8, *(block+i)+9, *(block+i)+10, *(block+i)+11, *(block+i)+12, *(block+i)+13, *(block+i)+14 );
    }
    fclose(fptr);

    // Open file for reading word list
    fptr = fopen("states.txt", "r");
    if (fptr == NULL) {
        printf("Cannot Open Words File!\n");
        return 0;
    }
    
    // Save words into arrays
    for(i=0; i<50; i++){
        *(words+i) = (char*)malloc(20 * sizeof(char));
        fgets(*(words+i), 20, fptr);
    }
    
    // Remove newline characters from each word (except for the last word)
    for(i=0; i<49; i++){
        *(*(words+i) + strlen(*(words+i))-2) = '\0';
    }
    
    // Print out word list
    printf("Printing list of words:\n");
    for(i=0; i<50; i++){
        printf("%s\n", *(words + i));
    }
    printf("\n");
    
    // Print out original puzzle grid
    printf("Printing puzzle before search:\n");
    printPuzzle(block, bSize);
    printf("\n");

    // Call searchPuzzle to find all words in the puzzle
    searchPuzzle(block, bSize, words, 50);
    printf("\n");
    
    // Print out final puzzle grid with found words in lower case
    printf("Printing puzzle after search:\n");
    printPuzzle(block, bSize);
    printf("\n");
    
    return 0;
}

void printPuzzle(char** arr, int n){
    // This function will print out the complete puzzle grid (arr). It must produce the output in the SAME format as the samples in the instructions.
    // Your implementation here
  int i;
     for(i=0;i<n;i++)
     {
     printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", *(*(arr+i)), *(*(arr+i)+1),
	 *(*(arr+i)+2), *(*(arr+i)+3), *(*(arr+i)+4), *(*(arr+i)+5), *(*(arr+i)+6), *(*(arr+i)+7),
	 *(*(arr+i)+8), *(*(arr+i)+9), *(*(arr+i)+10), *(*(arr+i)+11), *(*(arr+i)+12), *(*(arr+i)+13), *(*(arr+i)+14) );
     }

}

void searchPuzzle(char** arr, int n, char** list, int listSize){
    // This function checks if arr contains words from list. If a word appears in arr, it will print out that word and then convert that word entry in arr into lower case.
    // Your implementation here
    int i=0;
    int foundwords = 0;
    for(i=0; i<listSize; i++){

        if(LeftToRight(arr, n, list[i]) ||
            TopToBottom(arr, n, list[i]) ||
            BottomToTop(arr, n, list[i]) ||
            TopleftToBotright(arr, n, list[i]) ||
            BotleftToTopright(arr, n, list[i])){
           printf("Word found: %s\n", list[i]);
          foundwords++;}
      
    }

    }

    int LeftToRight(char** arr, int n, char* word){
      
       int size = strlen(word);
       int i=0, j=0, index=0;
       for(i=0; i<n; i++){
           for(j=0; j<n-size; j++){
           index=0;
           while(index<size){
                    if(tolower(*(word+index))==tolower(*(*(arr+i)+index+j))){
                   if(index == size-1){
                       convertToLowerCase(arr, size, n, i, j, 1);
                       return 1;;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }

    int RightToLeft(char** arr, int n, char* word){
      
       int size = strlen(word);
      
       int i=0, j=0, index=0;
       for(i=0; i<n; i++){
           for(j=n-1; j>=size-1; j--){
           index=0;
           while(index<size){
                    if(tolower(*(word+index))==tolower(*(*(arr+i)+j-index))){
                   if(index == size-1){
                       convertToLowerCase(arr, size, n, i, j, 2);
                       return 1;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }

    int TopToBottom(char** arr, int n, char* word){
      
       int size = strlen(word);
      
       int i=0, j=0, index=0;
       for(i=0; i<n; i++){
           for(j=0; j<n-size; j++){
           index=0;
           while(index<size){
                   if(tolower(*(word+index))==tolower(*(*(arr+index+j)+i))){
                   if(index == size-1){
                       convertToLowerCase(arr, size, n, j, i, 3);
                       return 1;;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }
    int BottomToTop(char** arr, int n, char* word){
      
       int size = strlen(word);
       int i=0, j=0, index=0;
       for(i=0; i<n; i++){
           for(j=n-1; j>=size-1; j--){
           index=0;
           while(index<size){
          if(tolower(*(word+index))==tolower(*(*(arr+j-index)+i))){

                   if(index == size-1){
                       convertToLowerCase(arr, size, n, j, i, 4);
                       return 1;;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }

    int TopleftToBotright(char** arr, int n, char* word){
      
       int size = strlen(word);
       int i=0, j=0, index=0;
       for(i=0; i<n; i++){
           for(j=0; j<n; j++){
           index=0;
           while(index<size && (i+index<n) && (j+index<n)){
              if(tolower(*(word+index))==tolower(*(*(arr+i+index)+j+index))){
                   if(index == size-1){
                       convertToLowerCase(arr, size, n, i, j, 5);
                       return 1;;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }

    int BotleftToTopright(char** arr, int n, char* word){
      
       int size = strlen(word);
       int i=0, j=0, index=0;
       for(i=n-1; i>0; i--){
           for(j=0;j<n;j++){
           index=0;
           while(index<size && (i-index>0) && (j+index<n)){
              if(tolower(*(word+index))==tolower(*(*(arr+i-index)+j+index))){
                   if(index == size-1){
                       convertToLowerCase(arr, size, n, i, j, 6);
                       return 1;;
                   }
               }else{
                   break;
               }
               index++;
           }
           }
       }
      
       return 0;
    }

    void convertToLowerCase(char** arr, int wordSize, int arrSize, int row, int col, int type){
      
       int i,j;
      
       switch(type){
          
           case 1: //horizontal left to right
               for(j=col; j<col+wordSize; j++){
                   *(*(arr+row)+j)=tolower(*(*(arr+row)+j));
               }
               break;
           case 2:   //horizontal right to left
               for(j=col; j>col-wordSize; j--){
                   *(*(arr+row)+j)=tolower(*(*(arr+row)+j));
               }
               break;
           case 3:   //vertical top to bottom
               for(j=row; j<row+wordSize; j++){
                   *(*(arr+j)+col)=tolower(*(*(arr+j)+col));
               }
               break;
           case 4:   //vertical bottom to top
               for(j=row; j>row-wordSize ; j--){
                   *(*(arr+j)+col)=tolower(*(*(arr+j)+col));
               }
               break;
           case 5:   //diagnol topleft to bottomright
               for(j=0;j<wordSize;j++)
                   *(*(arr+row+j)+col+j) = tolower(*(*(arr+row+j)+col+j));
               break;
           case 6:   //diagnol bottomleft to topright
               for(j=0;j<wordSize;j++)
                   *(*(arr+row-j)+col+j) = tolower(*(*(arr+row-j)+col+j));
               break;
          
       }
    }


