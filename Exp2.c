/*Encryption by Substitution Method*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
char seq[36]="qwertyuiopasdfghjklzxcvvnm1234567890";
char data[50];
char encoded[50];
int i,j,len,present=0;
printf("\nEnter data:");
gets(data);
len=strlen(data);
for(i=0;i<len;i++)
{
if(isupper(data[i]))
encoded[i]=seq[data[i]-'A'];
else if(islower(data[i]))
encoded[i]=toupper(seq[data[i]-'a']);
else if(isdigit(data[i]))
encoded[i]=seq[data[i]-'0'+26];
else
encoded[i]=data[i];
}
encoded[len]='\0';
printf("\n encoded string is:%s",encoded);
return 0;
}
/*Decryption by Substitution Method*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void main()
{
char seq[36]="qwertyuiopasdfghjklzxcvbnm1234567890";
char data[100];
char decoded[100];
int i,j,len,present=0;
printf("\n Enter data:");
gets(data);
len=strlen(data);
for(i=0;i<len;i++)
{
for(j=0;j<36 && !present;++j)
{
if(seq[j]==tolower(data[i]))
{
if(isupper(data[i]))
decoded[i]='a'+j;
else if(islower(data[i]))
decoded[i]='A'+j;
else decoded[i]='0'+(j-26);
present=1;
}
}
if(!present)
decoded[i]=data[i];
else
present=0;
}
decoded[len]='\0';
printf("\n Decoded string is:%s", decoded);
}


/*Encryption by Transposition Method */
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char data[100];
char wrd[]="MEGABUCK";
char cipher[20][8];
int seq[8];
int i,j,k,cnt;
for(i=0;i<strlen(wrd);i++)
{
cnt=0;
for(j=0;j<8;j++)
if(wrd[i]>wrd[j])
++cnt;
seq[i]=cnt;
}
printf("\n Enter data :");
gets(data);
cnt=strlen(data);
for(i=0;i<cnt;i++)
cipher[i/strlen(wrd)][i%strlen(wrd)]=data[i];
if(i%strlen(wrd)!=0)
{
for(j=i%strlen(wrd);j<strlen(wrd);j++)
{
cipher[i/strlen(wrd)][j]='.';
cnt++;
}
}
printf("\n Encrypted data :\n");
for(i=0;i<8;i++)
{
for(j=0;j<8;j++)
if(seq[j]==i) break;
for(k=0;k<cnt/8||k==0;k++)
printf("%c",cipher[k][j]);
}
}
/*Decryption by using Transposition Method*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
char data[100];
char wrd[]="MEGABUCK";
char cipher[20][8];
int seq[8];
int i,j,cnt,c;
for(i=0;i<strlen(wrd);i++)
{
cnt=0;
for(j=0;j<strlen(wrd);j++)
if(wrd[i]>wrd[j])
++cnt;
seq[i]=cnt;
}
printf("\nEnter data :");
gets(data);
cnt=strlen(data);
if(cnt%strlen(wrd)!=0)
printf("\nError: Invalid Input");
else
{
for(i=0;i<8;i++)
{
for(c=0;c<8;c++)
if(seq[c]==i)
break;
for(j=0;j<cnt/strlen(wrd);j++)
cipher[j][c]=data[i*(cnt/strlen(wrd))+j];
}
for(j=0;j<strlen(wrd);j++)
{
if(cipher[cnt/strlen(wrd)-1][j]=='.')
cipher[cnt/strlen(wrd)][i%strlen(wrd)]==' ';
}
printf("Decrypted data:");
for(i=0;i<cnt;i++)
printf("%c",cipher[i/strlen(wrd)][i%strlen(wrd)]);
}
return 0;
}