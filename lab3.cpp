#include <windows.h>
#include <iostream>
#include "lab3.h"

using namespace std;

#define THREAD_COUNT 12
#define SEMAPHORE_COUNT 5

DWORD ThreadID;
HANDLE hThread[THREAD_COUNT];
HANDLE hSemaphore[SEMAPHORE_COUNT];
HANDLE hInterval;
HANDLE hContinue;
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

	WaitForSingleObject(hInterval, INFINITE); // Thread_b

	// step 2 

	ReleaseSemaphore(hContinue, 1, NULL); // Thread_b

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
	WaitForSingleObject(hInterval, INFINITE); // Thread_e


	// step 3 

	ReleaseSemaphore(hContinue, 1, NULL); // Thread_e

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

	// wait H
	WaitForSingleObject(hThread[6], INFINITE);
	// wait G
	WaitForSingleObject(hThread[7], INFINITE);
	// wait F
	WaitForSingleObject(hThread[8], INFINITE);
	// wait E
	WaitForSingleObject(hThread[4], INFINITE);
	// wait I
	WaitForSingleObject(hInterval, INFINITE); // Thread_i

	// step 4 

	ReleaseSemaphore(hContinue, 1, NULL); // Thread_i

	// start K 
	hThread[9] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
	if (hThread[9] == NULL) {
		return GetLastError();
	}

	// start M 
	hThread[10] = CreateThread(NULL, 0, thread_m, NULL, 0, &ThreadID);
	if (hThread[10] == NULL) {
		return GetLastError();
	}

	// wait I 
	WaitForSingleObject(hThread[5], INFINITE);
	// wait K 
	WaitForSingleObject(hThread[9], INFINITE);
	// wait M 
	WaitForSingleObject(hThread[10], INFINITE);


	// step 5 

	// start N 
	hThread[11] = CreateThread(NULL, 0, thread_n, NULL, 0, &ThreadID);
	if (hThread[11] == NULL) {
		return GetLastError();
	}

	// wait N 
	WaitForSingleObject(hThread[11], INFINITE);

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

	ReleaseSemaphore(hInterval, 1, NULL);
	WaitForSingleObject(hContinue, INFINITE);

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

	ReleaseSemaphore(hInterval, 1, NULL);
	//
	WaitForSingleObject(hContinue, INFINITE);

	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[4], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "e" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[0], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{

	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[0], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "i" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[1], 1, NULL);
	}

	ReleaseSemaphore(hInterval, 1, NULL);
	//
	WaitForSingleObject(hContinue, INFINITE);

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
		WaitForSingleObject(hSemaphore[1], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "h" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[2], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[2], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "g" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[3], 1, NULL);
	}

	return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
	for (int i = 0; i < 3; i++) {
		WaitForSingleObject(hSemaphore[3], INFINITE);
		WaitForSingleObject(hMutex, INFINITE);
		cout << "f" << flush;
		computation();
		ReleaseMutex(hMutex);
		ReleaseSemaphore(hSemaphore[4], 1, NULL);
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

	hInterval = CreateSemaphore(NULL, 0, 2, NULL);
	hContinue = CreateSemaphore(NULL, 0, 2, NULL);



	// start A
	hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
	if (hThread[0] == NULL) {
		return GetLastError();
	}
	// wait A
	WaitForSingleObject(hThread[0], INFINITE);

	CloseHandle ( hMutex );
	//
	CloseHandle( hInterval );
	//
	CloseHandle ( hContinue );
	for (int i = 0; i < SEMAPHORE_COUNT; i++) {
		CloseHandle(hSemaphore[i]);
	}



	return 0;
}
