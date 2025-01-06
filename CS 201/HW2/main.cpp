#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;

int linearSearch(int arr[],const int size,const int key);
int binarySearch(int arr[],const int size,const int key);
int linearSearchRec(int arr[],const int size,const int key,int recNum);
int randomSearch(int arr[],const int size,const int key);
int jumpSearch(int arr[],const int size,const int key);
void test(int arr[],const int size,const int value);

int main()
{
    srand(time(0));

    int size1=10,size2=30,size3=60,size4=100,size5=300,size6=600,size7=1000,size8=3000,size9=6000, size10=10000, size11=30000;

    int arr1[size1];

    for(int i=0;i<size1;i++)
    {
        int randomNumber=rand()%(size1*10)+1;
        arr1[i]=randomNumber;
    }

    for (int i = 0; i < size1 - 1; i++)
    {
        for (int j = 0; j < size1 - i - 1; j++)
            {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr1,size1,arr1[size1/5]);
    cout<<"Scenerio 2:"<<endl;
    test(arr1,size1,arr1[size1/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr1,size1,arr1[size1-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr1,size1,size1*10+1);
    cout<<endl;

    int arr2[size2];

    for(int i=0;i<size2;i++)
    {
        int randomNumber=rand()%(size2*10)+1;
        arr2[i]=randomNumber;
    }

    for (int i = 0; i < size2 - 1; i++)
    {
        for (int j = 0; j < size2 - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr2,size2,arr2[size2/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr2,size2,arr2[size2/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr2,size2,arr2[size2-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr2,size2,size2*10+1);
    cout<<endl;

    int arr3[size3];
    for(int i=0;i<size3;i++)
    {
        int randomNumber=rand()%(size3*10)+1;
        arr3[i]=randomNumber;
    }
    for (int i = 0; i < size3 - 1; i++)
    {
        for (int j = 0; j < size3 - i - 1; j++)
        {
            if (arr3[j] > arr3[j + 1])
            {
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr3,size3,arr3[size3/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr3,size3,arr3[size3/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr3,size3,arr3[size3-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr3,size3,size3*10+1);
    cout<<endl;

    int arr4[size4];
    for(int i=0;i<size4;i++)
    {
        int randomNumber=rand()%(size4*10)+1;
        arr4[i]=randomNumber;
    }
    for (int i = 0; i < size4 - 1; i++)
    {
        for (int j = 0; j < size4 - i - 1; j++)
        {
            if (arr4[j] > arr4[j + 1])
            {
                int temp = arr4[j];
                arr4[j] = arr4[j + 1];
                arr4[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr4,size4,arr4[size4/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr4,size4,arr4[size4/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr4,size4,arr4[size4-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr4,size4,size4*10+1);
    cout<<endl;

    int arr5[size5];
    for(int i=0;i<size5;i++)
    {
        int randomNumber=rand()%(size5*10)+1;
        arr5[i]=randomNumber;
    }
    for (int i = 0; i < size5 - 1; i++)
    {
        for (int j = 0; j < size5 - i - 1; j++)
        {
            if (arr5[j] > arr5[j + 1])
            {
                int temp = arr5[j];
                arr5[j] = arr5[j + 1];
                arr5[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr5,size5,arr5[size5/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr5,size5,arr5[size5/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr5,size5,arr5[size5-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr5,size5,size5*10+1);
    cout<<endl;

    int arr6[size6];
    for(int i=0;i<size6;i++)
    {
        int randomNumber=rand()%(size6*10)+1;
        arr6[i]=randomNumber;
    }
    for (int i = 0; i < size6 - 1; i++)
    {
        for (int j = 0; j < size6 - i - 1; j++)
        {
            if (arr6[j] > arr6[j + 1])
            {
                int temp = arr6[j];
                arr6[j] = arr6[j + 1];
                arr6[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr6,size6,arr6[size6/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr6,size6,arr6[size6/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr6,size6,arr6[size6-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr6,size6,size6*10+1);
    cout<<endl;

    int arr7[size7];
    for(int i=0;i<size7;i++)
    {
        int randomNumber=rand()%(size7*10)+1;
        arr7[i]=randomNumber;
    }
    for (int i = 0; i < size7 - 1; i++)
    {
        for (int j = 0; j < size7 - i - 1; j++)
        {
            if (arr7[j] > arr7[j + 1])
            {
                int temp = arr7[j];
                arr7[j] = arr7[j + 1];
                arr7[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr7,size7,arr7[size7/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr7,size7,arr7[size7/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr7,size7,arr7[size7-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr7,size7,size7*10+1);
    cout<<endl;

    int arr8[size8];
    for(int i=0;i<size8;i++)
    {
        int randomNumber=rand()%(size8*10)+1;
        arr8[i]=randomNumber;
    }
    for (int i = 0; i < size8 - 1; i++)
    {
        for (int j = 0; j < size8 - i - 1; j++)
        {
            if (arr8[j] > arr8[j + 1])
            {
                int temp = arr8[j];
                arr8[j] = arr8[j + 1];
                arr8[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr8,size8,arr8[size8/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr8,size8,arr8[size8/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr8,size8,arr8[size8-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr8,size8,size8*10+1);
    cout<<endl;

    int arr9[size9];
    for(int i=0;i<size9;i++)
    {
        int randomNumber=rand()%(size9*10)+1;
        arr9[i]=randomNumber;
    }
    for (int i = 0; i < size9 - 1; i++)
    {
        for (int j = 0; j < size9 - i - 1; j++)
        {
            if (arr9[j] > arr9[j + 1])
            {
                int temp = arr9[j];
                arr9[j] = arr9[j + 1];
                arr9[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr9,size9,arr9[size9/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr9,size9,arr9[size9/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr9,size9,arr9[size9-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr9,size9,size9*10+1);
    cout<<endl;

    int arr10[size10];
    for(int i=0;i<size10;i++)
    {
        int randomNumber=rand()%(size10*10)+1;
        arr10[i]=randomNumber;
    }
    for (int i = 0; i < size10 - 1; i++)
    {
        for (int j = 0; j < size10 - i - 1; j++)
        {
            if (arr10[j] > arr10[j + 1])
            {
                int temp = arr10[j];
                arr10[j] = arr10[j + 1];
                arr10[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr10,size10,arr10[size10/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr10,size10,arr10[size10/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr10,size10,arr10[size10-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr10,size10,size10*10+1);
    cout<<endl;

    int arr11[size11];
    for(int i=0;i<size11;i++)
    {
        int randomNumber=rand()%(size11*10)+1;
        arr11[i]=randomNumber;
    }
    for (int i = 0; i < size11 - 1; i++)
    {
        for (int j = 0; j < size11 - i - 1; j++)
        {
            if (arr11[j] > arr11[j + 1])
            {
                int temp = arr11[j];
                arr11[j] = arr11[j + 1];
                arr11[j + 1] = temp;
            }
        }
    }

    cout<<"Scenerio 1:"<<endl;
    test(arr11,size11,arr11[size11/6]);
    cout<<"Scenerio 2:"<<endl;
    test(arr11,size11,arr11[size11/2]);
    cout<<"Scenerio 3:"<<endl;
    test(arr11,size11,arr11[size11-3]);
    cout<<"Scenerio 4:"<<endl;
    test(arr11,size11,size11*10+1);

    return 0;

}
void test(int arr[],const int size,const int value)
{

    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    startTime = std::chrono::system_clock::now();
    for(int i=0;i<10000;i++)
    {
        linearSearch(arr,size,value);
    }
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Algorithm 1 took  " << elapsedTime.count()/10000<< " milliseconds for n= "<<size << endl;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    startTime = std::chrono::system_clock::now();
    for(int i=0;i<10000;i++)
    {
        linearSearchRec(arr,size,value,0);
    }
    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << "Algorithm 2 took " << elapsedTime.count()/10000 << " milliseconds for n= "<<size<< endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    startTime = std::chrono::system_clock::now();
        for(int i=0;i<10000;i++)
        {
            binarySearch(arr,size,value);
        }
    elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Algorithm 3 took " << elapsedTime.count()/10000 << " milliseconds for n= "<<size<< endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    startTime = std::chrono::system_clock::now();
        for(int i=0;i<10000;i++)
        {
            jumpSearch(arr,size,value);
        }
    elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Algorithm 4 took " << elapsedTime.count()/10000 << " milliseconds for n= "<<size<< endl;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    startTime = std::chrono::system_clock::now();
        for(int i=0;i<10000;i++)
        {
            randomSearch(arr,size,value);
        }
    elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Algorithm 5 took " << elapsedTime.count()/10000<< " milliseconds for n= "<<size<< endl;

}

int linearSearch(int arr[],const int size,const int key)
{

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;

}

int binarySearch(int arr[],const int size,const int key)
{
    int left=0;
    int right=size-1;
    int mid;

    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[mid]>key)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }

    return -1;

}

int linearSearchRec(int arr[],const int size,const int key,int recNum)
{

    if(arr[0]==key)
    {
        return recNum;
    }

    if(size==1)
    {
        return -1;
    }

    return linearSearchRec(arr+1,size-1,key,recNum+1);
}

int randomSearch(int arr[],const int size,const int key)
{
    srand(time(0));

    int newArr[size];
    int newSize=size;

    for(int i=0;i<size;i++)
    {
        newArr[i]=arr[i];
    }

    while(newSize!=1)
        {

        int randomIndex=rand()%size;

        if(newArr[randomIndex]==key)
        {
            return randomIndex;
        }
        if(newArr[newSize-1]==key)
        {
            return newSize-1;
        }

        swap(newArr[randomIndex],newArr[newSize-1]);
        newSize--;

        }
    return -1;

}

int jumpSearch(int arr[], const int size, const int key) {
    int first = 0;
    int m = sqrt(size);

    while (arr[min(m, size) - 1] < key) {
        first = m;
        m += sqrt(size);

        if (first >= size) {
            return -1;
        }
    }

    while (arr[first] < key) {
        first++;
        if (first >= min(m, size)) {
            return -1;
        }
    }

    if (arr[first] == key) {
        return first;
    }

    return -1;

}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
