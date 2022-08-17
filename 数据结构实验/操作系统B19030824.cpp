#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>



/*�����鸳ֵ*/ 
void setarray(int arr[], int num, int val) 
{  
	int i;
	
	for (i = 0; i < num; i++)   
		arr[i] = val; 
}

/*����һ����ά���������洢�ڴ���ҳ��仯���*/
void initarr(int **arr, int rnum, int cnum)
{
    int r, c;
    for(r = 0; r < rnum; r++)
    {
        for(c = 0; c < cnum; c++)
            arr[r][c] = -1;
    }
}

/*�����ڴ� mem ���Ƿ����ҳ�� page*/ 
int findexist(int mem[], int mnum, int page) 
{  
	int i;
	
	for (i = 0; i < mnum; i++){
		if (mem[i] == page)
			return i;  
	}
	
	return -1; 
}

/*�����ڴ� mem ���Ƿ��յ�λ��*/ 
int findempty(int mem[], int mnum) 
{  
	int i; 
	
	for (i = 0; i < mnum; i++){   
		if (mem[i] == -1)
			return i;  
	} 
	
	return -1; 
} 

/*��ӡ�ڴ���ҳ��ı仯*/
void print(int **a, int rnum, int mnum){
	
	int i = 0;
	int k = 0;
	int j;
	
    while(i < mnum)
    {
		for(j = 10 * k; j < rnum; j++)
		{	
				if(j != 10 * (k+1))
				   printf("%d\t", a[i][j]);
			   
				if(j % 10 == 0 && j != 10 * k && i == mnum-1)
				{   
					i=-1;
					k++;
					printf("\n");
					break;
				}
				
				if(j%10==0&&j!=k*10&&i!=mnum-1)
					break;
		}
		
				printf("\n");
				i++;
        
    }
}

/*�Ƚ��ȳ�ҳ���û��㷨*/ 
int fifo(int req[], int rnum, int mnum) 
{  
	int count;  
	int i, j;  
	int pos;     

	
	/*
	�����ڴ�ռ�
	ʵ���г��õ�mnum=3
	��ʼ��Ϊ-1
	*/
	/*�����ڴ�ռ�*/
    int *mem = (int *)malloc(sizeof(int ) * mnum);
    setarray(mem, mnum, -1);
	
    /*time��¼�ڴ���ÿ��ҳ������ʱ��*/
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, rnum);
	
    /*a��¼�ڴ��д�ŵ�ҳ��*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1; i < mnum; i++)
        a[i] = a[0] + i * rnum;
    initarr(a, mnum, rnum);

	/*ȱҳ������ʼʱΪ 0*/  
	count = 0; 
 
	for (i = 0; i < rnum; i++){   
	
		/*����ҳ�������Ƿ�����ڴ���*/   
		pos = findexist(mem, mnum, req[i]); 
	
		/*����ڴ��д���ҳ������*/   
		if (pos != -1){
			
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
			/*	
				a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/
			
			continue;
		}
		
		/*����ڴ��в�����ȱҳ������һ*/   
		count++; 
		
		/*�ڴ����Ƿ���ڿ�λ�ÿ��Դ����ҳ��*/   
		pos = findempty(mem, mnum); 
		
		/*���ڿ�λ�ã�ֱ�Ӵ�����ҳ�棬�����û�*/   
		if (pos != -1){
			mem[pos] = req[i];
			time[pos] = i;
			
			a[pos][i] = req[i];
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
            /*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/

			continue;
		}
	
		/*�����ڿ�λ�ã�Ѱ��Ҫ�û���ҳ�棬fifo*/
		pos = 0;
		
		for (j = 1; j < mnum; j++){
			if (time[j] < time[pos]){
				pos = j;
				}
		}
		
		mem[pos] = req[i];
		time[pos] = i;
		a[pos][i] = req[i];
        if(i < rnum-1)	//��ֹ����Խ��
        {
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
			/*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/
        }
	} 
	
	for(j = 1; j < mnum; j++){
		a[j][0] = -1;
	}
	
	/*��ӡ�ڴ���ҳ��ı仯*/
	print(a, rnum, mnum);

	free(time);		//�ͷ��ڴ�ռ�
	free(mem);
	free(a);
	
	return count;	//����ȱҳ����
	
}

/*������δʹ��ҳ���û��㷨*/
int lru(int req[], int rnum, int mnum){
	
	int count;
	int i, j;
	int pos;
	
	/*�����ڴ�ռ�*/
    int *mem = (int *)malloc(sizeof(int ) * mnum);
    setarray(mem, mnum, -1);
	
    /*time��¼�ڴ���ÿ��ҳ������ʱ��*/
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, rnum);
	
    /*a��¼�ڴ��д�ŵ�ҳ��*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1; i < mnum; i++)
        a[i] = a[0] + i * rnum;
	
    initarr(a, mnum, rnum);
	
    /*ȱҳ�ʳ�ʼʱΪ 0*/
	count = 0; 
	
	for (i = 0; i < rnum; i++){
		
		/*����ҳ�������Ƿ�����ڴ���*/
		pos = findexist(mem, mnum, req[i]); 
		
		/*����ڴ��д���ҳ�����󣬴˴��� fifo ��Щ������*/
		if (pos != -1){
			time[pos] = i;	//�˴� lru ��¼�������һ�εķ���ʱ�䣬�� fifo �м�¼������ �Ƚ����ʱ��
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
			/*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/

			continue;
		}
			
		/*����ڴ��в�����ȱҳ������һ*/
		count++; 
		
		/*�ڴ����Ƿ���ڿ�λ�ÿ��Դ����ҳ��*/
		pos = findempty(mem, mnum); 
		
		/*���ڿ�λ�ã�ֱ�Ӵ�����ҳ�棬�����û�*/
		if (pos != -1){
			mem[pos] = req[i];
			time[pos] = i;
			a[pos][i] = req[i];
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
            /*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/

			continue;
		}

		/*�����ڿ�λ�ã�Ѱ��Ҫ�û���ҳ�棬lru*/
		pos = 0;
		for (j = 1; j < mnum; j++){
			if (time[j] < time[pos]){
				pos = j;
			}
		} 
		
		mem[pos] = req[i];
		time[pos] = i;
		a[pos][i] = req[i];
        if(i < rnum-1)	//��ֹ����Խ��
        {
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
			/*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/
        }
	} 
	
	for(j = 1; j < mnum; j++){
		a[j][0] = -1;
	}
	/*	a[1][0] = -1;
		a[2][0] = -1;	*/
	
	/*��ӡ�ڴ���ҳ��ı仯*/
	print(a, rnum, mnum);

	free(time);		//�ͷ��ڴ�ռ�
	free(mem);
	free(a);
	
	return count;	//����ȱҳ����
	
}

/*ʱ���㷨*/
int clo(int req[], int rnum, int mnum)
{
    int count;
    int i, j, p;
    int pos;
    int flag;
	
    /*�����ڴ�ռ�*/
    int *mem = (int *)malloc(sizeof(int) * mnum);
    setarray(mem, mnum, -1);
	
    /*state��¼�ڴ���ÿ��ҳ�����ʱ�ı��λ*/
    int *state = (int *)malloc(sizeof(int) * mnum);
    setarray(state, mnum, 0);
	
    /*a��¼�ڴ��д�ŵ�ҳ��*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1;i < mnum; i++)
        a[i] = a[0] + i * rnum;

    initarr(a, mnum, rnum);
	
    /*ȱҳ��ʼʱΪ0*/
    count = 0;
	flag = 0;
    for(i = 0; i < rnum; i++)
    {
        /*����ҳ�������Ƿ�����ڴ���*/
        pos = findexist(mem, mnum, req[i]);
		
        /*����ڴ��д���ҳ������*/
        if (pos != -1)
        {
		   state[pos] = 1;
		   for(j = 0; j < mnum; j++)
		   {
			  a[j][i+1] = a[j][i];
		   }	
			continue;
	    }
		else
		{ 
           /*����ڴ��в�����ȱҳ������һ*/
            count++;
           /*�ڴ����Ƿ���ڿ�λ�ÿ��Դ����ҳ��*/
           pos = findempty(mem, mnum);
		   
           /*���ڿ�λ�ã�ֱ�Ӵ�����ҳ�棬�����û�*/
           if (pos != -1)
           {
               mem[pos] = req[i];
               state[pos] = 1;
			   flag = (flag+1) % mnum;
			   a[pos][i] = req[i];
			   for(j = 0; j < mnum; j++)
			   {
				  a[j][i+1] = a[j][i];
			   }
			   continue;
	    
           }
		   else
		   {
          /*�����ڿ�λ�ã�Ѱ��Ҫ�û���ҳ��*/
               pos = 0;
	           while(1)
               {
	              if(state[flag] == 0)
	              {	
                     pos = flag;
		             break;
	              }
	              else
	              { 
	                 state[flag] = 0;
	              }
	             flag++;
	             flag = flag % mnum;
		       }
		         
			   mem[pos] = req[i];
               state[pos] = 1;
			   flag++;
	           flag = flag % mnum;
               a[pos][i] = req[i];
			   
			   if(i < rnum-1)	//��ֹ����Խ��
               {
			      for(j = 0; j < mnum; j++)
				  {
				    a[j][i+1] = a[j][i];
			      }
               }
			   
		    }
	    }
		
    }
	
	for(j = 1; j < mnum; j++)
	{
		a[j][0] = -1;
	}

	print(a, rnum, mnum);
  
    free(state);
    free(mem);
    free(a);
	
    return count;
}
int main()
{
    FILE *fp;
	FILE *fp1;
	FILE *fp2;
	
	srand(time(NULL));//�������� 
    int request[100];
	
	char input[100];
	int i,j,s=0;
	int M = 0;		//��¼�ļ���ҳ�����
    int n = 0;		//ҳ����
	int count;		//ȱҳ����
	float rate;		//ȱҳ��
	
	
	/*����100��1-10���������������д�뵽data.txt��*/
	fp = fopen("page.txt","w");
	
	/*����ļ�������*/
    if(fp == NULL)
        return -1;
	
	fp2 = fopen("B19030824���˰�.txt", "a+");
	
	for(i = 0; i < 100; i++) //����100��10���ڵ������ 
	{
		j = rand() % 10 ;
		fprintf(fp,"%d ", j);
		fprintf(fp2,"%d ", j);
	}
	fclose(fp);
	
	/*�ļ�ָ���ȡ�ļ�*/
    fp1 = fopen("page.txt","r");
	
	/*����ļ�������*/
    if(fp1 == NULL)
        return -1;
	
	/*��ȡ�ļ�����������*/
    while(fscanf(fp1,"%d",&request[M]) != EOF)
        M++;
	
	printf("\n");
	printf("================================================================================\n");
	printf("%d\n", M);
	for(i = 0; i < M; i++){
		printf("%d ", request[i]);
	}
	
	printf("\n");
	printf("================================================================================\n");
	
	printf("Please input the number of page frame:");
	scanf("%d", &n);
	printf("\n");
	printf("%d\n", n);
	
	printf("================================================================================\n");
	fprintf(fp2, "\n===================================================================================\n");
	
	fprintf(fp2, "The number of page is %d\n", M);
	
	fprintf(fp2, "The number of page frame is %d\n", n);
	
    count = fifo(request, M, n);
    printf("FIFO: %d \n", count);
	fprintf(fp2, "FIFO: %d \n", count);
	rate = (float)count/M;
	printf("the rate of missing pages is: %.2f\n", rate);
	fprintf(fp2, "the rate of missing pages is: %.2f\n", rate);
	printf("==================================================================================\n");
	
    count = lru(request, M, n);
    printf("LRU: %d \n", count);
	fprintf(fp2, "LRU: %d \n", count);
	rate = (float)count/M;
	printf("the rate of missing pages is: %.2f\n", rate);
	fprintf(fp2, "the rate of missing pages is: %.2f\n", rate);
	printf("==================================================================================\n");
	
    count = clo(request, M, n);
    printf("CLOCK: %d \n", count);
	fprintf(fp2, "CLOCK: %d \n", count);
	rate = (float)count/M;
	printf("the rate of missing pages is: %.2f\n", rate);
	fprintf(fp2, "the rate of missing pages is: %.2f\n", rate);
	printf("===================================================================================\n");
	fprintf(fp2, "===================================================================================\n");
	
			//�ر��ļ�ָ��
	fclose(fp1);
	fclose(fp2);
	return 0;
}
