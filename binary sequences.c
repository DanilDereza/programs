#include <stdio.h>

long long int count = 0;

void Sort(int *a, int begin, int end){

    if (begin == end)
        return;

    int i = begin;
    int mid = (end + begin) / 2;
    int j = mid + 1;
    int k = begin;
    Sort(a, begin, mid);
    Sort(a, mid + 1, end);
    int d[end - begin + 1];
    for (int index = begin; index <= end; ++index)
    {
        if (k <= mid && (j > end || a[k] <= a[j]))
        {
            d[index - begin] = a[k];
            ++k;
        }
        else
        {
            d[index - begin] = a[j];
            ++j;
            count += mid + 1ll - k;
        }
    }

    for (int index = begin; index <= end; ++index)
    {
        a[index] = d[index - begin];
    }


}


int main()
{
    FILE *input = fopen("input.txt","r");
    int N;
    fscanf(input, "%d", &N);
    int a[N];
    for(int i = 0; i < N; ++i){
        fscanf(input, "%d", &a[i]);
    }
    fclose(input);
    FILE *output = fopen("output.txt", "w");
    Sort(a, 0, N-1);
    fprintf(output, "%d", count);
    fclose(output);
    return 0;
}
