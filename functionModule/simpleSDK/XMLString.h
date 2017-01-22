#ifndef __XML_STRING_FOR_SDK_H__
#define __XML_STRING_FOR_SDK_H__

static const char* SDK_INIT_STR_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?><Param><Path>%1</Path></Param>";

static const char *XML_PLAY_REAL_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                   "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RealPlayStart\">"\
                                   "<ConnectInfo  PlayHandle=\"%3\" Mode=\"%20\" Prior=\"255\" Param=\"%23\" ServerPort=\"%2\" ClientPort=\"0\" ReceiveOnly=\"0\" FuncPtr=\"0\" UserData = \"0\" HWAcc=\"0\" ChannelNO=\"%6\"  LinkMode=\"0\" Blocked=\"0\" CallbackFuncPtr=\"0\" PlayMode=\"0\"></ConnectInfo>"\
                                   "<Login IP=\"%10\" Port=\"%11\" LoginID=\"%12\" Password=\"%13\" ChannelIP=\"%17\" ChannelPort=\"%18\" ChannelLoginID=\"%14\" ChannelPassword=\"%15\"></Login>"\
                                   "<Camera StreamName=\"%19\" CameraId=\"%16\" IP=\"%4\" Slot=\"%5\" Port=\"%6\"  Channel=\"%6\" CameraID=\"%6\" BelongToAsID=\"AS\" IsSupportMultiCast=\"1\" IsUseMS = \"1\" IsBufferOn=\"0\"></Camera>"\
                                   "<Monitor IP=\"%9\" Slot=\"%7\" Port=\"%8\"  Channel=\"%8\"></Monitor>"\
                                   "<MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>"\
                                   "<RtspUrl url=\"%21\" Port=\"%22\" rtspport=\"%22\"></RtspUrl>"\
                                   "</Param>";

static const char *XML_PLAY_REAL_SIMPLE_infinova="<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                           "<Param Factory=\"avt_sdkadapter_infinova.dll\">"\
                                           "<ConnectInfo infIp=\"%1\" infPort=\"%2\" infUser=\"%3\" infPwd=\"%4\" StreamType=\"%5\" PlayHandle=\"%6\" FuncPtr=\"0\" UserData=\"0\"></ConnectInfo>"\
                                           "<Camera ID=\"%7\"></Camera>"\
                                           "<Channel ID=\"%8\"></Channel>"\
                                           "</Param>";
static const char *XML_PLAY_REAL_SIMPLE_AVPhone="<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                          "<Param Factory=\"avt_sdkadapter_mobile.dll\" Device=\"Camera\" Func=\"MakeCall\">"\
                                          "<ConnectInfo PlayHandle=\"%1\"></ConnectInfo>"\
                                          "<Camera PhoneNumber=\"%2\" Line=\"%3\" Type=\"%4\"></Camera>"\
                                          "</Param>";
static const char *XML_PLAY_REGISTER_SIMPLE_AVPhone="<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                             "<Param Factory=\"avt_sdkadapter_mobile.dll\" Device=\"Camera\" Func=\"Register\">"\
                                             "<Login ServerIP=\"%1\" ServerPort=\"%2\" StunServerIP=\"%3\" StunServerPort=\"%4\" LoginID=\"%5\" Password=\"%6\"></Login>"\
                                             "</Param>";
static const char *XML_LOGIN_SIMPLE_NVS= "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                    "<Param Factory=\"avt_sdkadapter_nvs.dll\" Device=\"Camera\" Func=\"Login\">"\
                                    "<Login ServerIP=\"%1\" ServerPort=\"%2\" Domain=\"%3\" LoginID=\"%4\" Password=\"%5\"></Login>"\
                                    "</Param>";
static const char *XML_LOGOUT_SIMPLE_NVS= "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                    "<Param Factory=\"avt_sdkadapter_nvs.dll\" Device=\"Camera\" Func=\"Logout\">"\
                                    "</Param>";
static const char *XML_SYS_GET_DEVICELIST_SIMPLE_NVS= "<Param Factory=\"avt_sdkadapter_nvs.dll\" Device=\"Camera\" Func=\"DeviceList\">"\
                                                      "<DeviceList GroupID=\"%1\" Type=\"%2\"/>"\
                                                      "</Param>";
static const char *XML_STOP_REAL_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                   "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RealPlayStop\">"\
                                   "<ConnectInfo  PlayHandle=\"%3\" Mode=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%2\" ClientPort=\"0\" ReceiveOnly=\"0\"></ConnectInfo>"\
                                   "</Param>";
static const char *XML_STOP_UNREGISTER_SIMPLE_AVPhone = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                                 "<Param Factory=\"avt_sdkadapter_mobile.dll\" Device=\"Camera\" Func=\"UnRegister\">"\
                                                 "</Param>";
static const char *XML_STOP_DISCONNECT_SIMPLE_AVPhone = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                                    "<Param Factory=\"avt_sdkadapter_mobile.dll\" Device=\"Camera\" Func=\"HangupCall\">"\
                                                    "<ConnectInfo PlayHandle=\"%1\"></ConnectInfo>"\
                                                    "</Param>";
static const char *XML_CONTROL_PLAY_BACK = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
                                    "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordControlPlayback\">"
                                    "<ConnectInfo  PlayHandle=\"%3\" Mode=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%2\" ClientPort=\"0\" Type = \"0\" Func = \"0\"></ConnectInfo>"
                                    "<Camera IP=\"%4\" Slot=\"%5\" Port=\"%6\"></Camera>"
                                    "<Monitor IP=\"127.0.0.1\" Slot=\"%7\" Port=\"%8\"></Monitor>"
                                    "<Storage IP=\"%9\" Slot=\"%10\" Port=\"%11\"></Storage>"
                                    "<MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>"
                                    "<RecordPlay Start=\"%12\" End=\"%13\"></RecordPlay>"
                                    "<Control Command=\"%14\" Speed=\"%15\"></Control>"
                                    "</Param>";
static const char *XML_PLAY_BACK = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
                            "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordPlayStart\">"
                            "<ConnectInfo  PlayHandle=\"%3\" Mode=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%2\" ClientPort=\"0\" Type = \"0\" Func = \"0\"></ConnectInfo>" \
                            "<Login IP=\"%15\" Port=\"%16\" LoginID=\"%17\" Password=\"%18\" ChannelIP=\"%21\" ChannelPort=\"%22\" ChannelLoginID=\"%19\" ChannelPassword=\"%20\"></Login>"\
                            "<StorageLogin IP=\"%15\" Port=\"%16\" LoginID=\"%17\" Password=\"%18\" ChannelIP=\"%21\" ChannelPort=\"%22\" ChannelLoginID=\"%19\" ChannelPassword=\"%20\"></StorageLogin>"\
                            "<StorageCamera Channel=\"%6\"></StorageCamera>"\
                            "<Camera CameraId=\"%14\" IP=\"%4\" Slot=\"%5\" Port=\"%6\"></Camera>" \
                            "<Monitor IP=\"127.0.0.1\" Slot=\"%7\" Port=\"%8\"></Monitor>" \
                            "<Storage IP=\"%9\" Slot=\"%10\" Port=\"%11\"></Storage>"\
                            "<MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>" \
                            "<RecordPlay Start=\"%12\" End=\"%13\" StartTime=\"%23\" StopTime=\"%24\"></RecordPlay>" \
                            "<RecordInfo StartTime=\"%23\" StopTime=\"%24\" Type=\"0\" Locked=\"0\" UseCardNo=\"0\" CardNumber=\"0\"></RecordInfo>"\
                            "<QueryInfo RecordFileType=\"0\"  StartTime=\"%23\" StopTime=\"%24\" WaitTime=\"1000\" EnableTime=\"0\"></QueryInfo>"\
                            "</Param>";

static const char *XML_STOP_Playback_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                       "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RealPlayStop\">"\
                                       "<ConnectInfo  PlayHandle=\"%3\" Mode=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%2\" ClientPort=\"0\" ReceiveOnly=\"0\"></ConnectInfo>"\
                                       "<Camera IP=\"%4\" Slot=\"%5\" Port=\"%6\"></Camera>"
                                       "<Monitor IP=\"127.0.0.1\" Slot=\"0\" Port=\"0\"></Monitor>"
                                       "<Login IP=\"%4\"></Login>"\
                                       "</Param>";
static const char *XML_QUERY_CONNECT_TABLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"avt_sdkadapter_avtrace.dll\" Device=\" Camera\" Func=\" QueryConnect\">\r\n\
        <ConnectInfo Prior=\"255\" ServerPort=\"40000\"></ConnectInfo>\r\n\
        <Camera IP=\"%1\" Slot=\"%2\" Port=\"%3\"></Camera>\r\n\
        </Param>";

        static const char *XML_GET_CHASSISINFO_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                                 "<Param Factory=\"%1\" Device=\" Camera\" Func=\" GetMachineInfo\">"\
                                                 "<Camera IP=\"%2\" Slot=\"2\" Port=\"1\"></Camera>"\
                                                 "<Monitor IP=\"192.168.168.0\" Slot=\"2\" Port=\"1\"></Monitor>"\
                                                 "<MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>"\
                                                 "<ConnectInfo Mode=\"0\" PlayHandle=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%3\" ClientPort=\"0\"></ConnectInfo>"\
                                                 "</Param>";

static const char *XML_GET_BOARDINFO_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
                                       "<Param Factory=\"%1\" Device=\" Camera\" Func=\" GetMachineBoard\">"
                                       "<Camera IP=\"%2\" Slot=\"2\" Port=\"1\"></Camera>"
                                       "<Monitor IP=\"192.168.168.0\" Slot=\"3\" Port=\"2\"></Monitor>"
                                       "<MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>"
                                       "<ConnectInfo Mode=\"0\" PlayHandle=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"%3\" ClientPort=\"0\"></ConnectInfo>"
                                       "</Param>";



static const char *XML_SET_VAS_DRAW_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
                                      "<Param Factory=\"%1\" Device=\" Camera\" Func=\" GetMachineBoard\">"
                                      "<ConnectInfo PlayHandle=\"0\" EnableGreen=\"%2\" EnableRed=\"%3\" EnableDeploy=\"%4\"></ConnectInfo>"
                                      "</Param>";

static const char *XML_GET_VAS_DRAW_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
                                      "<Param Factory=\"%1\" Device=\" Camera\" Func=\" GetMachineBoard\">"
                                      "<ConnectInfo PlayHandle=\"0\" EnableGreen=\"%2\" EnableRed=\"%3\" EnableDeploy=\"%4\"></ConnectInfo>"
                                      "</Param>";

static const char *XML_SET_CALLBACK_FUNCTION = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"SetYUV420Callback\">\r\n\
        <ConnectInfo PlayHandle=\"%2\" UserDataPtr=\"%3\" Func =\"0\" UserData=\"0\"></ConnectInfo>\r\n\
        <Function Pointer=\"%4\"  UserData=\"%3\"></Function>\r\n\
        </Param>";

        static const char *XML_GET_IS_DRAW_VAS_CIRCLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"VAS\" Func=\"IsDrawVasCircle\">\r\n\
        <ConnectInfo PlayHandle=\"%2\"></ConnectInfo>\r\n\
        </Param>";

        static const char* XML_RETURN_SIMPLE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                        "<Result>"\
                                        "<Return>1</Return>"\
                                        "<ErrorCode>%1,%2,%3</ErrorCode>"\
                                        "</Result>";

        static const char* XML_ADJUST_VIDEO_PARAM = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"%1\" Device=\" Camera\" Func=\"AdjustVideoParam\"> \r\n\
        <Camera IP=\"%2\" Slot=\"%4\" Port=\"%5\"></Camera> \r\n\
        <ConnectInfo Prior=\"255\" Param=\"%6\" ServerPort=\"%3\"></ConnectInfo> \r\n\
        </Param>";

        static const char* XML_OSD_CONTROL = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"OSDControl\"> \r\n\
        <ConnectInfo PlayHandle=\"%2\" Mode=\"0\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo> \r\n\
        <OSDInfo Color=\"%3\"></OSDInfo> \r\n \
        </Param>";
        static const char* XML_CANCEL_STATIC_OBJECT = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \
                <Param Factory=\"avt_sdkadapter_avtrace.dll\" Device=\"VAS\" Func=\"CANCELSTATICOBJECT\"> \
                    <VAS IP=\"%1\" Port=\"40000\"/> \
                    <Camera IP=\"%2\" Slot=\"%3\" Port=\"%4\"> \
                <Point X=\"%5\" Y=\"%6\"> </Point> \
                </Camera> \
                </Param> ";
        static const char* XML_SET_OSD_PARAM = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"avt_sdkadapter_avtrace.dll\" Device=\"Camera\" Func=\"SetOsdExParam\"> \r\n\
        <ConnectInfo PlayHandle=\"%1\"></ConnectInfo> \r\n \
        <OSDInfo Param=\"%2\"></OSDInfo> \r\n \
        </Param>";

        static const char* XML_OSD_TRANSPARENT = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"avt_sdkadapter_avtrace.dll\" Device=\"Camera\" Func=\"SetOsdExDraw\"> \r\n\
        <ConnectInfo PlayHandle=\"%1\"></ConnectInfo> \r\n\
        <OSDInfo Transparent=\"%2\"></OSDInfo> \r\n \
        </Param>";

        static const char* XML_RECORD_QUERY = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"%1\" Device=\" Camera\" Func=\" RecordQueryStart\"> \r\n\
        <ConnectInfo Prior=\"255\" ServerPort=\"%2\" FuncPtr=\"%20\" UserData=\"%21\" FuncPtrAll=\"%22\"></ConnectInfo> \r\n\
        <Login IP=\"%10\" Port=\"%11\" LoginID=\"%12\" Password=\"%13\" ChannelIP=\"%9\" ChannelPort=\"%14\" ChannelLoginID=\"%15\" ChannelPassword=\"%16\"></Login>\
        <Storage IP=\"%3\"></Storage> \r\n\
        <StorageLogin IP=\"%10\" Port=\"%11\" LoginID=\"%12\" Password=\"%13\"></StorageLogin> \r\n\
        <StorageCamera Channel=\"%6\"></StorageCamera> \r\n\
        <Camera IP=\"%4\" Slot=\"%5\" Port=\"%6\" CameraId=\"%17\" Channel=\"%6\" CameraID=\"%6\" BelongToAsID=\"AS\"></Camera> \r\n\
        <QueryInfo Start=\"%7\" End=\"%8\" StartTime=\"%19\" StopTime=\"%18\"></QueryInfo> \r\n\
        <RecordInfo Start=\"%7\" End=\"%8\" StartTime=\"%19\" StopTime=\"%18\" Type=\"0\" Locked=\"0\" UseCardNo=\"0\" CardNumber=\"0\"></RecordInfo> \r\n\
        </Param>";
        static const char* XML_STOP_LOCAL_FILE_RECORD = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordFilePlayStop\"> \
        <ConnectInfo PlayHandle=\"%2\"></ConnectInfo>\
        </Param>";

        static const char *XML_STATR_DOWNLOAD = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                         "<Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordDownloadStart\">"\
                                         "<ConnectInfo Prior=\"255\" Param=\"0\" ServerPort=\"%2\" ClientPort=\"0\" FuncPtr=\"%3\" UserData =\"%4\"></ConnectInfo>"\
                                         "<Login IP=\"%19\" Port=\"%20\" LoginID=\"%21\" Password=\"%22\" ChannelIP=\"%17\" ChannelPort=\"%18\" ChannelLoginID=\"%14\" ChannelPassword=\"%15\"></Login>"\
                                         "<Camera IP=\"%5\" Slot=\"%6\" Port=\"%7\" Channel=\"%7\" CameraId=\"%16\" CameraID=\"%7\" BelongToAsID=\"AS\"></Camera>"\
                                         "<Storage IP=\"%8\" Slot=\"%9\" Port=\"%10\"></Storage>"\
                                         "<RecordPlay Start=\"%11\" End=\"%12\"  SaveFileName =\"%13\" FileName=\"%13\"></RecordPlay>"\
                                         "<RecordInfo Start=\"%11\" End=\"%12\"  SaveFileName =\"%13\" FileName=\"%13\"></RecordInfo>"\
                                         "</Param>";


static const char *XML_STATR_LOCAL_RECORD = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"LocalRecordStart\">\
        <ConnectInfo Mode=\"0\" PlayHandle=\"%2\" Prior=\"255\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo>\
        <Filename Filename=\"%3\"></Filename>\
        </Param>";

        static const char* XML_START_LOCAL_FILE_RECORD ="<Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordFilePlayStart\"> \
        <ConnectInfo PlayHandle=\"%2\" Mode=\"0\" Prior=\"255\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo>\
        <RecordPlay FileName=\"%3\"></RecordPlay>\
        <Monitor IP=\"127.0.0.1\" Slot=\"0\" Port=\"0\"></Monitor>\
        </Param>";

        static const char* XML_SOUND_CONTROL = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"CloseSound\">\
        <ConnectInfo PlayHandle=\"%2\" Mode=\"0\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo>\
        </Param>";

        static const char* XML_AVT_SOUND_CONTROL = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"%2\"> \
            <Camera IP=\"%3\" Slot=\"%4\" Port=\"%5\"></Camera> \
            <Monitor IP=\"127.0.0.1\" Slot=\"1\" Port=\"1\"></Monitor> \
            <ConnectInfo PlayHandle=\"0\" Mode=\"0\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo>\
            <MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>\
            </Param>";

        //打开对讲
        static const char* XML_OPEN_TALKBACK = " <Param Factory=\"%1\" Device=\"Camera\" Func=\"StartTalkback\">\
        <Login IP=\"%2\" LoginID=\"%3\" Password=\"%4\"></Login>\
        <Talkback pUserContext=\"%5\" Mode=\"%6\" TalkbackInterfaceErrorCallback=\"%7\"></Talkback>\
        <Camera StreamName=\"%8\" ServerPort=\"%9\"></Camera>\
        </Param>";
        //关闭对讲
        static const char* XML_CLOSE_TALKBACK = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"removeDeviceFromTalkback\">\
        <Talkback TalkbackContext=\"%2\"></Talkback>\
        </Param>";
        //检测设备麦克风是否可用
        static const char* XML_CHECK_MICROPHONE = "<Param Factory=\"%1\" Device=\"Camera\" Func=\"checkClientIsSupportTalkback\">\
        <Talkback ></Talkback>\
        </Param>";
        static const char * XML_GET_INFINNOVA_DEVICELIST="<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
        <Param Factory=\"avt_sdkadapter_infinova.dll\" Device=\"Camera\" Func=\"GetCameraList\">\
        <ConnectInfo IP=\"%1\" Port=\"%2\" User=\"%3\" Password=\"%4\" lLoginHandle=\"0\"></ConnectInfo>\
        </Param>";
        static const char* XML_SNAP_PICTURE = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
        <Param Factory=\"%3\" Device=\"Camera\" Func=\"Snap\">\
        <ConnectInfo PlayHandle=\"%1\"></ConnectInfo>\
        <File Filename=\"%2\"></File>\
        <Snap Path=\"%2\" BufferAddress=\"0\" BufferSize=\"0\"></Snap>\
        </Param>";
        static const char* XML_SET_DIGITAL_ZOOM = "<Param Factory=\"%6\" Device=\"Camera\" Func=\"SetDigitalZoom\">\
        <ConnectInfo PlayHandle=\"%1\" TopX=\"%2\" TopY=\"%3\" Width=\"%4\" Height=\"%5\"></ConnectInfo>\
        </Param>";
        static const char* XML_RESET_DIGITAL_ZOOM = "<Param Factory=\"%2\" Device=\"Camera\" Func=\"SetDigitalZoom\">\
        <ConnectInfo PlayHandle=\"%1\" ></ConnectInfo>\
        </Param>";
        static const char* XML_PTZ_CONTROL = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"PTZControl\"> \r\n\
        <PTZ IP=\"%2\" Protocol=\"%3\" Slot=\"%4\" Port=\"%5\" DeviceID=\"%6\" Delay=\"%7\" Prior=\"%8\" DataPort=\"%9\" ParamID=\"%10\" PtzPrior=\"%11\"  ShowName=\"%12\" OSDName=\"%24\"></PTZ> \r\n\
        <PTZControl Command=\"%13\" HStep=\"%14\" VStep=\"%15\" Delay=\"%16\" Stop=\"0\" PresetID=\"%17\" PresetName=\"%18\" ProfileToken=\"%30\"></PTZControl> \r\n\
        <Login IP=\"%26\" Port=\"%27\" LoginID=\"%28\" Password=\"%29\" ChannelIP=\"%19\" ChannelPort=\"%20\" ChannelLoginID=\"%21\" ChannelPassword=\"%22\"></Login>\
        <Camera CameraId=\"%23\" Channel=\"%25\" CameraID=\"%25\"></Camera>\r\n\
        </Param>";
        static const char* XML_PTZ_INFINOVA_CONTROL ="<?xml version=\"1.0\" encoding=\"utf-8\" ?>"\
                                              "<Param Factory=\"%1\" Device=\"Camera\" Func=\"PTZControl\">"\
                                              "<Camera ID=\"%2\"></Camera>"\
                                              "<Login IP=\"%3\" Port=\"%4\" User=\"%5\" Password=\"%6\" lLoginHandle=\"4\"></Login>"\
                                              "<PTZControl Type=\"0\" Command=\"%7\" Stop=\"%8\" Speed=\"%9\" PresetID=\"%10\" PatternIndex=\"0\" AuxIndex=\"1\"></PTZControl>"\
                                              "</Param>";
        static const char* XML_PTZ_CONTROL_USING = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"SetPtzUserName\">\r\n\
        <Camera IP=\"%2\" Slot=\"%3\" Port=\"%4\" ServerPort=\"%5\"></Camera>\r\n\
        <PTZUser Delay=\"%6\" Flag=\"0\" Prior=\"%7\" OSDName=\"%8\" ShowName=\"%9\"></PTZUser>\r\n\
        </Param>";
        static const char* XML_PTZ_USING = "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"PTZControl\"> \r\n\
        <ConnectInfo Prior=\"%4\" ServerPort=\"%2\" ></ConnectInfo> \
        <Camera IP=\"%3\"></Camera>\
        </Param>";
        static const char* XML_TX_TO_RX_CONNECT = "<Param Factory=\"%7\" Device=\"Camera\" Func=\"ConnectTX2RX\"> \
        <ConnectInfo Mode=\"%9\" Prior=\"255\" Param=\"%8\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo> \
        <Camera IP=\"%1\" Slot=\"%2\" Port=\"%3\"></Camera>\
        <Monitor IP=\"%4\" Slot=\"%5\" Port=\"%6\"></Monitor>\
        <MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>\
        </Param>";

        static const char* XML_TX_TO_RX_PLAYBACK = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"RecordPlayStartToRX\">\r\n\
        <ConnectInfo Mode=\"%4\" Prior=\"%2\" Param=\"0\" ServerPort=\"%3\" ClientPort=\"0\"></ConnectInfo>\r\n\
        <Storage IP=\"%5\" Slot=\"%6\" Port=\"%7\"></Storage>\r\n\
        <Monitor IP=\"%8\" Slot=\"%9\" Port=\"%10\"></Monitor>\r\n\
        <MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>\r\n\
        <Camera IP=\"%11\" Slot=\"%12\" Port=\"%13\"></Camera>\r\n\
        <RecordPlay Style=\"%14\" Start=\"%15\" End=\"%16\" Ctrl=\”%17\”></RecordPlay>\r\n\
        <Control Command=\"%18\" Speed=\"%19\"></Control>\r\n\
        </Param>";

        static const char *XML_GET_YUV_COLOR = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"GetYuvColor\">\r\n\
        <ConnectInfo PlayHandle=\"%2\"></ConnectInfo>\r\n\
        </Param>";

        static const char *XML_SET_YUV_COLOR = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"AdjustYuvColor\">\r\n\
        <ConnectInfo PlayHandle=\"%2\" Brightness=\"%3\" Contrast=\"%4\" Saturation=\"%5\" Hue=\"%6\"></ConnectInfo>\r\n\
        </Param>";

        static const char *XML_RESET_YUV_COLOR = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"%1\" Device=\"Camera\" Func=\"ResetGetYuvColor\">\r\n\
        <ConnectInfo PlayHandle=\"%2\"></ConnectInfo>\r\n\
        </Param>";

        static const char *XML_GET_PLAYING_TIME = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\r\n\
        <Param Factory=\"avt_sdkadapter_avtrace.dll\" Device=\"Camera\" Func=\"GetPlayingTime\">\r\n\
            <Camera IP=\"192.168.168.0\" Slot=\"2\" Port=\"1\"></Camera>\r\n\
            <Monitor IP=\"192.168.168.0\" Slot=\"2\" Port=\"1\"></Monitor>\r\n\
            <ConnectInfo PlayHandle=\"%1\" Mode=\"0\" Param=\"0\" ServerPort=\"40000\" ClientPort=\"0\"></ConnectInfo>\r\n\
            <MutilCast IP=\"0.0.0.0\" Port=\"0\"></MutilCast>\r\n\
        </Param>";

#endif // __XML_STRING_FOR_SDK_H__
