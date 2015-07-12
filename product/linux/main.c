#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include "ctype.h"
#include "gagent.h"
#include "lib.h"
#include "wifi.h"
#include "mqttxpg.h"

#include <stdio.h>        //printf()
#include <unistd.h>        //pause()
#include <signal.h>        //signal()
#include <string.h>        //memset()
#include <sys/time.h>    //struct itimerval, setitimer()

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include "x86_drv.h"
#include "main.h"

#define GAGENT_TIMER_S_1        1
#define GAGENT_TIMER_US         0

// declare top ,it come from mavlink_control.so
/*
typedef struct __mavlink_attitude_t
{
 uint32_t time_boot_ms; ///< Timestamp (milliseconds since system boot)
 float roll; ///< Roll angle (rad, -pi..+pi)
 float pitch; ///< Pitch angle (rad, -pi..+pi)
 float yaw; ///< Yaw angle (rad, -pi..+pi)
 float rollspeed; ///< Roll angular speed (rad/s)
 float pitchspeed; ///< Pitch angular speed (rad/s)
 float yawspeed; ///< Yaw angular speed (rad/s)
} mavlink_attitude_t;


extern int top(mavlink_attitude_t *attitude);

mavlink_attitude_t G_mavlink_attitude;

*/
mavlink_attitude_t G_mavlink_attitude;

int main(void)
{
    /* 创建gagent进程单独运行 */
	
    //CoreInit();
    IOF_Config_hook_init();
	IOF_General_Hook_Init();
    GAgent_TimerInit();
    X86_Timer_Creat(GAGENT_TIMER_S_1, GAGENT_TIMER_US, x86_timer_handle);       /* 1S */
	
    GAgent_Init();
	top(&G_mavlink_attitude);
    while(1)
    {
        GAgent_TimerRun();
        GAgent_DoBusiness();
//		printf("roll =%f,pitch =%f,yaw =%f,rollspeed =%f,pitchspeed =%f,yawspeed=%f \n",G_mavlink_attitude.roll,G_mavlink_attitude.pitch, G_mavlink_attitude.yaw,G_mavlink_attitude.rollspeed,G_mavlink_attitude.pitchspeed,G_mavlink_attitude.yawspeed);
        sleep(3);
    }
}
