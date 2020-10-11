//#include<stdio.h>
//#include<time.h>

//int main(void) {
//	clock_t before;
//	double result;
//	before = clock();
//
//	for (int i = 0; i < 100; i++) {
//		printf("%dn", i);
//	}
//
//	result = (double)(clock() - before) / CLOCKS_PER_SEC;
//
//	printf("\n걸린시간은 %5.6f 입니다.\n", duringtime);
//}
//




//#include<stdio.h>
//#include<windows.h>
//int main(void) {
//	__int64 Frequency;
//	__int64 BeginTime;
//	__int64 Endtime;
//	
//	QueryPerformanceFrequency((LARGE_INTEGER *)&Frequency);
//	QueryPerformanceCounter((LARGE_INTEGER *)&BeginTime);
//
//
//	for (int i = 0; i < 1; i++) {
//		printf("%dn", i);
//	}
//
//	QueryPerformanceCounter((LARGE_INTEGER *)&Endtime);
//
//	__int64 elapsed = Endtime - BeginTime;
//
//	double duringtime = (double)elapsed / (double)Frequency;
//	printf("\n걸린시간은 %5.6f 입니다.\n", duringtime);
//}

#include<stdio.h>
#include<windows.h>
#include<time.h>
__int64 Frequency;
__int64 BeginTime;
__int64 Endtime;
void setTimer() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&Frequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&BeginTime);
}

void printTimer() {
	QueryPerformanceCounter((LARGE_INTEGER*)&Endtime);
	__int64 elapsed = Endtime - BeginTime;
	double duringtime = (double)elapsed / (double)Frequency;
	printf("\n걸린시간은 %5.6f 입니다.\n", duringtime);
}


clock_t before;
double result;
void setClock() {
	before = clock();
}

void printClock() {
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("\n걸린시간은 %5.6f 입니다.\n", result);
}