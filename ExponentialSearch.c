#include <stdio.h>
// #include <unistd.h>

int binary_search(int arr[], int start, int end, int value)
{
  printf("f=%d b=%d\n", start, end);
    int front=start, back=end;
    int mid = (front + back) / 2;

    printf("loop2 start , mid=%d\n", mid);
    
    while (arr[mid] != value)
    {
        printf("%d %d\n", front, back);
        //sleep(1);
        if (front == back)
          return (arr[back] == value) ? back : -1;

        if (arr[mid] < value)
        {
            front = mid;
            mid = (front+back) / 2;
        }
        else
        {
            back = mid;
            mid = (front+back) / 2;
        }
    }

    return mid;
}

int exponential_search(int arr[], int size, int value)
{
    int xpt = 1, cnt = 0, index, start, end;

    if (arr[0] == value) return 0;
    else if (arr[size-1] < value) return -1;
    
    printf("loop start\n");

    while (arr[(xpt<<cnt)] < value)
    {
        printf("xpt cal %d -> %d\n", cnt, xpt<<cnt);
        start = xpt<<(cnt-1);
        end = xpt<<cnt;
        cnt++;
        if ((xpt<<cnt) >= size)
        {
            printf("deducted\n");
            //cnt-=1;
            break;
        }
        //sleep(1);
    }

    printf("goto binsearch\n");
    
    index = binary_search(arr, (xpt<<(cnt-1)), ((xpt<<cnt)>=size)?(size-1):(xpt<<cnt), value);

    return index;
}

int main(void)
{
    int N, value, index;

    // get the number of values
    scanf("%d", &N);
    int nums[N];

    // get the sorted values
    for (int i=0; i<N; i++)
        scanf("%d ", &nums[i]);

    // get a value to search
    scanf("%d", &value);
    
    printf("input end\n");
    
    // find the value to find by Exponential Search
    index = exponential_search(nums, N, value);
    
    printf("search end\n");

    // Show the position of the value
    if (index != -1)
    {
        printf("\nFound value: Index [%d]\n", index);
        for (int i=0; i<N; i++)
            printf(" %c%d%c ", (i==index)?'<':' ', nums[i], (i==index)?'>':' ');
        printf("\n");
    }
    else
        printf("Cannot search value <%d> \n", value);

    return 0;
}