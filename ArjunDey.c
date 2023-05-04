#include <stdio.h>
#include <string.h>

void CheckSum(char WrappedSum1[], int n, char CheckSum1[])
{
    for (int i = 0; i < n; i++)
    {
        if (WrappedSum1[i] == '0')
        {
            CheckSum1[i] = '1';
        }
        else
        {
            CheckSum1[i] = '0';
        }
    }
}

int main()
{
    printf("\n\n SENDER SIDE : \n");
    char binary1[6], binary2[6], CheckSum1[6], WrappedSum1[6];
    int i = 0, carry1 = 0, carry2 = 0, num;

    printf("Enter the input data1 for Sender : ");
    scanf("%s", binary1);
    printf("Enter the input Data2 for Sender : ");
    scanf("%s", binary2);

    int n = strlen(binary1);

    for (i = n - 1; i >= 0; i--)
    {
        num = (binary1[i] - '0') + (binary2[i] - '0') + (carry1);
        WrappedSum1[i] = (num % 2) + '0';
        carry1 = num / 2;
    }
    i = n - 1;
    while (carry1)
    {
        if (i < 0)
        {
            i = n - 1;
        }
        num = (WrappedSum1[i] - '0') + (carry1);
        WrappedSum1[i] = (num % 2) + '0';
        carry1 = num / 2;
        i--;
    }
    CheckSum(WrappedSum1, n, CheckSum1);

    printf("\nSENDER-----\nData - 1: %s\nData - 2: %s\nWrappedSum - 1: %s\nCheckSum - 1: %s\n", binary1, binary2, WrappedSum1, CheckSum1);

    printf("\n\nReceiver Side\n");
    char binary3[6], binary4[6], binary5[6], CheckSum2[6], WrappedSum2[6];
    int j = 0;

    printf("Enter the input data1 for Receiver : ");
    scanf("%s", binary3);
    printf("Enter the input Data2 for Receiver : ");
    scanf("%s", binary4);
    printf("Enter the input Data3 for Receiver : ");
    scanf("%s", binary5);

    int m = strlen(binary3);

    for (j = m - 1; j >= 0; j--)
    {
        num = (binary3[j] - '0') + (binary4[j] - '0') + (binary5[j] - '0') + (carry2);
        WrappedSum2[j] = (num % 2) + '0';
        carry2 = num / 2;
    }
    j = m - 1;
    while (carry2)
    {
        if (j < 0)
        {
            j = m - 1;
        }
        num = (WrappedSum2[j] - '0') + (carry2);
        WrappedSum2[j] = (num % 2) + '0';
        carry2 = num / 2;
        j--;
    }
    CheckSum(WrappedSum2, m, CheckSum2);

    printf("\nReceiver ----\nData - 1: %s\nData - 2: %s\nData - 3: %s\nWrappedSum - 2: %s\nCheckSum - 2: %s\n", binary3, binary4, binary5, WrappedSum2, CheckSum2);

    int k = 0, z = strlen(CheckSum2), ans = 0;
    for (k = 0; k < z; k++)
    {
        if (CheckSum2[k] == '0')
        {
            ans = 1;
            break;
        } 
    }
    
    if(ans == 0) {
        printf("\nSuccessful.");
    } else {
        printf("\nUnsuccessful.");
    }
    
}
