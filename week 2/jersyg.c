#include<stdio.h>

void main()
{
    int p;
    scanf("%d",&p);
    int n=p-1;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans=-1;
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] ==7) {
            ans= mid;
            break; // Found the target
        } else if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (arr[left] <= 7 && 7 < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (arr[mid] < 7 && 7 <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    printf("%d",ans); // Target not found
}


