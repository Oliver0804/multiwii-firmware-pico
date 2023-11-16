// MultiWii版本號
#define  VERSION        241
// 航點版本號，用於與GUI同步
#define  NAVI_VERSION   7

// 定義檢查範圍的最小和最大值
#define MINCHECK 1100
#define MAXCHECK 1900

// 以下是一些外部引用變量的宣告，例如：計時器、PID名稱、模式開關名稱等
extern volatile unsigned long timer0_overflow_count;
extern const char pidnames[];
extern const char boxnames[];
extern const uint8_t boxids[];

// 以下是更多外部引用變量的宣告，例如：當前時間、循環時間、校準值、電池最小電壓等
extern uint32_t currentTime;
extern uint16_t previousTime;
extern uint16_t cycleTime;
extern uint16_t calibratingA;
extern uint16_t calibratingB;
extern uint16_t calibratingG;
extern int16_t  magHold,headFreeModeHold;
extern uint8_t  vbatMin;
extern uint8_t  rcOptions[CHECKBOXITEMS];
extern int32_t  AltHold;
extern int16_t  sonarAlt;
extern int16_t  BaroPID;
extern int16_t  errorAltitudeI;

// I2C錯誤計數和警報數組
extern int16_t  i2c_errors_count;
extern uint8_t alarmArray[ALRM_FAC_SIZE];
extern global_conf_t global_conf;

// IMU數據結構和其他相關變量
extern imu_t imu;
extern analog_t analog;
extern alt_t alt;
extern att_t att;
#ifdef LOG_PERMANENT
extern plog_t plog;
#endif

extern int16_t debug[4];

extern conf_t conf;
extern int16_t  annex650_overrun_count;
extern flags_struct_t f;
extern uint16_t intPowerTrigger1;

extern int16_t gyroZero[3];
extern int16_t angle[2];

// GPS相關變量和定義
#if GPS
extern gps_conf_struct GPS_conf;
extern int16_t  GPS_angle[2];           // GPS修正角度
extern int32_t  GPS_coord[2];           // GPS坐標
extern int32_t  GPS_home[2];            // 家的GPS坐標
extern int32_t  GPS_hold[2];            // 保持位置的GPS坐標
extern int32_t  GPS_prev[2];            // 上一個GPS坐標
extern int32_t  GPS_poi[2];             // 興趣點的GPS坐標
extern int32_t  GPS_directionToPoi;     // 興趣點的方向
extern uint8_t  GPS_numSat;             // 衛星數量
extern uint16_t GPS_distanceToHome;     // 與家的距離
extern int16_t  GPS_directionToHome;    // 指向家的方向
extern uint16_t GPS_altitude;           // GPS高度
extern uint16_t GPS_speed;              // GPS速度
extern uint8_t  GPS_update;             // GPS更新標誌
extern uint16_t GPS_ground_course;      // 地面航向
extern uint32_t GPS_time;               // GPS時間
extern uint8_t  GPS_mode;               // GPS模式
// ... 其他GPS相關變量
#endif

// 自動校準加速度計的變量
#if defined(INFLIGHT_ACC_CALIBRATION)
extern uint16_t InflightcalibratingA;
extern int16_t AccInflightCalibrationArmed;
extern uint16_t AccInflightCalibrationMeasurementDone;
extern uint16_t AccInflightCalibrationSavetoEEProm;
extern uint16_t AccInflightCalibrationActive;
#endif

// 其他重要的函式和變量
void annexCode();
void go_disarm();
#endif /* MULTIWII_H_ */
