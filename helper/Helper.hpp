#include <functional>

typedef uint64_t ull;

void GenerateData(int *&a, int n, int dataType);
void InputArrayFromTxtFile(int *&a, int &n, const char *fileName);
void WriteArrayToTxtFile(int *a, int n, const char *fileName);
void PrintArray(int a[], int n);
void PrintResult(const char *outPara, int runningTime, ull countCompare);
int MeasureRunningTime(std::function<void(int *, int)> algoFunc, int a[], int size);
void PrintOrderName(int orderIdx);

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}