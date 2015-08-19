#include <stdio.h>
#include <fcntl.h>
int main()
{
    int rfd,rfd1, rfd2,b,rfd4,rfd3,d, j, k = 0, flag = 1, index[2], d1, i ,d3,p=0,p1,p2=0;
    int8_t a; 
    char c[2],temp, ma[15], in[3],ans[2],in1[3],arr1[3],ch='n';
    rfd = open("test.txt", O_RDONLY, 0);
    rfd1 = open("out.txt", O_WRONLY, 0);
    d = read(rfd, c, 1);
    c[1]='\0';
    ma[k] = c[0];
    while(d = read(rfd, c, 1))
    {
	++p ;
	for(j = 0; j<=k; j++)
	{
	    if(ma[j] == c[0])
	    {
		flag=0;

	    }
	}
	if(flag==1)
	{
	    k++;
	    ma[k] = c[0];
	    flag = 1;

	}
	flag=1;

    }
    p1=p;

    rfd2 = open("test.txt", O_RDONLY, 0);
    while(d1=read(rfd2, in, 2))
    {
	p2++;
	in[2] ='\0';

	for(i=0; i<2; i++)
	{
	    for(j=0;j<=k;j++)
	    {
		if(in[i] == ma[j])
		{
		    index[i] = j;
		}
	    }
	}
	if(in[0] == '.' | in[1] == '.')
	    break;
	index[1] = index[1] <<4; 

	ans[0] = (char)(index[0] | index[1]);

	ans[1] = '\0';


	write(rfd1, ans, 1);
	p1=p1-2;
	if(p1<0)
	    break;
    }
    printf("File compression successfull!!!\n");
    printf("Want to decompress the file(y/n):");
    scanf("%c",&ch);
    if(ch == 'y' || ch == 'Y')
    {
	rfd4 = open("out.txt",O_RDONLY);
	rfd3 = open("decom.txt",O_WRONLY);
	int e;
	while(d3=read(rfd4, in1, 1))
	{

	    in1[1]='\0';

	    a=((int8_t)in1[0])<<4;
	    arr1[0]=ma[e=a>>4];



	    arr1[1]=ma[b=( (int8_t)in1[0]>>4)];

	    arr1[2]='\0';

	    write(rfd3, arr1, 2);
	    --p2;
	    if(p2<1)
		break;


	}
	printf("Decompression successfull!!\n");
    }

    return 0;
}

