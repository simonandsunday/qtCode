#ifndef RESTFULFUNCTIONID_H
#define RESTFULFUNCTIONID_H

#define restfulId_sendAlarm 1000000 // 发送报警
#define restfulId_getMySendAlarm 1000001 // 获取我发出的报警信息（状态处理未处理/处理中）
#define restfulId_urge 1000002 // 报警催促
#define restfulId_releseAlarm_as_danger_gone 1000003 // 解除报警 危险已经解除
#define restfulId_releseAlarm_as_mistake 1000004 // 解除报警 原因不小心按错
#define restfulId_upgradeAlarm 1000005 // 报警升级
#define restfulId_getMyDealCase 1000006 // 获取我处理的报警信息
#define restfulId_confirmCase 1000007 // 确认报警信息
#define restfulId_call110 1000008 // 通知110
#define restfulId_DoneCase 1000009 // 处理完报警
#define restfulId_getAlarmHistoryList 1000010 // 获取报警历史
#define restfulId_getAlarmHistoryItemDetail 1000011 // 获取某个报警的详细信息
#define restfulId_getPersonalInformation 1000012 // 获取我的详细信息
#define restfulId_submitPersonalInformation 1000013 // 提交我的信息
#define restfulId_changePassword 1000014 // 修改登录密码
#define restfulId_applyRealNameAuth 1000015 // 申请实名认证
#define restfulId_getEventMessList 1000016 // 获取事件消息的列表
#define restfulId_clearAllEventMess 1000017 // 清除所有的事件消息
#define restfulId_getEventMessDetail 1000018 // 获取事件消息的详细内容
#define restfulId_getRealVedioInfo 1000019 // 获取报警信息的实时视频信息
#define restfulId_getRealVedioInfo 1000020 // 获取报警信息的录像信息
#define restfulId_getFriendList 1000021 // 获取我的好友列表
#define restfulId_getChatList 1000027 // 获取群聊列表
#define restfulId_getChatLog 1000022 // 获取与某个好友的聊天信息
#define restfulId_sendChatMess 1000023 // 发送聊天信息 （one-to-one）
#define restfulId_revokeChatMess 1000024 // 撤销某条聊天内容
#define restfulId_addContact 1000025 // 添加好友
#define restfulId_addContact 1000026 // 处理添加好友申请
#define restfulId_setupGroupChat 1000028 // 发起群聊
#define restfulId_addMemberToGroupChat 1000029 // 添加成员到群聊
#define restfulId_removeMemberToGroupChat 1000030 // 从群聊中剔除某个成员
#define restfulId_getGroupChatLog 1000031 // 获取某个群聊的聊天内容
#define restfulId_sendMessToGroupChat 1000032 // 发送信息到群聊
#define restfulId_getOnDutyMess 1000033 // 获取正在执行巡逻的信息
#define restfulId_signTask 1000034 // 点击签到
#define restfulId_getOnDutyMess 1000035 // 获取巡逻任务列表
#define restfulId_startDuty 1000036 // 开始巡逻任务
#define restfulId_submitFeedback 1000037 // 提交投诉
#define restfulId_setConfiguration 1000038 // 提交配置信息
#define restfulId_submitComment 1000039 // 提交案件评论
#define restfulId_getMyVideoList 1000040 // 获取我的视频list
#define restfulId_addVideoToMyFavorite 1000041 // 添加视频到我的收藏
#define restfulId_removeVideoFromMyFavorite 1000042 // 取消收藏
#define restfulId_getVideoInfo 1000043 // 获取我的视频详细信息
#define restfulId_ptz 1000044 // 云台控制
#define restfulId_getVideoHistoryInfo 1000045 // 获取视频通道录像信息
#define restfulId_getMyFavoriteVideoList 1000046 //获取我的收藏视频list
#define restfulId_getCityList 1000047 //获取城市list
#define restfulId_getCityVideoList 1000048 //获取指定城市视频
#define restfulId_getCircleRegionGuardLoacation 1000049 //获取圆形范围内保安员的地理位置与信息
#define restfulId_getCircleRegionMonitoryLocation 1000050 //获取圆形范围内监控点的地理位置与信息
#define restfulId_submitUserLocation 1000051 //提交用户地理位置
#define restfulId_getAlarmLocation 1000052 //获取报警点的地理位置

#define restfulId_registerUser 1000053 //用户注册
#define restfulId_applyRegisterAuthCode 1000054//申请用户注册验证码
#define restfulId_sumbitGetuiClientId 1000055 //提交用户的个推clientId
#define resttulId_getAssignUserId 1000056//获取指定用户userid
#define resttulId_getUserAuthId 1000057//获取用户操作认证码（相当于登陆）
#define resttulId_releaseUserAuthId 1000058//释放用户操作认证码（相当于退出登录）
#define restfulId_submitDeviceLocation 1000059//提交设备通道地理位置
#define restfulId_resetPassword 1000060//提交设备通道地理位置
#define restfulId_getMyDealCaseList 1000061//获取用户处理的案件列表
#define restfulId_applyDealCase 1000062//用户领取分配的案件
#define restfulId_giveupDealCase 1000063//放弃处理案件
#define restfulId_pauseDealCase 1000064//用户暂停处理案件
#define restfulId_getUserCurrentLocation 1000065 //获取用户当前位置
#define restfulId_getUserTrack 1000066 //获取用户当前位置
#define restfulId_getMobileAlarmHistoryList 1000067 //获取报警历史信息（V5客户端使用）
#define restfulId_getAlarmType 1000068//获取报警类型
#define restfulId_startTimingAlarm 1000069//开启定时防护报警
#define restfulId_cancelTimingAlarm 1000070//取消定时防护报警
#define restfulId_getMydealAlarmHistoryCaseList 1000071//获取我处理的报警历史
#define restfulId_getMySendAlarmHistoryCaseList 1000072//获取我发出的报警历史
#define restfulId_getCircleRegionCaseLocation   1000073//获取圆形范围内案件信息
#define restfulId_confirmToRelease   1000074//确认解除报警
#define restfulId_getBannerList   1000075//获取锦旗列表
#define restfulId_getWebPortalsInfo   1000076//获取门户网站信息
#define restfulId_getUserCapacitySet   1000077//获取用户能力集
#define restfulId_releaseAlarm   1000078//解除报警
#define restfulId_getGuardLoacationByCaseId   1000079//根据案件获取保安员的地理位置信息
#define restfulId_getFreeCaseList   1000080//获取自由案件列表
#endif // RESTFULFUNCTIONID_H
