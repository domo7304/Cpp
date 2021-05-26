//#include <ctime> 
//#include <iostream> 
//
//int main() {
//	struct tm *curr_tm;
//	time_t curr_time = time(NULL);
//	curr_tm = localtime(&curr_time);
//
//	int curr_day = curr_tm->tm_mday;
//	int curr_hour = curr_tm->tm_hour;
//	int curr_minute = curr_tm->tm_min;
//	int curr_second = curr_tm->tm_sec;
//
//	printf("< %d %d:%d:%d > \n",
//		curr_day, curr_hour, curr_minute, curr_second);
//}