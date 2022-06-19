#include <stdio.h>
//#include <unistd.h>

int binary_search(int arr[], int start, int end, int value)
{
    int front=start, back=end;
    int mid = (front + back) / 2;
    
    while (arr[mid] != value)
    {
        if (front == back)
          return (arr[back] == value) ? back : -1;

        if (arr[mid] < value)
            front = mid+1;
        else
            back = mid-1;
        mid = (front+back) / 2;
    }

    return mid;
}

int exponential_search(int arr[], int size, int value)
{
    int xpt = 1, cnt = 0, index, start, end;

    if (arr[0] == value) return 0;
    else if (arr[size-1] < value) return -1;

    while (arr[(xpt<<cnt)] < value)
    {   
        cnt++;
        if ((xpt<<cnt) >= size)
            break;
    }
  
    start = ((xpt<<(cnt-1)) < 0) ? 0 : xpt<<(cnt-1);
    end = ((xpt<<cnt) >= size) ? size : xpt<<cnt;
    
    index = binary_search(arr, start, end, value);

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
    
    // find the value to find by Exponential Search
    index = exponential_search(nums, N, value);

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
