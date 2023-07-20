void GenerateData(int a[], int n, int dataType);
void InputArrayFromTxtFile(int a[], int n, char* filename);
void PrintArray(int a[], int n);

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}