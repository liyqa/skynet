#ifndef _UNISTD_H_
#define _UNISTD_H_

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>
#include <pthread.h>

#define random   rand
#define srandom  srand
#define snprintf _snprintf

#define SHUT_RD   SD_RECEIVE
#define SHUT_WR   SD_SEND
#define SHUT_RDWR SD_BOTH

typedef int ssize_t;

//typedef long pid_t;
pid_t getpid();
int kill(pid_t pid, int exit_code);

// defined in WinSock2.h
__declspec(dllimport) int __stdcall gethostname(char *buffer, int len);
void usleep(size_t us);
void sleep(size_t ms);

#if _MSC_VER < 1900
typedef struct timespec {
	int tv_sec;
	int tv_nsec;
} timespec;
#endif

enum { CLOCK_THREAD_CPUTIME_ID, CLOCK_REALTIME, CLOCK_MONOTONIC };
int clock_gettime(int what, struct timespec *ti);
struct tm* localtime_r(const time_t* timep, struct tm* result);
int gettimeofday(struct timeval* tv, struct timezone* tz);

enum { LOCK_EX, LOCK_NB };
int flock(int fd, int flag);

struct sigaction {
	void (*sa_handler)(int);
	int sa_flags;
	int sa_mask;
};
enum { SIGPIPE, SIGHUP, SA_RESTART };
void sigfillset(int *flag);
void sigemptyset(int* flag);
int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact);

int pipe(int fd[2]);
int daemon(int a, int b);

char *strsep(char **stringp, const char *delim);

int write(int fd, const void *ptr, size_t sz);
int read(int fd, void *buffer, size_t sz);
int close(int fd);

#endif
