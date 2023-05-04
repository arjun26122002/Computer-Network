#include <stdio.h>

int main()
{
    int m,n,a[100],b[100],c[100];
    printf("Enter the length of dividend:");
    scanf("%d",&m);
    printf("Enter the dividend:");
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the length of divisor:");
    scanf("%d",&n);
    printf("Enter the divisor:");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int bit=n-1;
    for(int i=m;i<(n+bit);i++){
        a[i]=0;
    }
    printf("New dividend is:");
    for(int i=0;i<(m+bit);i++){
        printf("%d",a[i]);
}
    for(int i=0;i<(m+bit);i++){
        c[i]=a[i];
    }
     for (int i = 0; i <=((m+bit)-n); i++) {
        if (c[i] == 1) {
            // XOR operation
            for (int j = 0; j < n; j++) {
                c[i + j] = (c[i + j] == b[j]) ? 0 : 1;
            }
        }
    }
    printf("\n");
    printf("CRC:");
    for(int i=m;i<(m+bit);i++){
        printf("%d",c[i]);
    }
    for(int i=m;i<(m+bit);i++){
        a[i]=c[i];
    }
    printf("\n");
    printf("DATA+CRC:");
for(int i=0;i<(m+bit);i++){
        printf("%d",a[i]);
    
}
}