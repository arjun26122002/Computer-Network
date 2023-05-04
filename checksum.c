#include <stdio.h>
#include <string.h>

void checksum(char wrappedsum[], int n, char checkSum1[])
{
    for (int i = 0; i < n; i++)
    {
        if (wrappedsum[i] == '1')
        {
            checkSum1[i] = '0';
        }
        else if (wrappedsum[i] == '0')
        {
            checkSum1[i] = '1';
        }
        else
            printf("ERROR");
    }
}
int main()
{
    printf("\n\n SENDER SIDE : \n");
    char data1[10] = {0}, data2[10] = {0}, data3[10] = {0}, data4[10] = {0},
         data5[10] = {0}, checkSum1[10] = {0},checkSum2[10] = {0} ,wrappedsum[10] = {0},wrappedsum1[10] = {0} ;
    int carry = 0, num = 0, i = 0;

    printf("\n 1st Data :");
    scanf("%s", data1);
    printf("\n 2nd Data :");
    scanf("%s", data2);

    int n = strlen(data1);
    for (i = n - 1; i >= 0; i--)
    {
        num = (data1[i] - '0') + (data2[i] - '0') + (carry);
        wrappedsum[i] = (num % 2) + '0';
        carry = num / 2;
    }
    i = n - 1;
    while (carry)
    {
        if (i < 0)
        {
            i = n - 1;
        }
        num = (wrappedsum[i] - '0') + (carry);
        wrappedsum[i] = (num % 2) + '0';
        carry = num / 2;
        i--;
    }
    checksum(wrappedsum, n, checkSum1);

    printf("\nSENDER-----\nData - 1: %s\nData - 2: %s\nwrappedSum - 1: %s\ncheckSum - 1: %s\n", data1, data2, wrappedsum, checkSum1);
     printf("\n\nReceiver Side\n");
    printf("\n 1st Data: ");
    scanf("%s", data3);
    printf(" 2nd Data: ");
    scanf("%s", data4);
    printf(" 3rd data: ");
    scanf("%s", data5);

    int m = strlen(data3);
    for (i = m - 1; i >= 0; i--)
    {
        num = (data3[i] - '0') + (data4[i] - '0') + (data5[i] - '0') + (carry);
        wrappedsum1[i] = (num % 2) + '0';
        carry = num / 2;
    }
    i = m - 1;
    while (carry)
    {
        if (i < 0)
        {
            i = m - 1;
        }
        num = (wrappedsum1[i] - '0') + (carry);
        wrappedsum1[i] = (num % 2) + '0';
        carry = num / 2;
        i--;
    }
    // for (i = 0; i < m; i++)
    // {
    //     if (wrappedsum1[i] == '1')
    //     {
    //         checkSum2[i] = '0';
    //     }
    //     else if (wrappedsum1[i] == '0')
    //     {
    //         checkSum2[i] = '1';
    //     }
    //     else
    //         printf("ERROR");
    // }
    checksum(wrappedsum1, m, checkSum2);
    printf("\n\nRECIVER:\nData - 1: %s\nData - 2: %s\nData -3: %s\nwrappedsum-2: %s\ncheckSum -2: %s\n\n", data3, data4, data5, wrappedsum1, checkSum2);

    for (i = 0; i < n; i++)
    {
        if (checkSum2[i] -'0')
        {
            printf("\n\n UNSUCCESFULL\n\n");
            return 0;
        }
    }

    printf("\n\n SUCCESFULL\n\n");
    return 1;
}