int z[4];
void outputArray(int m[],int length)
{
    int i;
    i=0;
    while(i<length)
    {
        output(m[i]);
        i = i+1;
        // output(i);
    }
}
void inputArray(int length)
{
    int i;
    i=0;
    while(i<length)
    {
        z[i] = input();
        i=i+1;
    }
    outputArray(z,length);
}

int main(void)
{
    inputArray(4);
}