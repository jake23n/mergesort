#include <iostream>
#include <cmath>
#include <random> 
#include <ctime>
#define max 1000
using namespace std;

void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << endl;
}

void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
}
void merge(int a[], int l, int m, int r)
{
    int pt1 = m - l + 1;
    int pt2 = r - m;

  
    int L[max], R[max];

    // gán dữ liệu vào mảng trái
    for (int i = 0; i < pt1; i++)
        L[i] = a[l + i];
    // gán dữ liệu vào mảng phải
    for (int j = 0; j < pt2; j++)
        R[j] = a[m + 1 + j];

  

    int i = 0, j = 0, k = l;

    //sắp xếp từ lớn đến bé
    while (i < pt1 && j < pt2)
    {
        if (L[i] >= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    // gán các giá trị còn lại 
    // cái nào lên trước cũng được không quan trọng
    while (i < pt1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < pt2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {

        int m = (ceil((double)r + l) / 2); // l + (r - l) / 2;

        // chia mảng trái
        mergeSort(a, l, m);
        // chia mảng phải
        mergeSort(a, m + 1, r);
        // sắp xếp
        merge(a, l, m, r);
    }
}
 void songaunhien(int a[], int n)
    {
     // random trong khoảng đoạn
        random_device rd;
        mt19937 rng(rd());


        uniform_int_distribution<int> uni(1, 10);
        for (int i = 0; i < n; i++)
        {
            a[i] = uni(rng);
        }
  }
int main()
{
    int a[max]; int n; cin >> n;
 
    songaunhien(a, n);
    xuatmang(a, n);

    mergeSort(a, 0, n - 1);

    cout << "\nmang moi\n";
    xuatmang(a, n);
    return 0;
}