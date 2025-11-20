#pragma once
// MESSAGE SENSOR_DATA PACKING

#define MAVLINK_MSG_ID_SENSOR_DATA 151


typedef struct __mavlink_sensor_data_t {
 uint32_t utc_time; /*< [s] Thời gian quốc tế UTC*/
 float latitude; /*< [deg] Vĩ độ thu GPS*/
 float longitude; /*< [deg] Kinh độ thu GP*/
 float speed; /*< [m/s] Tốc độ di chuyển*/
 float course; /*< [deg] Hướng di chuyển*/
 float voltage;
 float acc_x; /*< [m/s/s] Gia tốc kế trục X*/
 float acc_y; /*< [m/s/s] Gia tốc kế trục Y*/
 float acc_z; /*< [m/s/s] Gia tốc kế trục Z*/
 float gyro_x; /*< [rad/s] Gia tốc góc X*/
 float gyro_y; /*< [rad/s] Gia tốc góc Y*/
 float gyro_z; /*< [rad/s] Gia tốc góc Z*/
 float temperature; /*< [degC] Nhiệt độ môi trường*/
 float humidity; /*< [%] Độ ẩm không khí*/
 float pressure; /*< [hPa] Áp suất không khí*/
 float co_concentration; /*< [ppm] Nồng độ CO*/
 float pm_diameter; /*< [um] Đường kính hạt bụi*/
 float distance; /*< [m] Khoảng cách đo từ cảm biến trên vệ tinh*/
 uint32_t gps_sample_time; /*< [ms] Thời gian lấy mẫu GPS*/
} mavlink_sensor_data_t;

#define MAVLINK_MSG_ID_SENSOR_DATA_LEN 76
#define MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN 76
#define MAVLINK_MSG_ID_151_LEN 76
#define MAVLINK_MSG_ID_151_MIN_LEN 76

#define MAVLINK_MSG_ID_SENSOR_DATA_CRC 228
#define MAVLINK_MSG_ID_151_CRC 228



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_DATA { \
    151, \
    "SENSOR_DATA", \
    19, \
    {  { "utc_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sensor_data_t, utc_time) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sensor_data_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sensor_data_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sensor_data_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_data_t, course) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sensor_data_t, voltage) }, \
         { "acc_x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sensor_data_t, acc_x) }, \
         { "acc_y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sensor_data_t, acc_y) }, \
         { "acc_z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sensor_data_t, acc_z) }, \
         { "gyro_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sensor_data_t, gyro_x) }, \
         { "gyro_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sensor_data_t, gyro_y) }, \
         { "gyro_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sensor_data_t, gyro_z) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sensor_data_t, temperature) }, \
         { "humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sensor_data_t, humidity) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sensor_data_t, pressure) }, \
         { "co_concentration", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sensor_data_t, co_concentration) }, \
         { "pm_diameter", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sensor_data_t, pm_diameter) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sensor_data_t, distance) }, \
         { "gps_sample_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 72, offsetof(mavlink_sensor_data_t, gps_sample_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_DATA { \
    "SENSOR_DATA", \
    19, \
    {  { "utc_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_sensor_data_t, utc_time) }, \
         { "latitude", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_sensor_data_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_sensor_data_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_sensor_data_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_data_t, course) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_sensor_data_t, voltage) }, \
         { "acc_x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_sensor_data_t, acc_x) }, \
         { "acc_y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sensor_data_t, acc_y) }, \
         { "acc_z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sensor_data_t, acc_z) }, \
         { "gyro_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sensor_data_t, gyro_x) }, \
         { "gyro_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sensor_data_t, gyro_y) }, \
         { "gyro_z", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sensor_data_t, gyro_z) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_sensor_data_t, temperature) }, \
         { "humidity", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_sensor_data_t, humidity) }, \
         { "pressure", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_sensor_data_t, pressure) }, \
         { "co_concentration", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_sensor_data_t, co_concentration) }, \
         { "pm_diameter", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_sensor_data_t, pm_diameter) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_sensor_data_t, distance) }, \
         { "gps_sample_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 72, offsetof(mavlink_sensor_data_t, gps_sample_time) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param utc_time [s] Thời gian quốc tế UTC
 * @param latitude [deg] Vĩ độ thu GPS
 * @param longitude [deg] Kinh độ thu GP
 * @param speed [m/s] Tốc độ di chuyển
 * @param course [deg] Hướng di chuyển
 * @param voltage [V] Điện áp pin đo được
 * @param acc_x [m/s/s] Gia tốc kế trục X
 * @param acc_y [m/s/s] Gia tốc kế trục Y
 * @param acc_z [m/s/s] Gia tốc kế trục Z
 * @param gyro_x [rad/s] Gia tốc góc X
 * @param gyro_y [rad/s] Gia tốc góc Y
 * @param gyro_z [rad/s] Gia tốc góc Z
 * @param temperature [degC] Nhiệt độ môi trường
 * @param humidity [%] Độ ẩm không khí
 * @param pressure [hPa] Áp suất không khí
 * @param co_concentration [ppm] Nồng độ CO
 * @param pm_diameter [um] Đường kính hạt bụi
 * @param distance [m] Khoảng cách đo từ cảm biến trên vệ tinh
 * @param gps_sample_time [ms] Thời gian lấy mẫu GPS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t utc_time, float latitude, float longitude, float speed, float course, float voltage, float acc_x, float acc_y, float acc_z, float gyro_x, float gyro_y, float gyro_z, float temperature, float humidity, float pressure, float co_concentration, float pm_diameter, float distance, uint32_t gps_sample_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, utc_time);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, longitude);
    _mav_put_float(buf, 12, speed);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, voltage);
    _mav_put_float(buf, 24, acc_x);
    _mav_put_float(buf, 28, acc_y);
    _mav_put_float(buf, 32, acc_z);
    _mav_put_float(buf, 36, gyro_x);
    _mav_put_float(buf, 40, gyro_y);
    _mav_put_float(buf, 44, gyro_z);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, humidity);
    _mav_put_float(buf, 56, pressure);
    _mav_put_float(buf, 60, co_concentration);
    _mav_put_float(buf, 64, pm_diameter);
    _mav_put_float(buf, 68, distance);
    _mav_put_uint32_t(buf, 72, gps_sample_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#else
    mavlink_sensor_data_t packet;
    packet.utc_time = utc_time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.speed = speed;
    packet.course = course;
    packet.voltage = voltage;
    packet.acc_x = acc_x;
    packet.acc_y = acc_y;
    packet.acc_z = acc_z;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;
    packet.temperature = temperature;
    packet.humidity = humidity;
    packet.pressure = pressure;
    packet.co_concentration = co_concentration;
    packet.pm_diameter = pm_diameter;
    packet.distance = distance;
    packet.gps_sample_time = gps_sample_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
}

/**
 * @brief Pack a sensor_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param utc_time [s] Thời gian quốc tế UTC
 * @param latitude [deg] Vĩ độ thu GPS
 * @param longitude [deg] Kinh độ thu GP
 * @param speed [m/s] Tốc độ di chuyển
 * @param course [deg] Hướng di chuyển
 * @param voltage [V] Điện áp pin đo được
 * @param acc_x [m/s/s] Gia tốc kế trục X
 * @param acc_y [m/s/s] Gia tốc kế trục Y
 * @param acc_z [m/s/s] Gia tốc kế trục Z
 * @param gyro_x [rad/s] Gia tốc góc X
 * @param gyro_y [rad/s] Gia tốc góc Y
 * @param gyro_z [rad/s] Gia tốc góc Z
 * @param temperature [degC] Nhiệt độ môi trường
 * @param humidity [%] Độ ẩm không khí
 * @param pressure [hPa] Áp suất không khí
 * @param co_concentration [ppm] Nồng độ CO
 * @param pm_diameter [um] Đường kính hạt bụi
 * @param distance [m] Khoảng cách đo từ cảm biến trên vệ tinh
 * @param gps_sample_time [ms] Thời gian lấy mẫu GPS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t utc_time, float latitude, float longitude, float speed, float course, float voltage, float acc_x, float acc_y, float acc_z, float gyro_x, float gyro_y, float gyro_z, float temperature, float humidity, float pressure, float co_concentration, float pm_diameter, float distance, uint32_t gps_sample_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, utc_time);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, longitude);
    _mav_put_float(buf, 12, speed);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, voltage);
    _mav_put_float(buf, 24, acc_x);
    _mav_put_float(buf, 28, acc_y);
    _mav_put_float(buf, 32, acc_z);
    _mav_put_float(buf, 36, gyro_x);
    _mav_put_float(buf, 40, gyro_y);
    _mav_put_float(buf, 44, gyro_z);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, humidity);
    _mav_put_float(buf, 56, pressure);
    _mav_put_float(buf, 60, co_concentration);
    _mav_put_float(buf, 64, pm_diameter);
    _mav_put_float(buf, 68, distance);
    _mav_put_uint32_t(buf, 72, gps_sample_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#else
    mavlink_sensor_data_t packet;
    packet.utc_time = utc_time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.speed = speed;
    packet.course = course;
    packet.voltage = voltage;
    packet.acc_x = acc_x;
    packet.acc_y = acc_y;
    packet.acc_z = acc_z;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;
    packet.temperature = temperature;
    packet.humidity = humidity;
    packet.pressure = pressure;
    packet.co_concentration = co_concentration;
    packet.pm_diameter = pm_diameter;
    packet.distance = distance;
    packet.gps_sample_time = gps_sample_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif
}

/**
 * @brief Pack a sensor_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param utc_time [s] Thời gian quốc tế UTC
 * @param latitude [deg] Vĩ độ thu GPS
 * @param longitude [deg] Kinh độ thu GP
 * @param speed [m/s] Tốc độ di chuyển
 * @param course [deg] Hướng di chuyển
 * @param voltage [V] Điện áp pin đo được
 * @param acc_x [m/s/s] Gia tốc kế trục X
 * @param acc_y [m/s/s] Gia tốc kế trục Y
 * @param acc_z [m/s/s] Gia tốc kế trục Z
 * @param gyro_x [rad/s] Gia tốc góc X
 * @param gyro_y [rad/s] Gia tốc góc Y
 * @param gyro_z [rad/s] Gia tốc góc Z
 * @param temperature [degC] Nhiệt độ môi trường
 * @param humidity [%] Độ ẩm không khí
 * @param pressure [hPa] Áp suất không khí
 * @param co_concentration [ppm] Nồng độ CO
 * @param pm_diameter [um] Đường kính hạt bụi
 * @param distance [m] Khoảng cách đo từ cảm biến trên vệ tinh
 * @param gps_sample_time [ms] Thời gian lấy mẫu GPS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t utc_time,float latitude,float longitude,float speed,float course,float voltage,float acc_x,float acc_y,float acc_z,float gyro_x,float gyro_y,float gyro_z,float temperature,float humidity,float pressure,float co_concentration,float pm_diameter,float distance,uint32_t gps_sample_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, utc_time);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, longitude);
    _mav_put_float(buf, 12, speed);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, voltage);
    _mav_put_float(buf, 24, acc_x);
    _mav_put_float(buf, 28, acc_y);
    _mav_put_float(buf, 32, acc_z);
    _mav_put_float(buf, 36, gyro_x);
    _mav_put_float(buf, 40, gyro_y);
    _mav_put_float(buf, 44, gyro_z);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, humidity);
    _mav_put_float(buf, 56, pressure);
    _mav_put_float(buf, 60, co_concentration);
    _mav_put_float(buf, 64, pm_diameter);
    _mav_put_float(buf, 68, distance);
    _mav_put_uint32_t(buf, 72, gps_sample_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#else
    mavlink_sensor_data_t packet;
    packet.utc_time = utc_time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.speed = speed;
    packet.course = course;
    packet.voltage = voltage;
    packet.acc_x = acc_x;
    packet.acc_y = acc_y;
    packet.acc_z = acc_z;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;
    packet.temperature = temperature;
    packet.humidity = humidity;
    packet.pressure = pressure;
    packet.co_concentration = co_concentration;
    packet.pm_diameter = pm_diameter;
    packet.distance = distance;
    packet.gps_sample_time = gps_sample_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
}

/**
 * @brief Encode a sensor_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_data_t* sensor_data)
{
    return mavlink_msg_sensor_data_pack(system_id, component_id, msg, sensor_data->utc_time, sensor_data->latitude, sensor_data->longitude, sensor_data->speed, sensor_data->course, sensor_data->voltage, sensor_data->acc_x, sensor_data->acc_y, sensor_data->acc_z, sensor_data->gyro_x, sensor_data->gyro_y, sensor_data->gyro_z, sensor_data->temperature, sensor_data->humidity, sensor_data->pressure, sensor_data->co_concentration, sensor_data->pm_diameter, sensor_data->distance, sensor_data->gps_sample_time);
}

/**
 * @brief Encode a sensor_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_data_t* sensor_data)
{
    return mavlink_msg_sensor_data_pack_chan(system_id, component_id, chan, msg, sensor_data->utc_time, sensor_data->latitude, sensor_data->longitude, sensor_data->speed, sensor_data->course, sensor_data->voltage, sensor_data->acc_x, sensor_data->acc_y, sensor_data->acc_z, sensor_data->gyro_x, sensor_data->gyro_y, sensor_data->gyro_z, sensor_data->temperature, sensor_data->humidity, sensor_data->pressure, sensor_data->co_concentration, sensor_data->pm_diameter, sensor_data->distance, sensor_data->gps_sample_time);
}

/**
 * @brief Encode a sensor_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param sensor_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_sensor_data_t* sensor_data)
{
    return mavlink_msg_sensor_data_pack_status(system_id, component_id, _status, msg,  sensor_data->utc_time, sensor_data->latitude, sensor_data->longitude, sensor_data->speed, sensor_data->course, sensor_data->voltage, sensor_data->acc_x, sensor_data->acc_y, sensor_data->acc_z, sensor_data->gyro_x, sensor_data->gyro_y, sensor_data->gyro_z, sensor_data->temperature, sensor_data->humidity, sensor_data->pressure, sensor_data->co_concentration, sensor_data->pm_diameter, sensor_data->distance, sensor_data->gps_sample_time);
}

/**
 * @brief Send a sensor_data message
 * @param chan MAVLink channel to send the message
 *
 * @param utc_time [s] Thời gian quốc tế UTC
 * @param latitude [deg] Vĩ độ thu GPS
 * @param longitude [deg] Kinh độ thu GP
 * @param speed [m/s] Tốc độ di chuyển
 * @param course [deg] Hướng di chuyển
 * @param voltage [V] Điện áp pin đo được
 * @param acc_x [m/s/s] Gia tốc kế trục X
 * @param acc_y [m/s/s] Gia tốc kế trục Y
 * @param acc_z [m/s/s] Gia tốc kế trục Z
 * @param gyro_x [rad/s] Gia tốc góc X
 * @param gyro_y [rad/s] Gia tốc góc Y
 * @param gyro_z [rad/s] Gia tốc góc Z
 * @param temperature [degC] Nhiệt độ môi trường
 * @param humidity [%] Độ ẩm không khí
 * @param pressure [hPa] Áp suất không khí
 * @param co_concentration [ppm] Nồng độ CO
 * @param pm_diameter [um] Đường kính hạt bụi
 * @param distance [m] Khoảng cách đo từ cảm biến trên vệ tinh
 * @param gps_sample_time [ms] Thời gian lấy mẫu GPS
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_data_send(mavlink_channel_t chan, uint32_t utc_time, float latitude, float longitude, float speed, float course, float voltage, float acc_x, float acc_y, float acc_z, float gyro_x, float gyro_y, float gyro_z, float temperature, float humidity, float pressure, float co_concentration, float pm_diameter, float distance, uint32_t gps_sample_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_DATA_LEN];
    _mav_put_uint32_t(buf, 0, utc_time);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, longitude);
    _mav_put_float(buf, 12, speed);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, voltage);
    _mav_put_float(buf, 24, acc_x);
    _mav_put_float(buf, 28, acc_y);
    _mav_put_float(buf, 32, acc_z);
    _mav_put_float(buf, 36, gyro_x);
    _mav_put_float(buf, 40, gyro_y);
    _mav_put_float(buf, 44, gyro_z);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, humidity);
    _mav_put_float(buf, 56, pressure);
    _mav_put_float(buf, 60, co_concentration);
    _mav_put_float(buf, 64, pm_diameter);
    _mav_put_float(buf, 68, distance);
    _mav_put_uint32_t(buf, 72, gps_sample_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, buf, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#else
    mavlink_sensor_data_t packet;
    packet.utc_time = utc_time;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.speed = speed;
    packet.course = course;
    packet.voltage = voltage;
    packet.acc_x = acc_x;
    packet.acc_y = acc_y;
    packet.acc_z = acc_z;
    packet.gyro_x = gyro_x;
    packet.gyro_y = gyro_y;
    packet.gyro_z = gyro_z;
    packet.temperature = temperature;
    packet.humidity = humidity;
    packet.pressure = pressure;
    packet.co_concentration = co_concentration;
    packet.pm_diameter = pm_diameter;
    packet.distance = distance;
    packet.gps_sample_time = gps_sample_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}

/**
 * @brief Send a sensor_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_data_send_struct(mavlink_channel_t chan, const mavlink_sensor_data_t* sensor_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_data_send(chan, sensor_data->utc_time, sensor_data->latitude, sensor_data->longitude, sensor_data->speed, sensor_data->course, sensor_data->voltage, sensor_data->acc_x, sensor_data->acc_y, sensor_data->acc_z, sensor_data->gyro_x, sensor_data->gyro_y, sensor_data->gyro_z, sensor_data->temperature, sensor_data->humidity, sensor_data->pressure, sensor_data->co_concentration, sensor_data->pm_diameter, sensor_data->distance, sensor_data->gps_sample_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)sensor_data, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t utc_time, float latitude, float longitude, float speed, float course, float voltage, float acc_x, float acc_y, float acc_z, float gyro_x, float gyro_y, float gyro_z, float temperature, float humidity, float pressure, float co_concentration, float pm_diameter, float distance, uint32_t gps_sample_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, utc_time);
    _mav_put_float(buf, 4, latitude);
    _mav_put_float(buf, 8, longitude);
    _mav_put_float(buf, 12, speed);
    _mav_put_float(buf, 16, course);
    _mav_put_float(buf, 20, voltage);
    _mav_put_float(buf, 24, acc_x);
    _mav_put_float(buf, 28, acc_y);
    _mav_put_float(buf, 32, acc_z);
    _mav_put_float(buf, 36, gyro_x);
    _mav_put_float(buf, 40, gyro_y);
    _mav_put_float(buf, 44, gyro_z);
    _mav_put_float(buf, 48, temperature);
    _mav_put_float(buf, 52, humidity);
    _mav_put_float(buf, 56, pressure);
    _mav_put_float(buf, 60, co_concentration);
    _mav_put_float(buf, 64, pm_diameter);
    _mav_put_float(buf, 68, distance);
    _mav_put_uint32_t(buf, 72, gps_sample_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, buf, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#else
    mavlink_sensor_data_t *packet = (mavlink_sensor_data_t *)msgbuf;
    packet->utc_time = utc_time;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->speed = speed;
    packet->course = course;
    packet->voltage = voltage;
    packet->acc_x = acc_x;
    packet->acc_y = acc_y;
    packet->acc_z = acc_z;
    packet->gyro_x = gyro_x;
    packet->gyro_y = gyro_y;
    packet->gyro_z = gyro_z;
    packet->temperature = temperature;
    packet->humidity = humidity;
    packet->pressure = pressure;
    packet->co_concentration = co_concentration;
    packet->pm_diameter = pm_diameter;
    packet->distance = distance;
    packet->gps_sample_time = gps_sample_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_DATA, (const char *)packet, MAVLINK_MSG_ID_SENSOR_DATA_MIN_LEN, MAVLINK_MSG_ID_SENSOR_DATA_LEN, MAVLINK_MSG_ID_SENSOR_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSOR_DATA UNPACKING


/**
 * @brief Get field utc_time from sensor_data message
 *
 * @return [s] Thời gian quốc tế UTC
 */
static inline uint32_t mavlink_msg_sensor_data_get_utc_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field latitude from sensor_data message
 *
 * @return [deg] Vĩ độ thu GPS
 */
static inline float mavlink_msg_sensor_data_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field longitude from sensor_data message
 *
 * @return [deg] Kinh độ thu GP
 */
static inline float mavlink_msg_sensor_data_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field speed from sensor_data message
 *
 * @return [m/s] Tốc độ di chuyển
 */
static inline float mavlink_msg_sensor_data_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field course from sensor_data message
 *
 * @return [deg] Hướng di chuyển
 */
static inline float mavlink_msg_sensor_data_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field voltage from sensor_data message
 *
 * @return [V] Điện áp pin đo được
 */
static inline float mavlink_msg_sensor_data_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field acc_x from sensor_data message
 *
 * @return [m/s/s] Gia tốc kế trục X
 */
static inline float mavlink_msg_sensor_data_get_acc_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field acc_y from sensor_data message
 *
 * @return [m/s/s] Gia tốc kế trục Y
 */
static inline float mavlink_msg_sensor_data_get_acc_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field acc_z from sensor_data message
 *
 * @return [m/s/s] Gia tốc kế trục Z
 */
static inline float mavlink_msg_sensor_data_get_acc_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field gyro_x from sensor_data message
 *
 * @return [rad/s] Gia tốc góc X
 */
static inline float mavlink_msg_sensor_data_get_gyro_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field gyro_y from sensor_data message
 *
 * @return [rad/s] Gia tốc góc Y
 */
static inline float mavlink_msg_sensor_data_get_gyro_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field gyro_z from sensor_data message
 *
 * @return [rad/s] Gia tốc góc Z
 */
static inline float mavlink_msg_sensor_data_get_gyro_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field temperature from sensor_data message
 *
 * @return [degC] Nhiệt độ môi trường
 */
static inline float mavlink_msg_sensor_data_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field humidity from sensor_data message
 *
 * @return [%] Độ ẩm không khí
 */
static inline float mavlink_msg_sensor_data_get_humidity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field pressure from sensor_data message
 *
 * @return [hPa] Áp suất không khí
 */
static inline float mavlink_msg_sensor_data_get_pressure(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field co_concentration from sensor_data message
 *
 * @return [ppm] Nồng độ CO
 */
static inline float mavlink_msg_sensor_data_get_co_concentration(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field pm_diameter from sensor_data message
 *
 * @return [um] Đường kính hạt bụi
 */
static inline float mavlink_msg_sensor_data_get_pm_diameter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field distance from sensor_data message
 *
 * @return [m] Khoảng cách đo từ cảm biến trên vệ tinh
 */
static inline float mavlink_msg_sensor_data_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field gps_sample_time from sensor_data message
 *
 * @return [ms] Thời gian lấy mẫu GPS
 */
static inline uint32_t mavlink_msg_sensor_data_get_gps_sample_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  72);
}

/**
 * @brief Decode a sensor_data message into a struct
 *
 * @param msg The message to decode
 * @param sensor_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_data_decode(const mavlink_message_t* msg, mavlink_sensor_data_t* sensor_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sensor_data->utc_time = mavlink_msg_sensor_data_get_utc_time(msg);
    sensor_data->latitude = mavlink_msg_sensor_data_get_latitude(msg);
    sensor_data->longitude = mavlink_msg_sensor_data_get_longitude(msg);
    sensor_data->speed = mavlink_msg_sensor_data_get_speed(msg);
    sensor_data->course = mavlink_msg_sensor_data_get_course(msg);
    sensor_data->voltage = mavlink_msg_sensor_data_get_voltage(msg);
    sensor_data->acc_x = mavlink_msg_sensor_data_get_acc_x(msg);
    sensor_data->acc_y = mavlink_msg_sensor_data_get_acc_y(msg);
    sensor_data->acc_z = mavlink_msg_sensor_data_get_acc_z(msg);
    sensor_data->gyro_x = mavlink_msg_sensor_data_get_gyro_x(msg);
    sensor_data->gyro_y = mavlink_msg_sensor_data_get_gyro_y(msg);
    sensor_data->gyro_z = mavlink_msg_sensor_data_get_gyro_z(msg);
    sensor_data->temperature = mavlink_msg_sensor_data_get_temperature(msg);
    sensor_data->humidity = mavlink_msg_sensor_data_get_humidity(msg);
    sensor_data->pressure = mavlink_msg_sensor_data_get_pressure(msg);
    sensor_data->co_concentration = mavlink_msg_sensor_data_get_co_concentration(msg);
    sensor_data->pm_diameter = mavlink_msg_sensor_data_get_pm_diameter(msg);
    sensor_data->distance = mavlink_msg_sensor_data_get_distance(msg);
    sensor_data->gps_sample_time = mavlink_msg_sensor_data_get_gps_sample_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_DATA_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_DATA_LEN;
        memset(sensor_data, 0, MAVLINK_MSG_ID_SENSOR_DATA_LEN);
    memcpy(sensor_data, _MAV_PAYLOAD(msg), len);
#endif
}
