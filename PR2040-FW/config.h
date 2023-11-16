#ifndef CONFIG_H_
#define CONFIG_H_
/*************************************************************************************************/
/****           可配置參數                                                                     ****/
/*************************************************************************************************/

/* 此文件包含數個部分
   為了創建一個有效的組合，您至少需要在第1部分中進行選擇。
   1 - 基本設置 - 您必須在每個塊中選擇一個選項。
      這假設您的控制板連接了4個標準電子調速器和伺服器的通道。
   2 - 特定於多軸飛行器類型的選項 - 您可能希望檢查您的飛行器類型的選項
   3 - 遙控系統設置
   4 - 替代CPU和控制板 - 如果您擁有
   5 - 替代設置 - 在此選擇替代接收器（SBUS、PPM等）、替代電子調速器範圍等
   6 - 可選功能 - 在此啟用一些不錯的功能（飛行模式、LCD、遙測、電池監控等）
   7 - 調試和開發 - 如果您知道自己在做什麼；您已被警告
      -（電子調速器校準、動力/螺旋槳動態平衡、診斷、記憶體節省等）
   8 - 已過時的功能 - 這些功能將在未來的某個版本中被移除
*/

/* 注釋：
   1. 註釋中帶有（*）的參數存儲在EEPROM中，可以通過串口監視器或LCD更改。
   2. 註釋中帶有（**）的參數存儲在EEPROM中，可以通過GUI更改。
*/

/*************************************************************************************************/
/*****************                                                                         ***************/
/****************  第1節 - 基本設置                                                           *******/
/*****************                                                                         ***************/
/*************************************************************************************************/

/**************************    多軸飛行器的類型    ****************************/
//#define GIMBAL
//#define BI
//#define TRI
//#define QUADP
//#define QUADX
//#define Y4
//#define Y6
//#define HEX6
//#define HEX6X
//#define HEX6H  // 新型號
//#define OCTOX8
//#define OCTOFLATP
//#define OCTOFLATX
//#define FLYING_WING
//#define VTAIL4
//#define AIRPLANE
//#define SINGLECOPTER
//#define DUALCOPTER
//#define HELI_120_CCPM
//#define HELI_90_DEG

/****************************    馬達最低油門    *******************************/
/* 設置發送到ESC（電子調速器）的最小油門指令
   這是讓馬達以怠速運行的最小值 */
//#define MINTHROTTLE 1300 // 對於Turnigy Plush 10A ESC
//#define MINTHROTTLE 1120 // 對於Super Simple 10A ESC
//#define MINTHROTTLE 1064 // 特殊ESC（simonk）
//#define MINTHROTTLE 1050 // 對於ladybird之類的刷式ESC
#define MINTHROTTLE 1150 // (*) (**)

/****************************    馬達最高油門    *******************************/
/* 這是全功率時ESC的最大值，這個值可以提高到2000 */
#define MAXTHROTTLE 1850

/****************************    最小指令          *******************************/
/* 這是當ESC未解鎖時的值
   在某些情況下，對於某些特定的ESC，這個值必須降低到900，否則它們無法啟動 */
#define MINCOMMAND  1000

/**********************************  舊WMP配置的I2C速度（對其他傳感器無效）  *************/
#define I2C_SPEED 100000L     //100kHz正常模式，這個值應該用於正版WMP
//#define I2C_SPEED 400000L   //400kHz快速模式，僅在某些WMP克隆上有效

/***************************    內部i2c上拉   ********************************/
/* 啟用內部I2C上拉（在大多數情況下，使用外部上拉更好） */
//#define INTERNAL_I2C_PULLUPS

/**********************************  恆定循環時間  ******************************/
#define LOOP_TIME 2800

/**************************************************************************************/
/*****************          控制板和傳感器定義                      ******************/
/**************************************************************************************/

/***************************    綜合IMU控制板    ********************************/
/* 如果您使用特定的傳感器控制板：
   如有任何修正，請提交到此列表。
   Alex的注釋：我只擁有一些控制板，對於其他控制板，我不太確定，這些信息是通過遙控論壇收集的，請謹慎使用 */
//#define FFIMUv1         // Jussi的第一個9DOF+氣壓計控制板，帶有HMC5843                   <- Alex已確認
//#define FFIMUv2         // Jussi的第二個9DOF+氣壓計控制板版本，帶有HMC5883                 <- Alex已確認
//#define FREEIMUv1       // Fabio的9DOF控制板v0.1 & v0.2 & v0.3版本
//#define FREEIMUv03      // FreeIMU v0.3 和 v0.3.1
//#define FREEIMUv035     // FreeIMU v0.3.5 無氣壓計
//#define FREEIMUv035_MS  // FreeIMU v0.3.5_MS                                                <- Alex已確認
//#define FREEIMUv035_BMP // FreeIMU v0.3.5_BMP
//#define FREEIMUv04      // FreeIMU v0.4，帶MPU6050, HMC5883L, MS561101BA                     <- Alex已確認
//#define FREEIMUv043     // 同FREEIMUv04，最終版MPU6050（正確的ACC比例）
//#define NANOWII         // 基於MPU6050 + pro micro的最小MultiWii FC                        <- Alex已確認
//#define PIPO            // erazz的9DOF控制板
//#define QUADRINO        // witespy的全功能9DOF+氣壓計控制板，帶BMP085氣壓計                  <- Alex已確認
//#define QUADRINO_ZOOM   // witespy的全功能9DOF+氣壓計控制板第二版
//#define QUADRINO_ZOOM_MS// witespy的全功能9DOF+氣壓計控制板第二版                            <- Alex已確認
//#define QUADRINO_NANO   // Lynxmotion / RobotShop的全功能9DOF+氣壓計控制板+GPS                 <- Alex已確認
//#define ALLINONE        // CSG_EU的全功能或獨立9DOF+氣壓計控制板
//#define AEROQUADSHIELDv2
//#define ATAVRSBIN1      // Atmel的9DOF（EOSBandi貢獻）。需要3.3V電源。
//#define SIRIUS          // Sirius導航IMU                                                     <- Alex已確認
//#define SIRIUSGPS       // 使用外部MAG在GPS板上的Sirius導航IMU                               <- Alex已確認
//#define SIRIUS600       // 使用WMP作為陀螺儀的Sirius導航IMU
//#define SIRIUS_AIR      // MultiWiiCopter.com的Sirius導航IMU 6050 32U4                       <- Alex已確認
//#define SIRIUS_AIR_GPS  // MultiWiiCopter.com的Sirius導航IMU 6050 32U4，帶有遠程GPS/MAG
//#define SIRIUS_MEGAv5_OSD //  Paris_Sirius™ ITG3050,BMA280,MS5611,HMC5883,uBlox  http://www.Multiwiicopter.com <- Alex已確認
//#define MINIWII         // Jussi的MiniWii飛控                                                <- Alex已確認
//#define MICROWII        // http://flyduino.net/的MicroWii 10DOF，帶ATmega32u4, MPU6050, HMC5883L, MS561101BA
//#define CITRUSv2_1      // qcrc.ca的CITRUS
//#define CHERRY6DOFv1_0
//#define DROTEK_10DOF    // Drotek的10DOF，帶ITG3200, BMA180, HMC5883, BMP085，帶或不帶LLC
//#define DROTEK_10DOF_MS // Drotek的10DOF，帶ITG3200, BMA180, HMC5883, MS5611, LLC
//#define DROTEK_6DOFv2   // Drotek的6DOF v2
//#define DROTEK_6DOF_MPU // Drotek的6DOF，帶MPU6050
//#define DROTEK_10DOF_MPU//
//#define MONGOOSE1_0     // mongoose 1.0    http://store.ckdevices.com/
//#define CRIUS_LITE      // Crius MultiWii Lite
//#define CRIUS_SE        // Crius MultiWii SE
//#define CRIUS_SE_v2_0   // Crius MultiWii SE 2.0，帶MPU6050, HMC5883和BMP085
//#define OPENLRSv2MULTI  // OpenLRS v2多路遙控接收器板，包括ITG3205和ADXL345
//#define BOARD_PROTO_1   // 帶MPU6050 + HMC5883L + MS氣壓計
//#define BOARD_PROTO_2   // 帶MPU6050 + 從屬MAG3110 + MS氣壓計
//#define GY_80           // 中國10DOF，帶L3G4200D ADXL345 HMC5883L BMP085，LLC
//#define GY_85           // 中國9DOF，帶ITG3205 ADXL345 HMC5883L LLC
//#define GY_86           // 中國10DOF，帶MPU6050 HMC5883L MS5611，LLC
//#define GY_88           // 中國10DOF，帶MPU6050 HMC5883L BMP085，LLC
//#define GY_521          // 中國6DOF，帶MPU6050，LLC
//#define INNOVWORKS_10DOF // 帶ITG3200, BMA180, HMC5883, BMP085的INNOVWORKS 10DOF，可在此處獲得 http://www.diymulticopter.com
//#define INNOVWORKS_6DOF // 帶ITG3200, BMA180的INNOVWORKS 6DOF，可在此處獲得 http://www.diymulticopter.com
//#define MultiWiiMega    // MEGA + MPU6050+HMC5883L+MS5611，可在此處獲得 http://www.diymulticopter.com
//#define PROTO_DIY       // 10DOF mega控制板
//#define IOI_MINI_MULTIWII// www.bambucopter.com
//#define Bobs_6DOF_V1     // BobsQuads的6DOF V1，帶ITG3200 & BMA180
//#define Bobs_9DOF_V1     // BobsQuads的9DOF V1，帶ITG3200, BMA180 & HMC5883L
//#define Bobs_10DOF_BMP_V1 // BobsQuads的10DOF V1，帶ITG3200, BMA180, HMC5883L & BMP180 - BMP180與BMP085軟件兼容
//#define FLYDUINO_MPU       // MPU6050 Break Out板載3.3V穩壓器
//#define CRIUS_AIO_PRO
//#define DESQUARED6DOFV2GO  // DEsquared V2，僅帶ITG3200
//#define DESQUARED6DOFV4    // DEsquared V4，帶MPU6050
//#define LADYBIRD
//#define MEGAWAP_V2_STD     // 可在此處獲得：http://www.multircshop.com                    <- Alex已確認
//#define MEGAWAP_V2_ADV
//#define HK_MultiWii_SE_V2  // Hobbyking控制板，帶MPU6050 + HMC5883L + BMP085
//#define HK_MultiWii_328P   // 背面標記為"Hobbybro"。ITG3205 + BMA180 + BMP085 + NMC5583L + DSM2接頭（Spektrum衛星）
//#define RCNet_FC           // RCNet飛控，帶MPU6050和MS561101BA  http://www.rcnet.com
//#define RCNet_FC_GPS       // RCNet飛控，帶MPU6050 + MS561101BA + HMC5883L + UBLOX GPS http://www.rcnet.com
//#define FLYDU_ULTRA        // MEGA+10DOF+MT3339飛控
//#define DIYFLYING_MAGE_V1  // diyflying的10DOF mega控制板，帶MPU6050 + HMC5883L + BMP085 http://www.indoor-flying.hk
//#define MultiWii_32U4_SE         // Hextronik的MultiWii_32U4_SE
//#define MultiWii_32U4_SE_no_baro // Hextronik的MultiWii_32U4_SE，無MS561101BA以釋放快閃存儲器以供其他功能使用
//#define Flyduino9DOF       // Flyduino的9DOF IMU MPU6050+HMC5883l
//#define Nano_Plane         // 帶LSM330尾部-前傳感器的Multiwii飛機版本 http://www.radiosait.ru/en/page_5324.html

/***************************    獨立傳感器    ********************************/
/* 如果您已經選擇了上面的特定控制板，請保持註釋 */
/* I2C陀螺儀 */
//#define WMP
//#define ITG3050
//#define ITG3200
//#define MPU3050
//#define L3G4200D
//#define MPU6050       //組合 + 加速度計
//#define LSM330        //組合 + 加速度計

/* I2C加速度計 */
//#define MMA7455
//#define ADXL345
//#define BMA020
//#define BMA180
//#define BMA280
//#define LIS3LV02
//#define LSM303DLx_ACC
//#define MMA8451Q

/* I2C氣壓計 */
//#define BMP085
//#define MS561101BA

/* I2C磁力計 */
//#define HMC5843
//#define HMC5883
//#define AK8975
//#define MAG3110

/* 超聲波測距儀 */ // 目前僅用於可視化目的 - 暫無控制代碼
//#define SRF02 // 使用Devantech SRF i2c傳感器
//#define SRF08
//#define SRF10
//#define SRF23

/* ADC加速度計 */ // 來自sparkfun的5DOF，使用模擬引腳A1/A2/A3
//#define ADCACC

/* 強制設定個別感測器方向 - 即使覆蓋了特定板的預設值 */
//#define FORCE_ACC_ORIENTATION(X, Y, Z)  {imu.accADC[ROLL]  =  Y; imu.accADC[PITCH]  = -X; imu.accADC[YAW]  = Z;}
//#define FORCE_GYRO_ORIENTATION(X, Y, Z) {imu.gyroADC[ROLL] = -Y; imu.gyroADC[PITCH] =  X; imu.gyroADC[YAW] = Z;}
//#define FORCE_MAG_ORIENTATION(X, Y, Z)  {imu.magADC[ROLL]  =  X; imu.magADC[PITCH]  =  Y; imu.magADC[YAW]  = Z;}

/* 板子方向位移 */
/* 如果你的機架僅適用於+模式，並且你無法物理上旋轉FC以進行X模式飛行（反之亦然），
   您可以使用以下其中一個選項來虛擬感測器旋轉45度，然後根據飛行模式設定多旋翼類型。
   檢查馬達的排列順序和馬達旋轉方向，以匹配新的前方指向！取消註釋僅一個選項！ */
//#define SENSORS_TILT_45DEG_RIGHT        // 順時針旋轉前方45度
//#define SENSORS_TILT_45DEG_LEFT         // 逆時針旋轉前方45度

/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  第 2 部分 - 多旋翼類型特定選項                                *******/
/*****************                                                                 ***************/
/*************************************************************************************************/
/********************************  PID 控制器 *********************************/
/* 選擇其中一種替代的 PID 控制算法
   1 = 進化的老式算法（類似於 v2.2）
   2 = 來自 Alex Khoroshko 的新實驗性算法 - 不支援 - http://www.multiwii.com/forum/viewtopic.php?f=8&t=3671&start=10#p37387
 * */
#define PID_CONTROLLER 1

/* NEW: 不再用於伺服多旋翼類型  <== 需要修復 - 移至 WIKI */
#define YAW_DIRECTION 1
//#define YAW_DIRECTION -1 // 如果您想反轉偏航校正方向

#define ONLYARMWHENFLAT // 防止多旋翼傾斜時啟動馬達

/********************************    啟動/停止    *********************************/
/* 可選地禁用操縱桿組合以啟動/停止馬達。
    在大多數情況下，通過TX操縱桿之一來啟動/停止是足夠的 */
#define ALLOW_ARM_DISARM_VIA_TX_YAW
//#define ALLOW_ARM_DISARM_VIA_TX_ROLL

/********************************    伺服      *********************************/
/* 有關伺服連接在哪裡以及如何設置的信息可以在此找到
   http://www.multiwii.com/wiki/index.php?title=Config.h#Servos_configuration
*/

/* 如果多旋翼未啟動，則不要移動伺服
   這是一個快速修復，以克服多旋翼具有柔軟
   起落架時的尾部抖動
*/
//#define DISABLE_SERVOS_WHEN_UNARMED

/* 如果您想要在刷機之後立即設置伺服的最小/中間/最大值，因為伺服行程有限，則必須啟用並設置以下三個選項 */
//#define SERVO_MIN  {1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020}
//#define  SERVO_MAX {2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000}
//#define  SERVO_MID {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500} // (*)
//#define FORCE_SERVO_RATES      {30,30,100,100,100,100,100,100} // 0 = 正常, 1= 反向

/***********************          攝影機穩定化             ***********************/
/* 以下行僅適用於俯仰/滾動傾斜穩定系統。取消註釋第一行或第二行以啟用它 */
//#define SERVO_MIX_TILT
//#define SERVO_TILT

/* 攝影機觸發功能：通過GUI中的Rc選項激活，伺服輸出=A2 on promini */
// 觸發間隔可以通過(*GUI*)或通過AUX通道更改
//#define CAMTRIG
#define CAM_TIME_HIGH 1000   // 高電位伺服的持續時間，以毫秒表示

/***********************          飛機                       ***********************/
//#define USE_THROTTLESERVO // 用於油門的標準50Hz伺服。

//#define FLAPPERONS    AUX4          // 將襟翼與副翼混合。
#define FLAPPERON_EP   { 1500, 1700 } // 襟翼的端點位置在2位切換器上，否則設置為{1020,2000}並在收音機中進行編程。
#define FLAPPERON_INVERT { -1, 1 }    // 更改襟翼方向 { 翅膀1, 翅膀2 }

//#define FLAPS                       // 傳統襟翼在SERVO3上。
//#define FLAPSPEED     3             // 襟翼移動速度慢，數值越大速度越快。

/***********************      適用於直升機和飛機的共用設置     ***********************/

/* 調速器：嘗試通過螺距和電壓變化保持轉速
   預測性方法：觀察輸入信號和電壓並猜測適當的校正。
   （油門曲線必須留出空間給調速器，所以 0-50-75-80-80 是可以的，0-50-95-100-100 是 _不_ 可以的。
   可以通過輔助開關切換。
*/
//#define GOVERNOR_P 7     // (*) 比例因子。較高的值 -> 較高的油門增加。必須 >= 1；0 = 關閉
//#define GOVERNOR_D 4     // (*) 衰減時間。較高的值 -> 需要更長的時間恢復油門至正常。必須 >= 1;

/* 從集體螺距的尾部預補償 */
#define YAW_COLL_PRECOMP 10           // (*) 0.1 中的比例因子。較高的值 -> 較高的預補償效果。值為 10 等於無/中性效果
#define YAW_COLL_PRECOMP_DEADBAND 120 // (*) 繞集體螺距輸入信號的死區，約為 0-螺距輸入值

//#define VOLTAGEDROP_COMPENSATION // 電壓影響校正

/***********************          直升機                           ***********************/
/* 用於控制集體螺距的通道 */
#define COLLECTIVE_PITCH      THROTTLE

/* 限制集體螺距的範圍。100％是兩個方向的全範圍，並且位置為零螺距 */
#define COLLECTIVE_RANGE { 80, 0, 80 }// {最小%，零螺距偏移值從 1500，最大%}。
#define YAWMOTOR                 0       // 如果一個馬達用作偏航，設為 1，否則設為 0。

/* 用於直升機 120 的伺服混合
                     {螺距，俯仰，搖擺} */
#define SERVO_NICK   { +10, -10,  0 }
#define SERVO_LEFT   { +10, +5, +10 }
#define SERVO_RIGHT  { +10, +5, -10 }

/* 限制滾轉和俯仰的最大控制在 0-100% */
#define CONTROL_RANGE   { 100, 100 }      //  { 滾轉，俯仰 }

/* 使用伺服代碼來驅動油門輸出。對於模擬伺服驅動內燃機上的油門，您需要這個。
   如果不活躍，則油門輸出將被視為馬達輸出，因此它可以驅動電子速控。 */
//#define HELI_USE_SERVO_FOR_THROTTLE

/***********************      個人混合     ***********************/
/* 如果您想要覆蓋混合表中的現有條目，您可能希望避免不斷編輯 mixTable() 函數以適應每個版本。
   使用方法：http://www.multiwii.com/wiki/index.php?title=Config.h#Individual_Mixing
*/
//#define MY_PRIVATE_MIXING "filename.h"

/***********************      個人默認值     ***********************/
/* 如果您想要使用自己的硬編碼默認值替換它們（例如，從以前保存到 .mwi 文件的版本中）
   您可能希望避免不斷編輯 LoadDefaults() 函數以適應每個版本。
   http://www.multiwii.com/wiki/index.php?title=Config.h#Individual_defaults
*/
//#define MY_PRIVATE_DEFAULTS "filename.h"

/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  第 3 部分 - 遙控系統設置                                            *******/
/*****************                                                                 ***************/
/*************************************************************************************************/

/* 注意：如果您使用標準接收器，無需在此部分取消註釋任何內容 */

/****************************    擴展輔助狀態    ***********************************/
/* 如果取消註釋此行，您可以使用六個狀態來控制您的多旋翼的每個輔助通道（AUX1-AUX4）。
   通道值
   1000-1230
   1231-1360
   1361-1490
   1491-1620
   1621-1749
   1750-

   目前只能在 WinGUI 2.3 發布版中使用此功能。MultiWiiConf尚不支持它
*/

//#define EXTENDED_AUX_STATES


/**************************************************************************************/
/********                       特殊接收器類型             ********************/
/**************************************************************************************/

/****************************    PPM Sum 接收器    ***********************************/
/* 以下行僅適用於僅具有一個PPM總和信號的特定接收器，位於數字PIN 2上
   根據您的遙控器品牌，選擇正確的行。如果您的PPM順序不同，請隨意修改順序 */
//#define SERIAL_SUM_PPM         PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,AUX3,AUX4,8,9,10,11 //用於Graupner/Spektrum
//#define SERIAL_SUM_PPM         ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4,8,9,10,11 //用於Robe/Hitec/Futaba
//#define SERIAL_SUM_PPM         ROLL,PITCH,YAW,THROTTLE,AUX1,AUX2,AUX3,AUX4,8,9,10,11 //用於Multiplex
//#define SERIAL_SUM_PPM         PITCH,ROLL,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4,8,9,10,11 //用於某些Hitec/Sanwa/其他品牌
//#define SERIAL_SUM_PPM         THROTTLE,YAW,ROLL,PITCH,AUX1,AUX2,AUX3,AUX4,8,9,10,11 //用於Modelcraft

// 取消以下行的註釋，允許將PPM_SUM接收器連接到MEGA板上的標準THROTTLE引腳（例如，在CRIUS AIO中的A8引腳上）
//#define PPM_ON_THROTTLE

/**********************    Spektrum 衛星接收器    *******************************/
/* 以下行僅適用於Spektrum衛星接收器
   Spektrum衛星接收器是3V設備。不要連接到5V！
   對於MEGA板，將衛星接收器的灰色線連接到RX1，引腳19。衛星接收器的黑色線連接到地。衛星接收器的橙色線連接到Mega板的3.3V（或任何其他3V至3.3V源）。
   對於PROMINI，將衛星接收器的灰色線連接到RX0。將衛星接收器的黑色線連接到地。 */
//#define SPEKTRUM 1024
//#define SPEKTRUM 2048
//#define RX_SERIAL_PORT 1    // 在Pro Mini和單串口板上強制為0；在基於Mega的任何板上，設置為0、1或2（在Mega上默認為1）。
//**************************
// 定義允許使用配置GUI進行Spektrum或兼容遙控接收器（稱為衛星）的“綁定”。
//   如果您的遙控器具有綁定模式，則綁定模式將與上面宣告的一樣。
//   地、電源和信號必須來自三個相鄰的引腳。默認情況下，這些引腳在大多數MultiWii板上是相鄰的。引腳可以在下面覆蓋。
//   通常情況下，需要在電源引腳上使用3.3V調壓器！！如果您的衛星在綁定期間掛起（閃爍，但無法完成綁定且沒有穩定燈），則將所有引腳連接到5V。
//**************************
//   對於Pro Mini，位於FTDI上的衛星的連接器可以拔下並移動到這三個相鄰的引腳上。
//#define SPEK_BIND             //取消註釋以支持Spektrum衛星綁定。如果禁用它，代碼將縮小約420字節。
//#define SPEK_BIND_GROUND 4
//#define SPEK_BIND_POWER  5
//#define SPEK_BIND_DATA   6

/*******************************    SBUS 接收器    ************************************/
/* 以下行僅適用於MEGA板或PROMICRO板上的Futaba S-Bus接收器。
   您必須反轉S-Bus串行信號，例如使用像IC SN74 LS 04這樣的六極反相器 */
//#define SBUS     PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,AUX3,AUX4,8,9,10,11,12,13,14,15,16,17  // dsm2 orangerx
//#define SBUS     ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,AUX3,AUX4,8,9,10,11,12,13,14,15,16,17  // T14SG
//#define RX_SERIAL_PORT 1
#define SBUS_MID_OFFSET 988 //SBUS中點在1500

/******************************* HOTT 接收器 ************************************/
/* Graupner Hott HD */
//#define SUMD PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,AUX3,AUX4
//#define RX_SERIAL_PORT 1
/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  第 4 部分 - 替代CPU和板子設置                                  *******/
/*****************                                                                 ***************/
/*************************************************************************************************/

/**************************************************************************************/
/********                      Promini 專用設置                   ********************/
/**************************************************************************************/

/**************************    六個馬達的 5 和 6 腳    *******************************/
/* 使用A0和A1腳代替D5和D6腳進行六個馬達配置和Pro Mini配置
   這種修改允許在Pro Mini上使用標準接收器
   （無需使用PPM總和接收器） */
//#define A0_A1_PIN_HEX

/*********************************    輔助2腳     ***********************************/
/* 可以使用PIN8或PIN12作為AUX2 RC輸入（僅一個，不是兩個）
   在這種情況下，它將停用POWER PIN（引腳12）或BUZZER PIN（引腳8） */
//#define RCAUXPIN8
//#define RCAUXPIN12


/**************************************************************************************/
/*****************             Teensy 2.0 支持                   ******************/
/**************************************************************************************/
/* 如果您使用具有teensyduino的teensy 2.0，請取消註釋此選項
   它需要運行在16MHz */
//#define TEENSY20


/**************************************************************************************/
/********   ProMicro、Leonardo 和其他Atmega32u4板的設置     ***********/
/**************************************************************************************/

/*********************************    引腳布局     **********************************/
/* 如果可以使用所有引腳，則啟用此選項以獲得更好的引腳布局 => ProMicro上不可行 */
//#define A32U4ALLPINS

/**********************************    PWM 設置     **********************************/
/* 啟用所有6個硬件PWM輸出，Motor 5 = D11和6 = D13。
   注意：在Sparkfun ProMicro上不可能（引腳11和13未經過處理）
   如果啟用：
   Motor 1-6 = 10位硬件PWM
   Motor 7-8 = 8位軟件PWM
   Servos    = 8位軟件PWM
   如果停用：
   Motor 1-4 = 10位硬件PWM
   Motor 5-8 = 10位軟件PWM
   Servos    = 10位軟件PWM */
//#define HWPWM6

/**********************************    輔助2腳     **********************************/
/* AUX2引腳在RXO引腳上 */
//#define RCAUX2PINRXO

/* AUX2引腳在D17引腳（RXLED）上 */
//#define RCAUX2PIND17

/**********************************    蜂鳴器引腳    **********************************/
/* 這將將蜂鳴器引腳從TXO移至D8以與ppm總和或spectrum sat RX一起使用（如果A32U4ALLPINS處於活動狀態，則不需要） */
//#define D8BUZZER

/***********************      Promicro版本相關     ****************************/
/* ProMicro版本10的反向狀態LED */
//#define PROMICRO10


/**************************************************************************************/
/********                      覆蓋默認的引腳分配    ********************/
/**************************************************************************************/

/* 只有在必須更改默認引腳分配的情況下才啟用以下任何選項，例如，您的板子沒有特定的引腳 */
/* 您可能需要根據所需的引腳更改PINx和PORTx以及#shift！ */
//#define OVERRIDE_V_BATPIN                   A0 // 代替A3    // 模擬引腳3

//#define OVERRIDE_PSENSORPIN                 A1 // 代替A2    // 模擬引腳2

//#define OVERRIDE_LEDPIN_PINMODE             pinMode (A1, OUTPUT); // 使用A1代替d13
//#define OVERRIDE_LEDPIN_TOGGLE              PINC |= 1<<1; // PINB |= 1<<5;     //切換LEDPIN狀態（數字引腳13）
//#define OVERRIDE_LEDPIN_OFF                 PORTC &= ~(1<<1); // PORTB &= ~(1<<5);
//#define OVERRIDE_LEDPIN_ON                  PORTC |= 1<<1;    // 以前是PORTB |= (1<<5);

//#define OVERRIDE_BUZZERPIN_PINMODE          pinMode (A2, OUTPUT); // 使用A2代替d8
//#define OVERRIDE_BUZZERPIN_ON               PORTC |= 1<<2 //PORTB |= 1;
//#define OVERRIDE_BUZZERPIN_OFF              PORTC &= ~(1<<2); //PORTB &= ~1;
/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  第 5 部分 - 替代設置                                               *******/
/*****************                                                                 ***************/
/*************************************************************************************************/

/******                串行通訊速度    *********************************/
/* 這是串行接口的速度 */
#define SERIAL0_COM_SPEED 115200
#define SERIAL1_COM_SPEED 115200
#define SERIAL2_COM_SPEED 115200
#define SERIAL3_COM_SPEED 115200

/* 當I2C匯流排出現錯誤時，我們會在短時間內中和值。以微秒為單位表示
   這僅對至少具有WMP的設置才有意義 */
#define NEUTRALIZE_DELAY 100000

/**************************************************************************************/
/********                              陀螺儀濾波器                ********************/
/**************************************************************************************/

/*********************    一些陀螺儀的低通濾波器    ****************************/
/* ITG3200和ITG3205低通濾波器設置。如果您無法消除陀螺儀的所有振動，可以嘗試降低LPF頻率，每次只能嘗試一次。一旦抖動消失，就保持該設置。
   這對於反饋擺動不起作用，因此僅在機架隨機抖動且所有減震和平衡選項用完時才更改。僅取消註釋一個選項！
   重要！更改低通濾波器設置會更改PID行為，因此在更改LPF後，重新調整PID。可用於ITG3050、ITG3200、MPU3050、MPU6050*/
//#define GYRO_LPF_256HZ     // 這是默認設置，無需取消註釋，僅供參考
//#define GYRO_LPF_188HZ
//#define GYRO_LPF_98HZ
//#define GYRO_LPF_42HZ
//#define GYRO_LPF_20HZ
//#define GYRO_LPF_10HZ
//#define GYRO_LPF_5HZ       // 僅在極端情況下使用，最好更換馬達和/或螺旋槳 -- 在ITG3200上不可用

/******                陀螺儀平滑    **********************************/
/* GYRO_SMOOTHING。如果您無法減少振動_且_在嘗試了低通濾波器選項之後，您可以嘗試通過平均來平滑這個陀螺儀。不適用於多旋翼！
   適用於直升機、飛機和具有大量振動的飛行翼（泡沫機）的良好效果。*/
//#define GYRO_SMOOTHING {20, 20, 3}    // (*) 獨立的平均範圍，分別用於橫滾、俯仰、偏航

/************************    移動平均陀螺儀    **********************************/
//#define MMGYRO 10                      // (*) 陀螺儀的活動移動平均函數
//#define MMGYROVECTORLENGTH 15          // 移動平均向量的長度（可調的MMGYRO的最大值
/* 移動平均伺服陀螺儀信號輸出 */
//#define MMSERVOGIMBAL                  // 伺服陀螺儀的主動輸出移動平均功能
//#define MMSERVOGIMBALVECTORLENGHT 32   // 移動平均向量的長度

/************************    模擬讀取              **********************************/
/* 如果您想要更快的模擬讀取，請啟用此選項。這可能會導致不太準確的結果，特別是對於多個模擬通道而言 */
//#define FASTER_ANALOG_READS

/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  第 6 部分 - 可選功能                                            *******/
/*****************                                                                 ***************/
/*************************************************************************************************/

/************************        在解鎖時重置氣壓高度         ********************/
/* 當未選中時，每次啟動時都會執行氣壓高度的校準 */
//#define ALTITUDE_RESET_ON_ARM

/************************        角度油門校正         ********************/
/* 根據機身角度自動增加油門
   最初的想法來自Kraut Rob，首次實現是由HAdrian完成的 */
//#define THROTTLE_ANGLE_CORRECTION 40

/*** HEADFREE : 這允許直升機由絕對搖桿方向控制，無論偏航方向如何 ***/
//#define HEADFREE

/*************************        高級Headfree模式             ********************/
/* 在高級Headfree模式下，當直升機距離ADV_HEADFREE_RANGE米時，
   家和直升機位置之間的方向將成為控制方向
   IF直升機距離ADV_HEADFREE_RANGE米以下，則控制方向被凍結到
   家和直升機交叉ADV_HEADFREE_RANGE米距離時的方向
   首次實施由HAdrian完成，由EOSBandi修改
*/

//#define ADVANCED_HEADFREE      //啟用高級headfree模式時取消注釋
//#define ADV_HEADFREE_RANGE 15  //激活高級headfree模式的範圍


/************************        連續陀螺儀校準        ********************/
/* 如果在校準過程中飛行器移動，則陀螺儀校準將被重複執行。 */
//#define GYROCALIBRATIONFAILSAFE

/************************        AP飛行模式        **********************************/
/*** 功能性暫時移除 ***/
/* 暫時禁用GPS_HOLD_MODE，以便在移動搖桿時調整Hold位置。*/
//#define AP_MODE 40  // 為GPS創建一個deadspan。

/************************   輔助AcroTrainer    ************************************/
/* 使用自動恢復訓練Acro。值設定了ANGLE_MODE接管的點。
   請記住首先啟用ANGLE_MODE！...
   值為200將提供非常明顯的轉移 */
//#define ACROTRAINER_MODE 200   // http://www.multiwii.com/forum/viewtopic.php?f=16&t=1944#p17437


/********                          失控保護設置                 ********************/
/* 失控檢查CH1-CH4上的四個主要控制通道的脈衝。如果缺少或低於985us（在這四個通道中的任何一個），
   則將啟動失控程序。在失控檢測後的FAILSAFE_DELAY時間後，啟用水平模式（如果ACC可用），
   將PITCH，ROLL和YAW居中，並將THROTTLE設置為FAILSAFE_THROTTLE值。您必須將此值設置為下降約1m/s左右，
   以獲得最佳效果。此值依賴於您的配置，AUW和一些其他參數。接下來，在FAILSAFE_OFF_DELAY之後，直升機解除武裝，
   馬達停止。如果RC脈衝在達到FAILSAFE_OFF_DELAY時間之前回來，經過短暫的延遲時間，RC控制將恢復正常。 */
//#define FAILSAFE                                // 取消注釋以激活失控保護功能
#define FAILSAFE_DELAY     10                     // 在信號丟失後激活失控的保護時間。1步=0.1秒 - 例如1秒
#define FAILSAFE_OFF_DELAY 200                    // 在0.1秒內停止驅動馬達之前的著陸時間。1步=0.1秒 - 例如20秒
#define FAILSAFE_THROTTLE  (MINTHROTTLE + 200)    // (*) 用於著陸的油門級別 - 可能與MINTHROTTLE相關 - 在這種情況下

#define FAILSAFE_DETECT_TRESHOLD  985


/*****************                DFRobot LED環    *********************************/
/* I2C DFRobot LED環通信 */
//#define LED_RING

/********************************    LED閃爍器    ***********************************/
//#define LED_FLASHER
//#define LED_FLASHER_DDR DDRB
//#define LED_FLASHER_PORT PORTB
//#define LED_FLASHER_BIT PORTB4
//#define LED_FLASHER_INVERT
//#define LED_FLASHER_SEQUENCE        0b00000000      // 關閉LED燈
//#define LED_FLASHER_SEQUENCE_ARMED  0b00000101      // 創建雙閃爍
//#define LED_FLASHER_SEQUENCE_MAX    0b11111111      // 全亮
//#define LED_FLASHER_SEQUENCE_LOW    0b00000000      // 關閉

/*******************************    OSD開關    *************************************/
// 這將添加一個可以由OSD解讀的框，用於啟用/禁用覆蓋層（例如切換覆蓋層開關）
//#define OSD_SWITCH

/**************************************************************************************/
/***********************                  有關TX的         **************************/
/**************************************************************************************/

/* 在搖桿中心周圍引入一個死區
   必須大於零，如果不想在搖桿的滾動、俯仰和偏航上引入死區，則注釋掉 */
//#define DEADBAND 6

/**************************************************************************************/
/***********************                  GPS                **************************/
/**************************************************************************************/

/* 啟用此選項以使用GPS模擬器（僅NMEA）*/
//#define GPS_SIMULATOR

/* 使用串口連接的GPS
   如果啟用，請在此處定義Arduino串口端口號和UART速度
   注意：僅在NMEA模式下使用RX引腳，不使用multiwii配置GPS
   在NMEA模式下，GPS必須配置為輸出GGA和RMC NMEA句子（這通常是大多數GPS設備的默認配置）
   至少5Hz的更新速率。取消注釋第一行以選擇Arduino上的GPS串口端口號 */

//#define GPS_SERIAL 2         // 應為2以供flyduino v2使用。這是arduino MEGA上的串口端口號
// PRO_MINI（例如GPS_PRO_MINI）必須為0
// 注意：現在GPS可以在同一端口上共享MSP。唯一的約束是不要同時使用它，並使用相同的端口速度。

// 避免使用115200波特率，因為使用16MHz的arduino時，115200波特率速度錯誤超過2％（57600的速度錯誤為0.8％）
#define GPS_BAUD   57600       // GPS_BAUD將覆蓋所選端口的SERIALx_COM_SPEED

/* GPS協議
    NMEA  - 標準NMEA協議需要GGA、GSA和RMC句子
    UBLOX - U-Blox二進制協議，使用源代碼樹中的ublox配置文件（u-blox-config.ublox.txt）
    MTK_BINARY16和MTK_BINARY19 - 基於MTK3329芯片的GPS，使用DIYDrones二進制固件（v1.6或v1.9）
    使用UBLOX和MTK_BINARY，您無需在multiwii代碼中使用GPS_FILTERING！！！ */


//#define NMEA
//#define UBLOX
//#define MTK_BINARY16
//#define MTK_BINARY19
//#define INIT_MTK_GPS        // 初始化MTK GPS以使用所選速度、5Hz更新率和GGA＆RMC句子或二進制設置
//#define VENUS8

/* 由獨立的arduino + GPS設備製成的I2C GPS設備
   包括一些導航功能
   貢獻來自EOSBandi   http://code.google.com/p/i2c-gps-nav/
   現在所有由SERIAL_GPS允許的功能都可用於I2C_GPS：所有相關的導航計算都集中在主FC中 */

//#define I2C_GPS

// 如果您的I2C GPS板支持聲納，請啟用
//#define I2C_GPS_SONAR

/* 使用閃爍的LED指示GPS修復的有效性 - 由MIS修改 - 使用穩定的LED（CRIUS AIO上的黃色）作為衛星數指示器
  - 沒有GPS FIX -> LED以接收到的GPS幀速度閃爍
  - 修復和衛星號小於5 -> LED熄滅
  - 修復和衛星號大於或等於5 -> LED閃爍，每5個衛星一閃爍，6個衛星兩閃爍，7個衛星三閃爍... */
#define GPS_LED_INDICATOR

// 啟用MSP_WP命令集，用於WinGUI顯示和設置導航
//#define USE_MSP_WP

// 家的位置在每次啟動時被重置，取消注釋它以禁止它（您可以使用GyroCalibration設置家的位置）
//#define DONT_RESET_HOME_AT_ARM

/* GPS導航可以控制方向 */

// 直升機面對著導航點，必須啟用maghold
#define NAV_CONTROLS_HEADING       1    //(**)
// true - 直升機首次尾部
#define NAV_TAIL_FIRST             0    //(**)
// true - 當直升機到達家時，它將旋轉以起飛方向
#define NAV_SET_TAKEOFF_HEADING    1    //(**)

/* 從這裡獲取磁場偏角：http://magnetic-declination.com/
  通過 ==> degree+minutes*(1/60)將度+分轉換為十進制度
  注意偏向角的符號可能是負的或正的（WEST或EAST）
  還要注意，磁場偏角會隨時間變化，因此每3-6個月重新檢查您的值 */
#define MAG_DECLINATION  4.02f   //(**)

// 添加前向預測過濾以補償GPS滯後。代碼基於Jason Short的領先濾波器實現
#define GPS_LEAD_FILTER               //(**)

// 添加5個元素的移動平均過濾器以消除GPS噪聲，但增加延遲以禁用請注釋掉
//僅與NMEA gps一起使用
//#define GPS_FILTERING                 //(**)

// 如果我們在一個路點附近，我們認為它已經到達（距離以厘米為單位）
#define GPS_WP_RADIUS              100      //(**)

// 安全WP距離，如果第一個WP距離大於這個數字（以米為單位），則不啟動任務
//如果下一個路點距離大於這個數字，也會中止任務
#define SAFE_WP_DISTANCE           500      //(**)

//導航高度的最大允許值（以米為單位），自動高度控制不會超過這個高度
#define MAX_NAV_ALTITUDE           100     //(**)

//接近路點時的最小速度
#define NAV_SPEED_MIN              100    // cm/sec //(**)
//達到路點之間的最大速度
#define NAV_SPEED_MAX              400    // cm/sec //(**)
//達到路點時減速至零（等同於NAV_SPEED_MIN = 0）
#define NAV_SLOW_NAV               0      //(**)
//導航計算中橫向偏差的權重因子（不要觸摸）
#define CROSSTRACK_GAIN            .4     //(**)
//導航輸出的最大允許俯仰角
#define NAV_BANK_MAX 3000                 //(**)

//定義RTH高度。 0表示在RTH期間保持當前高度（以米為單位）
#define RTH_ALTITUDE               15        //(**)
//在開始返回家之前等待達到RTH高度（0-否，1-是）
#define WAIT_FOR_RTH_ALT           1         //(**)

//導航引擎將接管BARO模式控制
#define NAV_TAKEOVER_BARO          1         //(**)

//將忽略油門搖桿輸入（僅在BARO中）
#define IGNORE_THROTTLE            1         //(**)

//如果FENCE DISTANCE大於0，則當距離家大於定義的米數時，無人機將切換到RTH
#define FENCE_DISTANCE      600

//這決定了著陸時的下降速度。 100等於約50cm /秒
#define LAND_SPEED          100


//#define ONLY_ALLOW_ARM_WITH_GPS_3DFIX      // 只允許在GPS具有3D修復時FC上電。


/**************************************************************************************/
/***********************        LCD/OLED - 顯示器設置       *********************/
/**************************************************************************************/

/* http://www.multiwii.com/wiki/index.php?title=Extra_features#LCD_.2F_OLED */

/*****************************   顯示器的類型     **********************************/
/* 配置和遙測所附的LCD的選擇，參見下面的註釋 */
//#define LCD_DUMMY       // 沒有實際附加的LCD。即使有LCD_CONF，TX搖桿仍然可以通過觀察LED閃爍來設置增益。
//#define LCD_SERIAL3W    // Alex的初始變體，帶有3條線，使用rx引腳進行固定速率為9600波特的傳輸
//#define LCD_TEXTSTAR    // 串行LCD：Cat's Whisker LCD_TEXTSTAR Module CW-LCD-02（具有4個輸入鍵，用於選擇菜單）
//#define LCD_VT100       // 串行LCD：vt100兼容終端仿真（blueterm、putty等）
//#define LCD_TTY         // 串行LCD：使用arduino IDE '串行監視器'電纜調整參數時有用
//#define LCD_ETPP        // I2C LCD：Eagle Tree Power Panel LCD，它是i2c（不是串行）
//#define LCD_LCD03       // I2C LCD：LCD03，它是i2c
//#define LCD_LCD03S      // 串行LCD：具有串行9600波特通信的LCD03。
//#define OLED_I2C_128x64 // I2C LCD：OLED http://www.multiwii.com/forum/viewtopic.php?f=7&t=1350
//#define OLED_DIGOLE     // I2C OLED from http://www.digole.com/index.php?productID=550

/******************************   顯示設置   ***********************************/
#define LCD_SERIAL_PORT 0    // 在Pro Mini和單個串行板上必須為0；在任何基於Mega的板上可以設置為您的選擇

//#define SUPPRESS_OLED_I2C_128x64LOGO  // 抑制OLED徽標的顯示以節省內存

/* 雙字體高度，以提高可讀性。將可見#行減少一半。
   每頁的下半部分可以在移位鍵盤字母的名稱下訪問：
   1 -！，2 - @，3 - #，4 - $，5 -％，6 - ^，7 -＆，8 - *，9 -（
   您必須在您的lcd.telemetry.*序列中都添加這兩個。 */
//#define DISPLAY_FONT_DSIZE //目前僅適用於OLED_I2C_128x64和OLED_DIGOLE

/* 顯示風格 - 通過LCD_設置自動檢測 - 只有在需要時才激活以覆蓋默認值 */
//#define DISPLAY_2LINES
//#define DISPLAY_MULTILINE
//#define MULTILINE_PRE 2  // 多行configMenu＃pref行
//#define MULTILINE_POST 6 // 多行configMenu＃post行
//#define DISPLAY_COLUMNS 16
/********************************    導航     ***********************************/
/* 用於導航LCD菜單的鍵 */
#define LCD_MENU_PREV 'p'
#define LCD_MENU_NEXT 'n'
#define LCD_VALUE_UP 'u'
#define LCD_VALUE_DOWN 'd'

#define LCD_MENU_SAVE_EXIT 's'
#define LCD_MENU_ABORT 'x'

/**************************************************************************************/
/***********************      LCD配置菜單         **************************/
/**************************************************************************************/

/* 如果您計劃使用LCD或OLED來調整參數，取消注釋此行
   http://www.multiwii.com/wiki/index.php?title=Extra_features#Configuration_Menu */
//#define LCD_CONF

/* 包括通過LCD設置AUX1 -> AUX4的輔助開關的選項 */
//#define LCD_CONF_AUX

/* 可選排除一些功能 - 取消注釋以抑制不需要的輔助通道配置選項 */
//#define SUPPRESS_LCD_CONF_AUX2
//#define SUPPRESS_LCD_CONF_AUX34

/**************************************************************************************/
/***********************      LCD       遙測            **************************/
/**************************************************************************************/

/* 監控系統值（電池電平、循環時間等）的選項，以LCD
   http://www.multiwii.com/wiki/index.php?title=LCD_Telemetry */

/********************************    激活     ***********************************/
//#define LCD_TELEMETRY

/* 啟用自動在選擇的遙測頁之間自動跳換，取消注釋此行。 */
//#define LCD_TELEMETRY_AUTO "123452679" // 頁1到9按升序排列
//#define LCD_TELEMETRY_AUTO  "212232425262729" // 頁2強調

/* 手動步進序列；首頁序列的第一頁在啟動時加載，以允許非交互式顯示 */
//#define LCD_TELEMETRY_STEP "0123456789" // 應包含0以允許關閉。

/* 可選排除一些功能 - 取消注釋以抑制一些不需要的遙測頁 */
//#define SUPPRESS_TELEMETRY_PAGE_1
//#define SUPPRESS_TELEMETRY_PAGE_2 // 傳感器讀數
//#define SUPPRESS_TELEMETRY_PAGE_3 // 复选框項目
//#define SUPPRESS_TELEMETRY_PAGE_4 // rx输入
//#define SUPPRESS_TELEMETRY_PAGE_5 // 伺服馬達輸出
//#define SUPPRESS_TELEMETRY_PAGE_6 // 電池電壓
//#define SUPPRESS_TELEMETRY_PAGE_7 // gps
//#define SUPPRESS_TELEMETRY_PAGE_8 // 告警狀態
//#define SUPPRESS_TELEMETRY_PAGE_9 // 循環和失敗
//#define SUPPRESS_TELEMETRY_PAGE_R // 重置

/* 可選覆蓋某些遙測頁的默認項目 - 有關可用功能的完整列表，請參見LCD.h */
//#define LCD_TELEMETRY_PAGE1 { output_V, output_mAh, }
//#define LCD_TELEMETRY_PAGE2 { output_gyroX, output_gyroY, output_accZ, }
//#define LCD_TELEMETRY_PAGE9 { output_fails, output_annex, output_debug0, output_debug3, }
/********************************************************************/
/****                             RSSI                           ****/
/********************************************************************/
//#define RX_RSSI
//#define RX_RSSI_PIN A3
//#define RX_RSSI_CHAN 8   //選擇的通道上的RSSI注入（用於PPM、Olrs、SBUS等）（從0開始）

/********************************************************************/
/****                             TELEMETRY                      ****/
/********************************************************************/
// 根據您的接收器選擇其中一個協議
//#define FRSKY_TELEMETRY           //用於帶有遙測的FRSKY雙向接收器（D系列，如D8R-II或D8R-XP）
// VBAT、Baro、MAG、GPS和POWERMETER對於幫助有用
// 如果可用，VBAT_CELLS對於FLD-02上的第四個屏幕是可選的
//#define SPORT_TELEMETRY           //用於帶有S.PORT遙測的FRSKY雙向接收器（S系列，如X4R/X6R/X8R），尚未實現 - 需要完成

// FRSKY通用條目 - 對兩個協議都有效
#define TELEMETRY_SERIAL 3        // 如果需要，請更改

// FRSKY標準遙測特定設備
#define FRSKY_FLD02               //僅發送特定於FRSKY顯示FLD-02的數據
//#define OPENTX                    //發送OpenTX特定數據

// FRSKY標準遙測特定選項
//#define COORDFORMAT_DECIMALMINUTES //取消注釋以獲取坐標的格式DD°MM.mmmm - 注釋以獲取坐標的格式DD.dddddd°
//#define KILOMETER_HOUR            //將速度發送為每小時的公里數，而不是節（默認值） - OPENTX要求
#define TELEMETRY_ALT_BARO        //發送BARO基準的高度，在武裝時校準為0，如果可用，建議使用
//#define TELEMETRY_ALT_GPS         //發送基於GPS的高度（海平面上的高度），對於FLD-02不要與TELEMETRY_ALT_BARO一起使用
#define TELEMETRY_COURSE_MAG      //發送MAG基準的航向，如果可用，建議使用，但FLD-02不顯示
//#define TELEMETRY_COURSE_GPS      //發送基於GPS的航向，不要與TELEMETRY_COURSE_MAG一起使用，FLD-02不顯示

// S.PORT特定條目
#define FRSKY_SPORT_A2_MAX 124    // A2電壓由範圍0-255表示。值16表示1.6V，124表示12.4V，依此類推

/********************************************************************/
/****                             Buzzer                         ****/
/********************************************************************/
//#define BUZZER
//#define RCOPTIONSBEEP         //取消注釋此行，如果要在通道Aux1到Aux4上的任何rcOptions更改時發出蜂鳴器聲音
//#define ARMEDTIMEWARNING 330  // (*) 在被武裝一段時間后觸發警報 [s] 以節省鋰電池（如果您的TX不具有倒計時）
//#define PILOTLAMP             //如果使用X-Arcraft Pilot Lamp，請取消注釋

/********************************************************************/
/****           電池電壓監測                       ****/
/********************************************************************/
/* 用於V BAT監測
   在電阻分壓器之後，我們應該獲得[0V;5V]->[0;1023]的模擬V_BATPIN
   使用R1=33k和R2=51k
   vbat = [0;1023]*16/VBATSCALE
   必須與#define BUZZER一起使用！ */
//#define VBAT              //取消注釋此行以激活vbat代碼
#define VBATSCALE       131 // (*) (**) 如果讀取的電池電壓不同於實際電壓，請更改此值
#define VBATNOMINAL     126 // 12.6V全電池標稱電壓 - 仅用于lcd.telemetry
#define VBATLEVEL_WARN1 107 // (*) (**) 10.7V
#define VBATLEVEL_WARN2  99 // (*) (**) 9.9V
#define VBATLEVEL_CRIT   93 // (*) (**) 9.3V - 至關重要的情況：如果vbat曾經低於此值，則會觸發永久警報
#define NO_VBAT          16 //避免在沒有任何電池的情況下發出蜂鳴器聲音
#define VBAT_OFFSET       0 //在0.1伏特中的偏移量，添加到電壓值 - 對于齊納二極管很有用

/* 用於個別細胞的V BAT監測
   同時啟用VBAT和VBAT_CELLS
*/
//#define VBAT_CELLS
#define VBAT_CELLS_NUM 0 //將其設置為您通過模擬引腳監測的細胞數
#define VBAT_CELLS_PINS {A0, A1, A2, A3, A4, A5 } //將其設置為模擬引腳的順序
#define VBAT_CELLS_OFFSETS {0, 50, 83, 121, 149, 177 } //以0.1伏特為單位，在電壓值上添加 - 對於齊納二極管很有用
#define VBAT_CELLS_DIVS { 75, 122,  98, 18, 30, 37 } //按比例部分的除數，根據電阻綫 - 較大的值會使電壓較小
/********************************************************************/
/****           powermeter (battery capacity monitoring)         ****/
/********************************************************************/

/* 啟用電池功耗監測（以mAh為單位），
   允許在GUI或通過LCD設置警報值
  完整的說明和操作方式在這裡 http://www.multiwii.com/wiki/index.php?title=Powermeter
   兩種選擇：
   1 - hard: -（使用硬件傳感器，在配置之後可以得到非常好的結果）
   2 - soft: -（對於2S和3S的plush和mystery ESCs，對於超簡單的ESC不好，結果約+-5%） */
//#define POWERMETER_SOFT
//#define POWERMETER_HARD
#define PSENSORNULL 510 /* (*) hard only: 設置為模擬讀取值以獲取零電流的電壓; 對於I=0A我的傳感器
                                   提供1/2 Vss; 這約為2.49伏特; */
#define PINT2mA 132     /* (*) hard: arduino模擬中的一個整數步驟轉化為mA（例如4.9 / 37 * 1000）;
                                   soft: 使用虛構值，從100開始。
                                   對於hard和soft: 較大的PINT2mA將獲得較大的功率值（mAh等效） */
//#define WATTS // 計算並顯示實際耗電功率（=Volt*Ampere） - 需要POWERMETER_HARD和VBAT兩者

/********************************************************************/
/****           altitude hold                                    ****/
/********************************************************************/

/* 定義高度保持期間油門檔位的中性區域，默認設置為
   +/-50，取消注釋並更改下面的值，如果您想要更改它。 */
#define ALT_HOLD_THROTTLE_NEUTRAL_ZONE    50
//#define ALT_HOLD_THROTTLE_MIDPOINT        1500  // in us    - 如果取消注釋，則此值將用於ALT_HOLD的油門檔位中點，而不是initialThrottleHold參數。

/* 取消注釋以禁用高度保持功能。
   如果以下所有情況均適用，則此選項很有用
   + 您有一個baro
   + 想要高度讀數和/或變速器
   + 不使用高度保持功能
   + 想要節省內存空間 */
//#define SUPPRESS_BARO_ALTHOLD

/********************************************************************/
/****           altitude variometer                              ****/
/********************************************************************/

/* 啟用升降機升降器，用於升降機/飛機。
   需要有效的baro。
   目前，輸出將發送到啟用的vt100終端程序，通過串行線進行連接。
   兩種方法的選擇（啟用其中一個或兩個）
   方法1：使用baro的短期運動（較大的代碼大小）
   方法2：使用baro的高度的長期觀察（較小的代碼大小）
*/
//#define VARIOMETER 12            // 可能的值：12 = 方法1和2；1 = 方法1；2 = 方法2
//#define SUPPRESS_VARIOMETER_UP   // 如果不希望上升運動的信號
//#define SUPPRESS_VARIOMETER_DOWN // 如果不希望下降運動的信號
//#define VARIOMETER_SINGLE_TONE   //僅使用一個音調（BEL）；對於非修補的vt100終端必需

/********************************************************************/
/****           board naming                                     ****/
/********************************************************************/

/*
   此名稱與MultiWii版本號一起顯示在LCD上電源開啟時。
   如果您没有DISPLAYD，那麼您可以啟用LCD_TTY並使用arduino IDE的串行監視器來查看信息。

   您必須保留此字符串的格式！
   它必須總共16個字符，
   最後4個字符將被版本號覆蓋。
*/
#define BOARD_NAME "MultiWii   V-.--"
//                  123456789.123456

/*************      在檢測到刷寫程序的更改時不要重置常量     ************/
#define NO_FLASH_CHECK

/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  SECTION  7 - 調整和開發人員選項                                   **************/
/*****************                                                                 ***************/
/*************************************************************************************************/

#define VBAT_PRESCALER 16 // 如果vbatscale超過255，將其設置為8

/**************************************************************************************/
/********   特殊的帶擴展範圍[0-2000]微秒的ESC   ********************/
/**************************************************************************************/
//#define EXT_MOTOR_RANGE // 與wii-esc一起使用需要將MINCOMMAND更改為1008，適用於promini和mega

/**************************************************************************************/
/********  刷過的ESC ****************************************************************/
/**************************************************************************************/
// 對於328p處理器
//#define EXT_MOTOR_32KHZ
//#define EXT_MOTOR_4KHZ
//#define EXT_MOTOR_1KHZ

// 對於32u4處理器
//#define EXT_MOTOR_64KHZ
//#define EXT_MOTOR_32KHZ
//#define EXT_MOTOR_16KHZ
//#define EXT_MOTOR_8KHZ

/**************************************************************************************/
/***********************     電機、伺服器和其他預設值     ***********************/
/**************************************************************************************/
/* 在油門指令處於低位置時，電機將不會轉動
   這是立即停止電機的替代方法 */
//#define MOTOR_STOP

/* 一些無線電的中性點未居中在1500上。可以在這裡更改 */
#define MIDRC 1500

/***********************         伺服器刷新率            ***********************/
/* 默認50Hz伺服器刷新率*/
#define SERVO_RFR_50HZ

/* 高達160Hz伺服器刷新率..適用於大多數模擬伺服器 */
//#define SERVO_RFR_160HZ

/* 高達300Hz更新率，盡快（視乎使用的伺服器數量和伺服器狀態而定，通常在100-300Hz之間）。
   用於數字伺服器
   不要與模擬伺服器一起使用！他們可能會損壞。（有些會工作，但要小心） */
//#define SERVO_RFR_300HZ

/***********************             HW PWM伺服器             ***********************/
/* Arduino Mega的HW PWM伺服器輸出..移動：
  Pitch   = 引腳44
  Roll    = 引腳45
  CamTrig = 引腳46
  SERVO4  = 引腳11（固定翼機的副翼左翼或TRI YAW伺服器）
  SERVO5  = 引腳12（固定翼機的副翼右翼）
  SERVO6  = 引腳6（固定翼機的方向舵）
  SERVO7  = 引腳7（固定翼機的升降舵）
  SERVO8  = 引腳8（固定翼機的馬達）  */

#define MEGA_HW_PWM_SERVOS

/* 32u4 NanoWii、MicroWii等的HW PWM伺服器輸出 - 可以使用SERVO_RFR_RATE變數或
   3個固定的伺服器刷新率之一
   只為heli_120（即1個馬達+4個伺服器）測試過，移動..
   motor[0] = motor       = 引腳6
   servo[3] = nick  servo = 引腳11
   servo[4] = left  servo = 引腳10
   servo[5] = yaw   servo = 引腳5
   servo[6]  = right servo= 引腳9
*/
//#define A32U4_4_HW_PWM_SERVOS

#define SERVO_RFR_RATE  50    // 以Hz為單位，可以設置為20到400Hz，僅在mega和32u4的HW PWM模式下使用
//#define SERVO_PIN5_RFR_RATE  200    // 獨立的偏航PWM率。
// 以Hz為單位，可以設置為20到400Hz，僅在32u4的HW PWM模式下使用

/********************************************************************/
/****           內存節省                                      ****/
/********************************************************************/

/* 用於對抗閃存和RAM內存的總缺乏，例如leonardo m32u4和其他 */

/**** 禁用串行命令的處理。***
   這不會影響RXserial、Spektrum或GPS的處理。這些不受影響，仍然可以正常工作。
   启用以下一个或两个选项之一 */

/* 刪除新的MultiWii串行協議的所有命令的處理。
   這將禁用GUI、winGUI、android應用程序和使用MSP的任何其他程序。
   您必须找到另一種方式（例如LCD_CONF）來調整參數或保持默認值。
   如果您運行具有i2c或串行/藍牙的LCD/OLED，則可以安全使用 */
//#define SUPPRESS_ALL_SERIAL_MSP // 節省約2700字節

/* 刪除其他串行命令的處理。
   這包括通過串行的lcd.configuration菜單、lcd.telemetry和permanent.log。
   通過遙杆輸入在TX上的導航不受影響，仍然可以正常工作。 */
//#define SUPPRESS_OTHER_SERIAL_COMMANDS // 節省約0到100字節，取決於啟用的功能

/**** 禁用在代碼中保留初始設置和重置的選項。
   這需要手動初始設置PID等，或者從defaults.mwi加載和寫入；
   GUI中的重置對PID無效 */
//#define SUPPRESS_DEFAULTS_FROM_GUI

//#define DISABLE_SETTINGS_TAB  // 在ProMini上節省約400字節

/********************************************************************/
/****           診斷                                      ****/
/********************************************************************/

/* 記錄值，如最大循環時間等，以便記錄到來
   通過LCD配置可見的日志值
   設置為1，啟用“R”選項以重置值、最大電流、最大高度
   設置為2，添加最小/最大周期時間
   設置為3，添加每個電機的額外功耗（這使用大陣列，佔用內存，如果POWERMETER <> PM_SOFT） */
//#define LOG_VALUES 1

/* 對eeprom進行永久記錄-在控制器板的生命周期內幾次升級和參數重置。
   用於跟蹤控制器板的生命週期內的飛行次數等。
   寫入eeprom的末尾-不應與存儲的參數衝突。
   记录的值：累计寿命、#电源循环/重置/初始化事件、#启动事件、#解除武装事件、最后的armedTime、
                 #武装解除时的失控、#解除武装时的i2c错误
   启用一个或多个选项以顯示日志
*/
//#define LOG_PERMANENT
//#define LOG_PERMANENT_SHOW_AT_STARTUP // 启用以在启动时显示日志
//#define LOG_PERMANENT_SHOW_AT_L // 启用以在接收到'L'时显示日志
//#define LOG_PERMANENT_SHOW_AFTER_CONFIG // 启用以在退出LCD配置菜单后显示日志
//#define LOG_PERMANENT_SERVICE_LIFETIME 36000 // 以秒为单位；在武装时间达到10小时后，在启动时触发服务警报

/* 添加調試代碼
   不需要且不建議正常運作
   將添加額外的代碼，可能會減慢主循環或使直升機無法飛行 */
//#define DEBUG
//#define DEBUG_FREE // 添加'F'命令以顯示可用內存

/* 使用這個觸發LCD配置，而不使用TX - 僅供調試使用 - 不要啟用此選項飛行 */
//#define LCD_CONF_DEBUG

/* 使用這個觸發遙測，而不使用TX - 僅供調試使用 - 不要啟用此選項飛行 */
//#define LCD_TELEMETRY_DEBUG    //這種形式在所有屏幕之間循環，LCD_TELEMETRY_AUTO也必須定義。
//#define LCD_TELEMETRY_DEBUG 6  //這種形式停留在指定的屏幕上。

/* 启用從直升機到GUI的字符串傳輸 */
//#define DEBUGMSG
/********************************************************************/
/****           ESC校準                                 ****/
/********************************************************************/

/* 同時校準連接到MWii的所有電子速控器（用於避免不斷拔插每個ESC）
   警告：這將創建一個特殊版本的MultiWii代碼
   您不能使用此特殊版本飛行。它僅用於校準ESC。
   閱讀如何操作：http://code.google.com/p/multiwii/wiki/ESCsCalibration */
#define ESC_CALIB_LOW  MINCOMMAND
#define ESC_CALIB_HIGH 2000
//#define ESC_CALIB_CANNOT_FLY  // 取消注释以激活

/****           內部頻率                             ****/
/* 主循環中罕見的周期性操作的頻率，取決於周期時間
   時間基準是主循環周期時間 - 值為6表示每個主循環的第6次運行觸發該操作
   例如：以約3毫秒的循環時間為例，每6*3毫秒=18毫秒執行操作
   值必須在[1; 65535]之間 */
#define LCD_TELEMETRY_FREQ 23       // 以串行方式發送遙測數據 23 <=> 60毫秒 <=> 16Hz（僅交替發送，因此更新率為8Hz）
#define LCD_TELEMETRY_AUTO_FREQ  967// 切換到下一個遙測頁面 967 <=> 3秒
#define PSENSOR_SMOOTH 16           // 平滑PSENSOR讀數的平均向量長度；應為2的冪；設為1以禁用
#define VBAT_SMOOTH 16              // 平滑VBAT讀數的平均向量長度；應為2的冪；設為1以禁用
#define RSSI_SMOOTH 16              // 平滑RSSI讀數的平均向量長度；應為2的冪；設為1以禁用

/********************************************************************/
/****           動態馬達/螺旋槳平衡                     ****/
/********************************************************************/
/* !!! 禁飛模式 !!! */

//#define DYNBALANCE   // (**) 由Gui控制的動態平衡

/********************************************************************/
/****           回歸測試                               ****/
/********************************************************************/

/* 僅供開發使用：
   為了更容易和可重複地測試編譯，將各種設置參數的不同組合保持在一起以進行測試編譯，
   以協助以協調的方式檢測編譯時錯誤的各種功能。
   它不是用來生成飛行固件的
   使用方法：
   - 在config.h中不要設置任何選項，
   - 使用#define COPTERTEST 1啟用，然後編譯
   - 如果可能，檢查大小
   - 以2、3、4等的其他值重複
*/
//#define COPTERTEST 1

/*************************************************************************************************/
/*****************                                                                 ***************/
/****************  SECTION  8 - 不再使用                                                 *******/
/*****************                                                                 ***************/
/*************************************************************************************************/

/* 這些功能將在不可預見的將來被刪除。不要基於這些功能構建新產品或功能。
   所有這些功能的默認值都是關閉。
*/

/**************************    WMP電源引腳     *******************************/
//#define D12_POWER      // 使用PROMINI上的D12供電傳感器。將禁用D12上的servo[4]
/* 禁用POWER引腳的使用（如果選擇了RCAUXPIN12選項，則已經執行） */
#define DISABLE_POWER_PIN

/*************************************************************************************************/
/****           可配置參數結束                                                ****/
/*************************************************************************************************/

#endif /* CONFIG_H_ */
