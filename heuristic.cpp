#include <sys/time.h>
long long getTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  long long result =  tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
  return result;
}
long long start_time, time_limit = 1900;
void setTime(){ start_time = getTime();}
long long nowTime(){ return getTime() - start_time;}
bool ended;
bool timeup(){ return ended = (nowTime() > time_limit);}
