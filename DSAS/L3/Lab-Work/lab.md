# DSA-I Lab Report formate:

## <mark>Name of the Experiment:</mark>  
Study of Pointer and its Operations

## Objective:
    1. to+verb
    2. verb+ing
    3. to know the basic operation of pointer

## Introduction:
....
#### Arithmatic Operation of Pointer:
...


## Source Code:
```
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
```

## Output:
```
Value to Search: 4
Found!
4444
4444
4444
bc9ffdd8
bc9ffdd8
bc9ffdd0
bc9ffdc6
10 Nahid
100 Hasan
200 Arif
```

## Discussion:
...(4-6 lines)