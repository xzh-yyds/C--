void qsort(int a[],int start,int end)    //start和end都是指下标
{
    int i,j,temp,x;
    i=start;
    j=end;
    x=a[start];    //选取基准值
    while(i<j)
    {
        while(i<j && x<a[j])    //从右向左搜索小于基准值的数,让j等于它的下标
            j--;
        while(i<j && x>a[i])    //从左向右搜索大于基准值的数,让i等于它的下标
            i++;
        if(i<j)    //在满足i<j的条件下，交换a[i]和a[j]的值 
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=x;   //跳出循环之后，把基准值和a[i]调换 
    x=a[i];
    a[i]=temp;
    if(start<j)    //递归 
        qsort(a,start,j-1);
	if(i<end)
        qsort(a,j+1,end);
}

int main(){
    int arr[10];
    int j = 1;
    for(int i = 0; i < 10; i++){
        arr[i] = 5*i-i*j+1;
        j++;
    }
    qsort(arr, 0, 9);
}