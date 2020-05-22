#include <windows.h>
#include <iostream>
#include "lab3.h"

using namespace std;

#define THREAD_COUNT 12
#define SEMAPHORE_COUNT 3

DWORD ThreadID;
HANDLE hThread[THREAD_COUNT];
HANDLE hSemaphore[SEMAPHORE_COUNT];
HANDLE hMutex;

DWORD WINAPI thread_a(LPVOID);
DWORD WINAPI thread_b(LPVOID);
DWORD WINAPI thread_c(LPVOID);
DWORD WINAPI thread_d(LPVOID);
DWORD WINAPI thread_e(LPVOID);
DWORD WINAPI thread_f(LPVOID);
DWORD WINAPI thread_g(LPVOID);
DWORD WINAPI thread_h(LPVOID);
DWORD WINAPI thread_i(LPVOID);
DWORD WINAPI thread_k(LPVOID);
DWORD WINAPI thread_m(LPVOID);
DWORD WINAPI thread_n(LPVOID);
//ihgfe סולאפמנû
DWORD WINAPI thread_i_sem(LPVOID);
DWORD WINAPI thread_h_sem(LPVOID);
DWORD WINAPI thread_g_sem(LPVOID);
DWORD WINAPI thread_f_sem(LPVOID);
DWORD WINAPI thread_e_sem(LPVOID);

DWORD WINAPI thread_a(LPVOID lpParam)
{
	// step 1 
	// start B
	hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
	if (hThread[1] == NULL) {
		return GetLastError();
	}

	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "a" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	// wait B
	WaitForSingleObject(hThread[1], INFINITE);
	// close B
	CloseHandle(hThread[1]);

	// step 2 

	// start B
	hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
	if (hThread[1] == NULL) {
		return GetLastError();
	}


	// start C
	hThread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
	if (hThread[2] == NULL) {
		return GetLastError();
	}

	// start D
	hThread[3] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
	if (hThread[3] == NULL) {
		return GetLastError();
	}

	// start E
	hThread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
	if (hThread[4] == NULL) {
		return GetLastError();
	}

	// wait B
	WaitForSingleObject(hThread[1], INFINITE);
	// wait C
	WaitForSingleObject(hThread[2], INFINITE);
	// wait D
	WaitForSingleObject(hThread[3], INFINITE);
	// wait E
	WaitForSingleObject(hThread[4], INFINITE);

	// close B
	CloseHandle(hThread[1]);
	// close C
	CloseHandle(hThread[2]);
	// close D
	CloseHandle(hThread[3]);
	// close E
	CloseHandle(hThread[4]);

	// step 3 

	// start I
	hThread[5] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
	if (hThread[5] == NULL) {
		return GetLastError();
	}

	// start H
	hThread[6] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
	if (hThread[6] == NULL) {
		return GetLastError();
	}

	// start G
	hThread[7] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
	if (hThread[7] == NULL) {
		return GetLastError();
	}

	// start F
	hThread[8] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
	if (hThread[8] == NULL) {
		return GetLastError();
	}

	// start E
	hThread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
	if (hThread[4] == NULL) {
		return GetLastError();
	}

	// wait I
	WaitForSingleObject(hThread[5], INFINITE);
	// wait H
	WaitForSingleObject(hThread[6], INFINITE);
	// wait G
	WaitForSingleObject(hThread[7], INFINITE);
	// wait F
	WaitForSingleObject(hThread[8], INFINITE);
	// wait E
	WaitForSingleObject(hThread[4], INFINITE);

	// close G
	CloseHandle(hThread[5]);
	// close E
	CloseHandle(hThread[6]);
	// close D
	CloseHandle(hThread[7]);
	// close C
	CloseHandle(hThread[8]);
	// close F
	CloseHandle(hThread[4]);

	// step 4 

	// start I sem
	hThread[5] = CreateThread(NULL, 0, thread_i_sem, NULL, 0, &ThreadID);
	if (hThread[5] == NULL) {
		return GetLastError();
	}

	// start H sem
	hThread[6] = CreateThread(NULL, 0, thread_h_sem, NULL, 0, &ThreadID);
	if (hThread[9] == NULL) {
		return GetLastError();
	}

	// start G sem
	hThread[7] = CreateThread(NULL, 0, thread_g_sem, NULL, 0, &ThreadID);
	if (hThread[10] == NULL) {
		return GetLastError();
	}

	//start F sem
	hThread[8] = CreateThread(NULL, 0, thread_f_sem, NULL, 0, &ThreadID);
	if (hThread[10] == NULL) {
		return GetLastError();
	}

	//start E sem
	hThread[4] = CreateThread(NULL, 0, thread_e_sem NULL, 0, &ThreadID);
	if (hThread[10] == NULL) {
		return GetLastError();
	}

	// wait I sem
	WaitForSingleObject(hThread[5], INFINITE);
	// wait H sem
	WaitForSingleObject(hThread[6], INFINITE);
	// wait G sem
	WaitForSingleObject(hThread[7], INFINITE);
	// wait F sem
	WaitForSingleObject(hThread[8], INFINITE);
	//wait E sem
	WaitForSingleObject(hThread[4], INFINITE);


	// close I sem
	CloseHandle(hThread[5]);
	// close H sem
	CloseHandle(hThread[6]);
	// close G sem
	CloseHandle(hThread[7]);
	// close F sem
	CloseHandle(hThread[8]);
	// close E sem 
	CloseHandle(hThread[4]);

	// step 5 

	// start N 
	hThread[11] = CreateThread(NULL, 0, thread_n, NULL, 0, &ThreadID);
	if (hThread[11] == NULL) {
		return GetLastError();
	}

	// wait N 
	WaitForSingleObject(hThread[11], INFINITE);

	// close N
	CloseHandle(hThread[11]);

	return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "b" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "c" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "d" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "e" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "i" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}


DWORD WINAPI thread_h(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "h" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "f" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "k" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_m(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_n(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "n" << flush;
		computation();
		ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI thread_i_sem(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[0], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "i" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[1], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_h_sem(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[1], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "k" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[2], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_g_sem(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[2], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[3], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_f_sem(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[3], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[4], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_e_sem(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[4], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "m" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[5], 1, NULL);
	}

	return 0;
}

unsigned int lab3_thread_graph_id()
{
	return 2;
}

const char* lab3_unsynchronized_threads()
{
	return "ikm";
}

const char* lab3_sequential_threads()
{
	return "ihgfe";
}

int lab3_init()
{
	hMutex = CreateMutex(NULL, 0, NULL);
	if (hMutex == NULL) {
		cout << "CreateMutex error: " << GetLastError();
		return 1;
	}

	for (int i = 0; i < SEMAPHORE_COUNT; i++) {
		hSemaphore[i] = CreateSemaphore(NULL, i == 0 ? 1 : 0, 1, NULL);
		if (hSemaphore[i] == NULL) {
			cout << "CreateSemaphore error: " << GetLastError();
			return 1;
		}
	}

	// start A
	hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
	if (hThread[0] == NULL) {
		return GetLastError();
	}
	// wait A
	WaitForSingleObject(hThread[0], INFINITE);
	// close A
	CloseHandle(hThread[0]);

	CloseHandle(hMutex);

	for (int i = 0; i < SEMAPHORE_COUNT; i++) {
		CloseHandle(hSemaphore[i]);
	}

	return 0;
}
