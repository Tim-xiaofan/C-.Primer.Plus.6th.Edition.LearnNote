/** 20210221 21:28, zyj, GuangDong*/
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdarg>
#include <sys/time.h>
#define DEBUG 0   
#define ERROR 1

#ifdef DEBUG
#define EVENT_LOG(info, args...) event_log(__FILE__, __LINE__, (info), ##args)
#else
#define EVENT_LOG(info, args...) 0
#endif

#ifdef ERROR
#define ERROR_LOG(info, args...) error_log(__FILE__, __LINE__, (info), ##args)
#else
#define ERROR_LOG(info, args...) 0
#endif

/**
  This function logs events.
  @param module_name      the name of the file.
  @param line             the line number in the file.
  @param log_info         the info that is printed with the modulename.
  @param anyno            optional pointer to unsigned int, which is printed along with log_info.
  The conversion specification must be contained in log_info.
 */

void event_log(const char *module_name,  int line, const char *log_info, ...)
{
	struct timeval tv;
	struct tm *the_time;
	va_list va;
	
	va_start(va, log_info);

	gettimeofday(&tv, (struct timezone *) NULL);
	the_time = localtime((time_t *) & (tv.tv_sec));
	/** [22:57:57.844] [*.cpp:1507]*/
	fprintf(stdout, "[%02d:%02d:%02d.%03d] [%s:%d] ",
				the_time->tm_hour, the_time->tm_min, the_time->tm_sec, (int) (tv.tv_usec / 1000), 
				module_name, line);
	vfprintf(stdout, log_info, va);
	va_end(va);
	return;
}

void error_log(const char *module_name,  int line, const char *log_info, ...)
{
	struct timeval tv;
	struct tm *the_time;
	va_list va;
	
	va_start(va, log_info);

	gettimeofday(&tv, (struct timezone *) NULL);
	the_time = localtime((time_t *) & (tv.tv_sec));
	/** [22:57:57.844] [*.cpp:1507]*/
	fprintf(stderr, "[%02d:%02d:%02d.%03d] [%s:%d] ",
				the_time->tm_hour, the_time->tm_min, the_time->tm_sec, (int) (tv.tv_usec / 1000), 
				module_name, line);
	vfprintf(stderr, log_info, va);
	va_end(va);
	return;
}
