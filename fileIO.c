#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *a,*p;
	FILE *fp1,*fp2;
	int len,tot;

	fp1 = fopen("../video/input.txt","rb");
	if (fp1 == NULL)
		printf("error");
	fp2 = fopen("../video/output.txt","wb");
	//파일 앞의 몇개 들어 있는지 정보 추출
	fscanf(fp1,"%d %d ",&len,&tot);
	//정보로 동적할당
	a = (char *) malloc(sizeof(char) * tot);
	p = a;
	//정보만큼 파일 읽기
	printf("%d %d\n",len,tot);
	for(int i=0;i<tot/len;i++)
	{
		fread(p,sizeof(char),5,fp1);
		p = p + len;
	}
	//파일 출력
	p=a;
	for(int i=0;i<tot/len;i++)
	{
		fwrite(p,sizeof(char),5,fp2);
		p = p + len;
	}
	for(int i=0;i<tot;i++)
	{
		printf("%c ",a[i]);
	}
	fclose(fp1);
	printf("\nendqw1");
}
