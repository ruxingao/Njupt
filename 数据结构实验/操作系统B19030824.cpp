#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>



/*给数组赋值*/ 
void setarray(int arr[], int num, int val) 
{  
	int i;
	
	for (i = 0; i < num; i++)   
		arr[i] = val; 
}

/*声明一个二维数组用来存储内存中页面变化情况*/
void initarr(int **arr, int rnum, int cnum)
{
    int r, c;
    for(r = 0; r < rnum; r++)
    {
        for(c = 0; c < cnum; c++)
            arr[r][c] = -1;
    }
}

/*查找内存 mem 中是否存在页面 page*/ 
int findexist(int mem[], int mnum, int page) 
{  
	int i;
	
	for (i = 0; i < mnum; i++){
		if (mem[i] == page)
			return i;  
	}
	
	return -1; 
}

/*查找内存 mem 中是否存空的位置*/ 
int findempty(int mem[], int mnum) 
{  
	int i; 
	
	for (i = 0; i < mnum; i++){   
		if (mem[i] == -1)
			return i;  
	} 
	
	return -1; 
} 

/*打印内存中页面的变化*/
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

/*先进先出页面置换算法*/ 
int fifo(int req[], int rnum, int mnum) 
{  
	int count;  
	int i, j;  
	int pos;     

	
	/*
	分配内存空间
	实验中常用的mnum=3
	初始化为-1
	*/
	/*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int ) * mnum);
    setarray(mem, mnum, -1);
	
    /*time记录内存中每个页面进入的时间*/
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, rnum);
	
    /*a记录内存中存放的页面*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1; i < mnum; i++)
        a[i] = a[0] + i * rnum;
    initarr(a, mnum, rnum);

	/*缺页次数初始时为 0*/  
	count = 0; 
 
	for (i = 0; i < rnum; i++){   
	
		/*发现页面请求是否存在内存中*/   
		pos = findexist(mem, mnum, req[i]); 
	
		/*如果内存中存在页面请求*/   
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
		
		/*如果内存中不存在缺页次数加一*/   
		count++; 
		
		/*内存中是否存在空位置可以存放新页面*/   
		pos = findempty(mem, mnum); 
		
		/*存在空位置，直接存入新页面，不做置换*/   
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
	
		/*不存在空位置，寻找要置换的页面，fifo*/
		pos = 0;
		
		for (j = 1; j < mnum; j++){
			if (time[j] < time[pos]){
				pos = j;
				}
		}
		
		mem[pos] = req[i];
		time[pos] = i;
		a[pos][i] = req[i];
        if(i < rnum-1)	//防止数组越界
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
	
	/*打印内存中页面的变化*/
	print(a, rnum, mnum);

	free(time);		//释放内存空间
	free(mem);
	free(a);
	
	return count;	//返回缺页次数
	
}

/*最近最久未使用页面置换算法*/
int lru(int req[], int rnum, int mnum){
	
	int count;
	int i, j;
	int pos;
	
	/*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int ) * mnum);
    setarray(mem, mnum, -1);
	
    /*time记录内存中每个页面进入的时间*/
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, rnum);
	
    /*a记录内存中存放的页面*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1; i < mnum; i++)
        a[i] = a[0] + i * rnum;
	
    initarr(a, mnum, rnum);
	
    /*缺页率初始时为 0*/
	count = 0; 
	
	for (i = 0; i < rnum; i++){
		
		/*发现页面请求是否存在内存中*/
		pos = findexist(mem, mnum, req[i]); 
		
		/*如果内存中存在页面请求，此处与 fifo 有些许区别*/
		if (pos != -1){
			time[pos] = i;	//此处 lru 记录的是最后一次的访问时间，而 fifo 中记录的是最 先进入的时间
			for(j = 0; j < mnum; j++){
				a[j][i+1] = a[j][i];
			}
			/*	a[0][i+1] = a[0][i];
				a[1][i+1] = a[1][i];
				a[2][i+1] = a[2][i];	*/

			continue;
		}
			
		/*如果内存中不存在缺页次数加一*/
		count++; 
		
		/*内存中是否存在空位置可以存放新页面*/
		pos = findempty(mem, mnum); 
		
		/*存在空位置，直接存入新页面，不做置换*/
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

		/*不存在空位置，寻找要置换的页面，lru*/
		pos = 0;
		for (j = 1; j < mnum; j++){
			if (time[j] < time[pos]){
				pos = j;
			}
		} 
		
		mem[pos] = req[i];
		time[pos] = i;
		a[pos][i] = req[i];
        if(i < rnum-1)	//防止数组越界
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
	
	/*打印内存中页面的变化*/
	print(a, rnum, mnum);

	free(time);		//释放内存空间
	free(mem);
	free(a);
	
	return count;	//返回缺页次数
	
}

/*时钟算法*/
int clo(int req[], int rnum, int mnum)
{
    int count;
    int i, j, p;
    int pos;
    int flag;
	
    /*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int) * mnum);
    setarray(mem, mnum, -1);
	
    /*state记录内存中每个页面进入时的标记位*/
    int *state = (int *)malloc(sizeof(int) * mnum);
    setarray(state, mnum, 0);
	
    /*a记录内存中存放的页面*/
    int **a;
    a = (int **)malloc(sizeof(int *) * mnum);
    a[0] = (int *)malloc(sizeof(int) * rnum * mnum);
    for(i = 1;i < mnum; i++)
        a[i] = a[0] + i * rnum;

    initarr(a, mnum, rnum);
	
    /*缺页初始时为0*/
    count = 0;
	flag = 0;
    for(i = 0; i < rnum; i++)
    {
        /*发现页面请求是否存在内存中*/
        pos = findexist(mem, mnum, req[i]);
		
        /*如果内存中存在页面请求*/
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
           /*如果内存中不存在缺页次数加一*/
            count++;
           /*内存中是否存在空位置可以存放新页面*/
           pos = findempty(mem, mnum);
		   
           /*存在空位置，直接存入新页面，不做置换*/
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
          /*不存在空位置，寻找要置换的页面*/
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
			   
			   if(i < rnum-1)	//防止数组越界
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
	
	srand(time(NULL));//先种种子 
    int request[100];
	
	char input[100];
	int i,j,s=0;
	int M = 0;		//记录文件中页表个数
    int n = 0;		//页框数
	int count;		//缺页个数
	float rate;		//缺页率
	
	
	/*生成100个1-10的随机数，并将其写入到data.txt中*/
	fp = fopen("page.txt","w");
	
	/*如果文件不存在*/
    if(fp == NULL)
        return -1;
	
	fp2 = fopen("B19030824茹兴奥.txt", "a+");
	
	for(i = 0; i < 100; i++) //产生100个10以内的随机数 
	{
		j = rand() % 10 ;
		fprintf(fp,"%d ", j);
		fprintf(fp2,"%d ", j);
	}
	fclose(fp);
	
	/*文件指针读取文件*/
    fp1 = fopen("page.txt","r");
	
	/*如果文件不存在*/
    if(fp1 == NULL)
        return -1;
	
	/*读取文件中请求序列*/
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
	
			//关闭文件指针
	fclose(fp1);
	fclose(fp2);
	return 0;
}
