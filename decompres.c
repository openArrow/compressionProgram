#include<stdio.h>
#include<fcntl.h>
main()
{
    int rfd,rfd1,d;
    rfd2 = open("out.txt",O_RDONLY);
    rfd3 = open("decom.txt",O_WRONLY);
    char in[3],arr1[3];
    while(d3=read(rfd2, in,1 ))
    { 
	
	in[1]='\0';
//	printf("%s\n", in);
	arr1[0]=(char)( ((int)in[0]<<4)>>4);
	printf("%d\n",(int)arr1[0]);
	arr1[1]=(char)( (int)in[0]>>4);
	arr1[2]='\0';
	//printf("hi\n");
	write(rfd3, arr1, 2);
    }
    return 0;
} 
