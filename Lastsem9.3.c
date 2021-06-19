#include<stdio.h>
typedef struct timestamp
{
    int dd;
    int mm;
    int yyyy;
    int hr;
    int min;
    int sec;
}ts;

void Sort_Tokens(ts arr[], int n){
    printf("%d\n", n);
    //year
    for(int i=0; i<n; i++){
        for (int j = i+1 ; j < n; j++)
        {
            if(arr[i].yyyy > arr[j].yyyy){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if((arr[i].yyyy==arr[j].yyyy)&&(arr[i].mm > arr[j].mm)){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if((arr[i].yyyy==arr[j].yyyy)&&(arr[i].mm == arr[j].mm)&&(arr[i].dd > arr[j].dd)){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if((arr[i].yyyy==arr[j].yyyy)&&(arr[i].mm == arr[j].mm)&&(arr[i].dd == arr[j].dd)&&(arr[i].hr > arr[j].hr)){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if((arr[i].yyyy==arr[j].yyyy)&&(arr[i].mm == arr[j].mm)&&(arr[i].dd == arr[j].dd)&&(arr[i].hr == arr[j].hr)&&(arr[i].min > arr[j].min)){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            if((arr[i].yyyy==arr[j].yyyy)&&(arr[i].mm == arr[j].mm)&&(arr[i].dd == arr[j].dd)&&(arr[i].hr == arr[j].hr)&&(arr[i].min == arr[j].min)&&(arr[i].sec > arr[j].sec)){
                ts temp;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }       
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d %d %d %d\n", (arr+i)->dd,(arr+i)->mm,(arr+i)->yyyy,(arr+i)->hr,(arr+i)->min,(arr+i)->sec);
    }
    
}

int main(){
    int n;
    scanf("%d", &n);
    ts arr[n];
    for(int i=0; i<n; i++){
        scanf("%d %d %d %d %d %d", &(arr[i].dd),&(arr[i].mm),&(arr[i].yyyy),&(arr[i].hr),&(arr[i].min),&(arr[i].sec));
    }
    Sort_Tokens(arr, n);
    return 0;
}