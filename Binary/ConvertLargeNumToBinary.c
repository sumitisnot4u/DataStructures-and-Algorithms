//Question : Convert a Large Decimal Number represented as a string into binary.
//Time Complexity: O(logn)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ConvertIntoBinary(char *num,char*answer)
{
    char*binary = malloc(10000*sizeof(char));
    int i =0;
    while(strlen(num)>0)
    {
        binary[i] = (num[strlen(num)-1] -'0')%2 +'0';  
        //printf("len:%ld\n",strlen(num));
        char *ans = malloc(10000*sizeof(char));
        char *temp = malloc(10000*sizeof(char));
        int len_num = strlen(num);
        for(int i =len_num-1;i>=0;i--)
        {
            int carry =0;
            if(i<=len_num -2 && (num[i]-'0')%2 == 1)
            {
                temp[i+1] +=  5;
                if(temp[i+1] >=58)
                {
                    temp[i+1] = '0';
                    carry = 1;
                } 
            }
            temp[i] = ((num[i] -'0')/2) + '0' + carry;
        }
        int k =0;
        while(temp[k] == '0')
            k++;
        for(int i =0;i<strlen(temp)-k;i++)
            ans[i] = temp[i+k];
        num = ans;
        //printf("%s\n",num);
        i++;
    }
    int k =0;
    for(k =0;k<strlen(binary);k++)
        answer[k] = binary[strlen(binary)-k-1];
    answer[k+1] = '\0';

}

int main()
{
    char * num = malloc(1000*sizeof(char));
    char * answer = malloc(1000*sizeof(char));
    scanf("%s",num);
    ConvertIntoBinary(num,answer);
    printf("%s\n",answer);
    return 0;
}




