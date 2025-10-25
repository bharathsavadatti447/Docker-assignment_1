#include <stdio.h>

int main() {
    int num = 17, i, flag = 0;

    if (num <= 1) 
        flag = 1;

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        printf("%d is a Prime Number\n", num);  // Use \n, not \\n
    else
        printf("%d is not a Prime Number\n", num);

    return 0;
}
