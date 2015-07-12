#ifndef __MAVLINK__
#define __MAVLINK__



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

extern mavlink_attitude_t G_mavlink_attitude;
extern int top(mavlink_attitude_t *attitude);


#endif
