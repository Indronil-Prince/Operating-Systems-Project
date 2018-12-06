#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlength(string ch)
{
        uint16 i = 0;
        while(ch[i]) i++;  
        return i;
}


uint8 strEql(string ch1,string ch2)                     
{
        uint8 result = 1;
        uint8 size = strlength(ch1);
        if(size != strlength(ch2)) result =0;
        else 
        {
			uint8 i = 0;
			for(i;i<size;i++)
			{
				if(ch1[i] != ch2[i]) result = 0;
			}
        }
        return result;
}

string strcat(string ch1,string ch2)                     
{
	string result;    
	uint8 size1 = strlength(ch1);
	uint8 size2 = strlength(ch2);
		uint8 i = 0;
			for(i;i<size2;i++)
			{
				result[size1+i]=ch2[i];
			}
        return result;
}
uint16 atoi(string ch)
{
	uint16 i=0, res=0, temp=1, len= strlength(ch);
	while(len--){
	temp = ch[i]-'0';
	uint16 x=len;
	while(x--){
		temp*=10;
	}
	res+=temp;
	i++;	
	}
	return res;
}

#endif
