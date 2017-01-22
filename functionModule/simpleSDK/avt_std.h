#ifndef _AVT_STD_H
#define _AVT_STD_H


#ifdef AVT_STD_EXPORTS
#define AVT_STD_API  extern "C" __declspec(dllexport) 
#else
#define AVT_STD_API  extern "C"
#endif//#ifdef AVT_STD_EXPORTS

typedef int                 BOOL;

//云台方向宏定义
#define		AVT_PTZ_DIR_UP					10001 //上
#define		AVT_PTZ_DIR_UPSTOP				10002 //上停
#define		AVT_PTZ_DIR_DOWN				10003 //下
#define		AVT_PTZ_DIR_DOWNSTOP			10004 //下停
#define		AVT_PTZ_DIR_LEFT				10005 //左
#define		AVT_PTZ_DIR_LEFTSTOP			10006 //左停
#define		AVT_PTZ_DIR_RIGHT				10007 //右
#define		AVT_PTZ_DIR_RIGHTSTOP			10008 //右停
#define		AVT_PTZ_ZOOMOUT					10009 //缩小
#define		AVT_PTZ_ZOOMOUTSTOP				10010 //缩小停
#define		AVT_PTZ_ZOOMIN					10011 //放大
#define		AVT_PTZ_ZOOMINSTOP				10012 //放大停
#define		AVT_PTZ_FOCUSFAR				10013 //远焦
#define		AVT_PTZ_FOCUSFARSTOP			10014 //远焦停
#define		AVT_PTZ_FOCUSNEAR				10015 //近焦
#define		AVT_PTZ_FOCUSNEARSTOP			10016 //近焦停
#define		AVT_PTZ_PRESET_SET				10017 //预置位
#define		AVT_PTZ_PRESET_MOVE				10018 //调预置位
#define		AVT_PTZ_PRESET_DELETE			10019 //清除预置位
#define		AVT_PTZ_IRIS_OPEN				10020 //打开IRIS
#define		AVT_PTZ_IRIS_CLOSE				10021 //关闭IRIS
#define		AVT_PTZ_DIR_LEFTUP				10022 //左上
#define		AVT_PTZ_DIR_LEFTUPSTOP			10023 //左上停
#define		AVT_PTZ_DIR_RIGHTUP				10024 //右上
#define		AVT_PTZ_DIR_RIGHTUPSTOP			10025 //右上停
#define		AVT_PTZ_DIR_LEFTDOWN			10026 //左下
#define		AVT_PTZ_DIR_LEFTDOWNSTOP		10027 //左下停
#define		AVT_PTZ_DIR_RIGHTDOWN			10028 //右下
#define		AVT_PTZ_DIR_RIGHTDOWNSTOP		10029 //右下停
#define		AVT_PTZ_IRIS_OPENSTOP			10030 //打开IRIS停止
#define		AVT_PTZ_IRIS_CLOSESTOP			10031 //关闭IRIS停止
#define		AVT_PTZ_SET_AUX					10032 //设置辅助功能
#define		AVT_PTZ_CLEAR_AUX				10033 //清除设置辅助功能
#define		AVT_PTZ_ZOOM_SPEED				10061 //设置缩放速度
#define		AVT_PTZ_FOCUS_SPEED				10062 //设置变焦速度

#define		AVT_PTZ_SET_LIGHT_PWRON			10034 //设置灯光电源,HIK
#define		AVT_PTZ_CLEAR_LIGHT_PWRON		10035 //清除设置灯光电源,HIK
#define		AVT_PTZ_SET_WIPER_PWRON			10036 //设置雨刷开关,HIK
#define		AVT_PTZ_CLEAR_WIPER_PWRON		10037 //清除设置雨刷开关,HIK
#define		AVT_PTZ_SET_FAN_PWRON			10038 //设置风扇开关,HIK
#define		AVT_PTZ_CLEAR_FAN_PWRON			10039 //清除设置风扇开关,HIK
#define		AVT_PTZ_SET_HEATER_PWRON		10041 //设置加热器开关,HIK
#define		AVT_PTZ_CLEAR_HEATER_PWRON		10042 //清除设置加热器开关,HIK
#define		AVT_PTZ_SET_AUX_PWRON1			10043 //设置辅助功能1,HIK
#define		AVT_PTZ_CLEAR_AUX_PWRON1		10044 //清除设置辅助功能1,HIK
#define		AVT_PTZ_SET_AUX_PWRON2			10045 //设置辅助功能2,HIK
#define		AVT_PTZ_CLEAR_AUX_PWRON2		10046 //清除设置辅助功能2,HIK

#define		AVT_PTZ_SET_BACK_LIGHT			10047 //设置背光补偿,DAHUA
#define		AVT_PTZ_CLEAR_BACK_LIGHT		10048 //清除设置背光补偿,DAHUA
#define		AVT_PTZ_SET_DIGITAL_ZOOM		10049 //设置数字变倍能,DAHUA
#define		AVT_PTZ_CLEAR_DIGITAL_ZOOM		10050 //清除设置数字变倍能,DAHUA
#define		AVT_PTZ_SET_NIGHT_VIEWING		10051 //设置夜视功能,DAHUA
#define		AVT_PTZ_CLEAR_NIGHT_VIEWING		10052 //清除设置夜视功能,DAHUA
#define		AVT_PTZ_SET_CAMERA_LIGHT_UP		10053 //设置摄像机亮度增,DAHUA
#define		AVT_PTZ_CLEAR_CAMERA_LIGHT_UP	10054 //清除设置摄像机亮度增,DAHUA
#define		AVT_PTZ_SET_PRETITLE_VISIBLE	10055 //设置预置题显示,DAHUA
#define		AVT_PTZ_CLEAR_PRETITLE_VISIBLE	10056 //清除设置预置题显示,DAHUA

#define		AVT_PTZ_ADD_PRESET_TO_PATROL		10071 //将一个预置位加入指定的巡航组
#define		AVT_PTZ_REMOVE_PRESET_FROM_PATROL	10072 //从指定的巡航组中删除一个预置位
#define		AVT_PTZ_SET_PATROL_SPEED			10073 //设置巡航速度
#define		AVT_PTZ_SET_PATROL_STAY_DURATION	10074 //设置巡航停留时间
#define		AVT_PTZ_START_PATROL				10075 //开始巡航
#define		AVT_PTZ_STOP_PATROL					10076 //停止巡航
#define		AVT_PTZ_SET_SCAN_LEFT_EDGE			10077 //设置自动扫描左边界
#define		AVT_PTZ_SET_SCAN_RIGHT_EDGE			10078 //设置自动扫描右边界
#define		AVT_PTZ_SET_SCAN_SPEED				10079 //设置自动扫描速度
#define		AVT_PTZ_START_SCAN					10080 //开始自动扫描
#define		AVT_PTZ_STOP_SCAN					10081 //停止自动扫描



//录像控制指令码
#define		AVT_RECORDCTRL_PLAY				11000	//播放
#define		AVT_RECORDCTRL_CONTINUE			11000	//继续
#define		AVT_RECORDCTRL_PAUSE			11001	//暂停
#define		AVT_RECORDCTRL_FAST				11002	//快放
#define		AVT_RECORDCTRL_SLOW				11003	//慢放
#define		AVT_RECORDCTRL_FOREWARD			11004	//快进
#define		AVT_RECORDCTRL_BACKWARD			11005	//快退
#define     AVT_RECORDCTRL_SINGLE_FRAME     11006   //单帧播放
#define     AVT_RECORDCTRL_POSITION			11007   //重新定位播放点
#define		AVT_RECORDCTRL_RESUME_NORMAL	11008	//恢复正常速度
#define		AVT_RECORDCTRL_REVERSE	        11009	//倒放
#define		AVT_RECORDCTRL_FORWARD	        11010	//正放

AVT_STD_API BOOL InitSDK(const char* XMLIn);//加载库，并且进行实例化对象
AVT_STD_API BOOL InitSDKEx(const char* XMLIn);//运行后随机加载指定库，并且进行实例化对象
AVT_STD_API BOOL ReleaseSDK();
AVT_STD_API BOOL ReleaseSDKEx(const char* XMLIn);//运行后随机卸载指定库
AVT_STD_API BOOL GetVersionInfo(const char* XMLIn, char** XMLOut, int XMLOutLen);//获取版本信息
AVT_STD_API BOOL CallSDK(const char* ModelName, const int FuncID, const char* XMLIn, char** XMLOut, int XMLOutLen);
AVT_STD_API BOOL CallSDKEx(const int FuncID, const char* XMLIn, char** XMLOut, int XMLOutLen);//不用传ModelName，通过XMLIn中的Factory来得到
AVT_STD_API BOOL Connect_Test(char * ip,int port,int time_out);//测试设备是否可以连接上

AVT_STD_API int GetdllPath(char * str,int len);

#endif//#ifndef _AVT_STD_H
