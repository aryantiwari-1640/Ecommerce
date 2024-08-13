#include <stdio.h>
#include <string.h>
int div_N=0;
int data_N=0;
short i,j;
void XOR(char *chck,char *div)
    {  
        j=1;
        while(j<div_N)
            {
                chck[j]=(chck[j]==div[j]?'0':'1');
                j++;
            }
    }
void crc(char *data,char *chck, char *div)
    {
        for(i=0;i<div_N;i++)
            {
                chck[i]=data[i];
            }
        do
            {
                if(chck[0]=='1')
                    XOR(chck,div);
                for(j=0;j<div_N-1;j++)
                    {
                        chck[j]=chck[j+1];
                    }
                chck[j]=data[i++];
            }while(i<=data_N+div_N-1);
        chck[++j]='\0';
        for(j=data_N;j<data_N+div_N-1;j++)
            data[j]=chck[j-data_N];  
    }
int main()
    {  
        char data[50],div[50],chck[50];
        printf("Enter the Data to be transmitted:");
        scanf("%s",data);
        data_N=strlen(data);
        printf("\nEnter the divisor:");
        scanf("%s",div);
        div_N=strlen(div);
        for(i=data_N;i<data_N+div_N-1;i++)
            {
                data[i]='0';
            }
        data[i]='\0';
        crc(data,chck,div);
        printf("\nCRC value is:%s",chck);
        printf("\nData to be transmitted:%s",data);
        crc(data,chck,div);//Receive part
        for(j=0;(j<div_N &&chck[j]!='1');j++);
        if(j<div_N)
            printf("\nError!");
        else
            printf("\nNo error");
    }