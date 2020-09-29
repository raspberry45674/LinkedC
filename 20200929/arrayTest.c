#include <stdio.h>
void funcInputArray(int [] , int , int , int);
void funcDeleteArray(int arr[], int userSet, int userInput);
int main() {
    int userSet = 0;
    int count = 0;
    int arrayA[20] = {0, };

    printf("몇 개의 숫자를 입력 하시겠습니까?(10개 이하만 가능)");
    fscanf(stdin, "%d", &userSet);

    while (userSet > count)
    {
        printf("숫자를 입력하세요 .");
        fscanf(stdin, "%d", &arrayA[count]);
        ++count;
    }
    printf("몇 번째에 어떤 숫자를 입력하시겠씁니까?");
    int userInput = 0;
    fscanf(stdin, "%d%d", &count, &userInput);
    
    
    funcInputArray(arrayA, userSet, count, userInput);

    printf("몇 번째에 숫자를 삭제하시겠씁니까?");
    fscanf(stdin, "%d", &userInput);
    funcDeleteArray(arrayA, userSet, userInput);
    
    
    return 0;
}
void funcInputArray(int arr[] , int userSet, int count, int userInput) {
    int deepCopy[20];
    for (int i = 0; i < userSet; i++)
    {
        deepCopy[i] = arr[i];
    }
    arr[count-1] = userInput;
    
    for (int i = count; i < userSet; i++)
    {
        arr[i] = deepCopy[i];
    }
    
    for (int i = 0; i < userSet; i++)
    {
        fprintf(stdout, "%d ", arr[i]);
    }
    printf("\n");
}

void funcDeleteArray(int arr[], int userSet, int userInput) {
    int deepCopy[20];
    for (int i = 0; i < userSet; i++)
    {
        deepCopy[i] = arr[i];
    }

    for (int i = userInput; i < userSet; i++)
    {
        arr[i - 1] = deepCopy[i];
    }
    
    for (int i = 0; i < userSet -1; i++)
    {
        fprintf(stdout, "%d ", arr[i]);
    }
    printf("\n");
}