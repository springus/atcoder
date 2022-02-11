include <bits/stdc++.h>
using namespace std;
// Time
#include <sys/time.h>
ll getTime() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  ll result =  tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
  return result;
}
ll start_time, time_limit = 1900;
void setTime(){ start_time = getTime();}
ll nowTime(){ return getTime() - start_time;}
bool ended;
bool timeup(){ return ended = (nowTime() > time_limit);}
//
int main(){
  return 0;
}
