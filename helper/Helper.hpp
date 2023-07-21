#include <functional>

void GenerateData(int a[], int n, int dataType);
void InputArrayFromTxtFile(int *&a, int &n, const char *filename);
void PrintArray(int a[], int n);
void PrintResult(const char *outPara, int runningTime, int countCompare);
int MeasureRunningTime(std::function<void(int *, int)> algoFunc, int a[], int size);

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}