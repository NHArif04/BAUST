#include <stdio.h>
#include <time.h>

void linearSearch(int *arr, int target){
    while (*arr!=NULL){
        if (*arr++ == target){
            printf("Found!\n");
            return;
        }
    }
    printf("Not Found!\n");
}

int main(){
    int ara[] = {2, 3, 4, 5};
    int key;
    printf("Value to Search: ");
    scanf("%d", &key);
    int *ptr = ara;
    linearSearch(ptr, key);
    
    int n = 4444;
    int *p = &n;
    int **p2 = &p;
    **p2+=1;
    char v2[10];
    printf("%d\n%d\n%d\n%x\n%x\n%x\n%x\n", n, *p, **p2, p, *p2, p2, &v2);

    int arr[] = {10, 100, 200};
    int i, *pArr[3];
    char *sArr[] = {"Nahid", "Hasan", "Arif"};

    for (i = 0; i < 3; i++){
        pArr[i] = &arr[i];
        printf("%d %s\n", *pArr[i], sArr[i]);
    }
    return 0;
}