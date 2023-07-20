void GenerateData(int a[], int n, int dataType);
void PrintArray(int arr[], int n);

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}