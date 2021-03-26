#include <stdio.h>

int work(int** arr, int* size)
{
   int a=32, b;
   __asm__("mov r1, %1\n\t"
           "mov r2, %2\n\t"
           "mov r12, #0\n\t"
           "ldr r10, [r2]\n\t"
           "add r2, r2, #4\n\t"
           "ldr r11, [r2]\n\t"
           "mov r8, #0\n\t"
           "loop_x:\n\t"
             "cmp r8, r10\n\t"
             "beq end_x\n\t"
             "ldr r6, [r1]\n\t"
             "mov r9, #0\n\t"
             "loop_y:\n\t"
               "cmp r9, r11\n\t"
               "beq end_y\n\t"
               "ldr r3, [r6]\n\t"
               "mul r3, r3, r3\n\t"
               "add r12, r12, r3\n\t"
               "add r6, r6, #4\n\t"
               "add r9, r9, #1\n\t"
               "b loop_y\n\t"
             "end_y:\n\t"
             "add r8, r8, #1\n\t"
             "add r1, r1, #4\n\t"
             "b loop_x\n\t"
           "end_x:\n\t"
           "mov %0, r12"
           :"=r"(b)
           :"r"(arr), "r"(size)
          );

   return b;
}

int main()
{
    int size[2];
    printf("Enter array size (2 parameters):\n");
    scanf("%d", &size[0]);
    scanf("%d", &size[1]);
    printf("\nEnter numbers:\n");

    int** arr = new int*[size[0]];
    for (int i=0; i<size[0]; i++)
    {
        arr[i] = new int[size[1]];
        for(int j=0; j<size[1]; j++)
        {
            printf("[%d, %d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    int res = work(arr, size);
    printf("%d\n", res);
    for (int i=0; i<size[0]; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
