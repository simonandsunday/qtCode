#ifndef _AVT_STD_H
#define _AVT_STD_H


#ifdef AVT_STD_EXPORTS
#define AVT_STD_API  extern "C" __declspec(dllexport) 
#else
#define AVT_STD_API  extern "C"
#endif//#ifdef AVT_STD_EXPORTS

typedef int                 BOOL;

//��̨����궨��
#define		AVT_PTZ_DIR_UP					10001 //��
#define		AVT_PTZ_DIR_UPSTOP				10002 //��ͣ
#define		AVT_PTZ_DIR_DOWN				10003 //��
#define		AVT_PTZ_DIR_DOWNSTOP			10004 //��ͣ
#define		AVT_PTZ_DIR_LEFT				10005 //��
#define		AVT_PTZ_DIR_LEFTSTOP			10006 //��ͣ
#define		AVT_PTZ_DIR_RIGHT				10007 //��
#define		AVT_PTZ_DIR_RIGHTSTOP			10008 //��ͣ
#define		AVT_PTZ_ZOOMOUT					10009 //��С
#define		AVT_PTZ_ZOOMOUTSTOP				10010 //��Сͣ
#define		AVT_PTZ_ZOOMIN					10011 //�Ŵ�
#define		AVT_PTZ_ZOOMINSTOP				10012 //�Ŵ�ͣ
#define		AVT_PTZ_FOCUSFAR				10013 //Զ��
#define		AVT_PTZ_FOCUSFARSTOP			10014 //Զ��ͣ
#define		AVT_PTZ_FOCUSNEAR				10015 //����
#define		AVT_PTZ_FOCUSNEARSTOP			10016 //����ͣ
#define		AVT_PTZ_PRESET_SET				10017 //Ԥ��λ
#define		AVT_PTZ_PRESET_MOVE				10018 //��Ԥ��λ
#define		AVT_PTZ_PRESET_DELETE			10019 //���Ԥ��λ
#define		AVT_PTZ_IRIS_OPEN				10020 //��IRIS
#define		AVT_PTZ_IRIS_CLOSE				10021 //�ر�IRIS
#define		AVT_PTZ_DIR_LEFTUP				10022 //����
#define		AVT_PTZ_DIR_LEFTUPSTOP			10023 //����ͣ
#define		AVT_PTZ_DIR_RIGHTUP				10024 //����
#define		AVT_PTZ_DIR_RIGHTUPSTOP			10025 //����ͣ
#define		AVT_PTZ_DIR_LEFTDOWN			10026 //����
#define		AVT_PTZ_DIR_LEFTDOWNSTOP		10027 //����ͣ
#define		AVT_PTZ_DIR_RIGHTDOWN			10028 //����
#define		AVT_PTZ_DIR_RIGHTDOWNSTOP		10029 //����ͣ
#define		AVT_PTZ_IRIS_OPENSTOP			10030 //��IRISֹͣ
#define		AVT_PTZ_IRIS_CLOSESTOP			10031 //�ر�IRISֹͣ
#define		AVT_PTZ_SET_AUX					10032 //���ø�������
#define		AVT_PTZ_CLEAR_AUX				10033 //������ø�������
#define		AVT_PTZ_ZOOM_SPEED				10061 //���������ٶ�
#define		AVT_PTZ_FOCUS_SPEED				10062 //���ñ佹�ٶ�

#define		AVT_PTZ_SET_LIGHT_PWRON			10034 //���õƹ��Դ,HIK
#define		AVT_PTZ_CLEAR_LIGHT_PWRON		10035 //������õƹ��Դ,HIK
#define		AVT_PTZ_SET_WIPER_PWRON			10036 //������ˢ����,HIK
#define		AVT_PTZ_CLEAR_WIPER_PWRON		10037 //���������ˢ����,HIK
#define		AVT_PTZ_SET_FAN_PWRON			10038 //���÷��ȿ���,HIK
#define		AVT_PTZ_CLEAR_FAN_PWRON			10039 //������÷��ȿ���,HIK
#define		AVT_PTZ_SET_HEATER_PWRON		10041 //���ü���������,HIK
#define		AVT_PTZ_CLEAR_HEATER_PWRON		10042 //������ü���������,HIK
#define		AVT_PTZ_SET_AUX_PWRON1			10043 //���ø�������1,HIK
#define		AVT_PTZ_CLEAR_AUX_PWRON1		10044 //������ø�������1,HIK
#define		AVT_PTZ_SET_AUX_PWRON2			10045 //���ø�������2,HIK
#define		AVT_PTZ_CLEAR_AUX_PWRON2		10046 //������ø�������2,HIK

#define		AVT_PTZ_SET_BACK_LIGHT			10047 //���ñ��ⲹ��,DAHUA
#define		AVT_PTZ_CLEAR_BACK_LIGHT		10048 //������ñ��ⲹ��,DAHUA
#define		AVT_PTZ_SET_DIGITAL_ZOOM		10049 //�������ֱ䱶��,DAHUA
#define		AVT_PTZ_CLEAR_DIGITAL_ZOOM		10050 //����������ֱ䱶��,DAHUA
#define		AVT_PTZ_SET_NIGHT_VIEWING		10051 //����ҹ�ӹ���,DAHUA
#define		AVT_PTZ_CLEAR_NIGHT_VIEWING		10052 //�������ҹ�ӹ���,DAHUA
#define		AVT_PTZ_SET_CAMERA_LIGHT_UP		10053 //���������������,DAHUA
#define		AVT_PTZ_CLEAR_CAMERA_LIGHT_UP	10054 //������������������,DAHUA
#define		AVT_PTZ_SET_PRETITLE_VISIBLE	10055 //����Ԥ������ʾ,DAHUA
#define		AVT_PTZ_CLEAR_PRETITLE_VISIBLE	10056 //�������Ԥ������ʾ,DAHUA

#define		AVT_PTZ_ADD_PRESET_TO_PATROL		10071 //��һ��Ԥ��λ����ָ����Ѳ����
#define		AVT_PTZ_REMOVE_PRESET_FROM_PATROL	10072 //��ָ����Ѳ������ɾ��һ��Ԥ��λ
#define		AVT_PTZ_SET_PATROL_SPEED			10073 //����Ѳ���ٶ�
#define		AVT_PTZ_SET_PATROL_STAY_DURATION	10074 //����Ѳ��ͣ��ʱ��
#define		AVT_PTZ_START_PATROL				10075 //��ʼѲ��
#define		AVT_PTZ_STOP_PATROL					10076 //ֹͣѲ��
#define		AVT_PTZ_SET_SCAN_LEFT_EDGE			10077 //�����Զ�ɨ����߽�
#define		AVT_PTZ_SET_SCAN_RIGHT_EDGE			10078 //�����Զ�ɨ���ұ߽�
#define		AVT_PTZ_SET_SCAN_SPEED				10079 //�����Զ�ɨ���ٶ�
#define		AVT_PTZ_START_SCAN					10080 //��ʼ�Զ�ɨ��
#define		AVT_PTZ_STOP_SCAN					10081 //ֹͣ�Զ�ɨ��



//¼�����ָ����
#define		AVT_RECORDCTRL_PLAY				11000	//����
#define		AVT_RECORDCTRL_CONTINUE			11000	//����
#define		AVT_RECORDCTRL_PAUSE			11001	//��ͣ
#define		AVT_RECORDCTRL_FAST				11002	//���
#define		AVT_RECORDCTRL_SLOW				11003	//����
#define		AVT_RECORDCTRL_FOREWARD			11004	//���
#define		AVT_RECORDCTRL_BACKWARD			11005	//����
#define     AVT_RECORDCTRL_SINGLE_FRAME     11006   //��֡����
#define     AVT_RECORDCTRL_POSITION			11007   //���¶�λ���ŵ�
#define		AVT_RECORDCTRL_RESUME_NORMAL	11008	//�ָ������ٶ�
#define		AVT_RECORDCTRL_REVERSE	        11009	//����
#define		AVT_RECORDCTRL_FORWARD	        11010	//����

AVT_STD_API BOOL InitSDK(const char* XMLIn);//���ؿ⣬���ҽ���ʵ��������
AVT_STD_API BOOL InitSDKEx(const char* XMLIn);//���к��������ָ���⣬���ҽ���ʵ��������
AVT_STD_API BOOL ReleaseSDK();
AVT_STD_API BOOL ReleaseSDKEx(const char* XMLIn);//���к����ж��ָ����
AVT_STD_API BOOL GetVersionInfo(const char* XMLIn, char** XMLOut, int XMLOutLen);//��ȡ�汾��Ϣ
AVT_STD_API BOOL CallSDK(const char* ModelName, const int FuncID, const char* XMLIn, char** XMLOut, int XMLOutLen);
AVT_STD_API BOOL CallSDKEx(const int FuncID, const char* XMLIn, char** XMLOut, int XMLOutLen);//���ô�ModelName��ͨ��XMLIn�е�Factory���õ�
AVT_STD_API BOOL Connect_Test(char * ip,int port,int time_out);//�����豸�Ƿ����������

AVT_STD_API int GetdllPath(char * str,int len);

#endif//#ifndef _AVT_STD_H
