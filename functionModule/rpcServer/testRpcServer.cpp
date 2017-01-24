#include "testRpcServer.h"
#include"JsonToHash.h"
#include"mobileServiceLog.h"
#include<QDebug>
#include"RestfulFunctionId.h"
#include"testDatabase.h"
testRpcServer::testRpcServer()
{
}

void testRpcServer::distributionInterface(std::string &_return, const std::string &content)
{
    JsonToHash jsonTohash;
    QVariantHash hash=jsonTohash.AnalysisJSONToHash(QString::fromUtf8(content.c_str()));
    QVariantHash returnHash;
    if(hash.isEmpty())
    {
        returnHash.insert("result", false);
        returnHash.insert("msg",    QString("解析json错误"));
        returnHash.insert("code",   0);
        returnHash.insert("data",   "");

        _return = jsonTohash.AnalysisHashToJSON(returnHash).toStdString();
        qDebug()<<__func__<<__LINE__<<QString::fromUtf8(content.c_str())<<"解析json错误";
        QString data=QString::fromUtf8(content.c_str());
        QString error=QString("data:%1,error:%2").arg(data).arg("解析json错误");
        INFO_PRINT(AVT_LOG_ERROR,error);
        return;
    }else {

    }
    QString data=QString::fromUtf8(content.c_str());
    INFO_PRINT(AVT_LOG_INFO,data);
    if(!hash.contains("FUNCTIONID")){
        returnHash.insert("result", false);
        returnHash.insert("msg",    QString("functionId 字段缺失"));
        returnHash.insert("code",   0);
        returnHash.insert("data",   "");

        _return = jsonTohash.AnalysisHashToJSON(returnHash).toStdString();
        qDebug()<<__func__<<__LINE__<<QString::fromUtf8(content.c_str())<<"functionId 字段缺失";
        return;
    }else{
        //keep going
    }
    QString functionId=hash.value("FUNCTIONID").toString();
    switch (functionId.toInt()) {
    case restfulId_sendAlarm:{
        // 发送报警
        //interfaceCore.restful_sendAlarm(returnHash,hash);
    }
        break;
    case restfulId_getMySendAlarm:{
        // 获取我发出的报警信息（状态处理未处理/处理中）
        //interfaceCore.restful_getMySendAlarm(returnHash,hash);
    }
        break;
    case restfulId_urge:{
        // 报警催促
        //interfaceCore.restful_urge(returnHash,hash);
    }
        break;
    case restfulId_releseAlarm_as_danger_gone:{
        // 解除报警 危险已经解除
        //interfaceCore.restful_releseAlarm_as_danger_gone(returnHash,hash);
    }
        break;
    case restfulId_releseAlarm_as_mistake:{
         // 解除报警 原因不小心按错
        //interfaceCore.restful_releseAlarm_as_mistake(returnHash,hash);
    }
        break;
    case restfulId_upgradeAlarm:{
        //案情升级
        //interfaceCore.restful_upgradeAlarm(returnHash,hash);
    }
        break;
    case restfulId_sumbitGetuiClientId:{
        //提交用户个推用户id
        //interfaceCore.restful_submitGetuiClientId(returnHash,hash);
    }
        break;
    case restfulId_getMyDealCase:{
        //获取我处理的案件信息
        //interfaceCore.restful_getMyDealCase(returnHash,hash);
    }
        break;
    case restfulId_confirmCase:{
        //确认案件
        //interfaceCore.restful_confirmCase(returnHash,hash);
    }
        break;
    case restfulId_call110:{
        //报110
        //interfaceCore.restful_call110(returnHash,hash);
    }
        break;
    case restfulId_DoneCase:{
        //完成处理报警
        //interfaceCore.restful_doneCase(returnHash,hash);
    }
        break;
    case restfulId_getAlarmHistoryList:{
        //获取报警历史
        //interfaceCore.restful_getAlarmHistoryList(returnHash,hash);
    }
        break;
    case restfulId_getAlarmHistoryItemDetail:{
        //获取报警案件详细信息
        //interfaceCore.restful_getAlarmHistoryItemDetail(returnHash,hash);
    }
        break;
    case restfulId_submitComment:{
        //提交对案件的评论
        //interfaceCore.restful_submitComment(returnHash,hash);
    }
        break;
    case restfulId_getCircleRegionGuardLoacation:{
        //获取圆形范围内保安的地理位置信息
        //interfaceCore.restful_getCircleRegionGuardLoacation(returnHash,hash);
    }
        break;
    case restfulId_getCircleRegionMonitoryLocation:{
        //获取指定位置附近监控点信息
        //interfaceCore.restful_getCircleRegionMonitoryLocation(returnHash,hash);
    }
        break;
    case restfulId_submitUserLocation:{
        //提交用户地理位置
        //interfaceCore.restful_submitUserLocation(returnHash,hash);
    }
        break;
    case restfulId_getAlarmLocation:{
        //获取报警点的地理位置
        //interfaceCore.restful_getAlarmLocation(returnHash,hash);
    }
        break;
    case restfulId_registerUser:{
        //用户注册
        //interfaceCore.restful_registerUser(returnHash,hash);
    }
        break;
    case restfulId_applyRegisterAuthCode:{
        //申请验证码
        //interfaceCore.restful_applyRegisterAuthCode(returnHash,hash);
    }
        break;
    case resttulId_getAssignUserId:{
        //获取指定用户userid
        //interfaceCore.restful_getAssignUserId(returnHash,hash);
    }
        break;
    case resttulId_getUserAuthId:{
        //获取用户操作认证码（相当于登陆）
        //interfaceCore.restful_getUserAuth(returnHash,hash);
    }
        break;
    case resttulId_releaseUserAuthId:{
        //释放用户操作认证码（相当于退出登录）
        //interfaceCore.restful_releaseUserAuth(returnHash,hash);
    }
        break;
    case restfulId_submitDeviceLocation:{
        //提交设备通道地理位置
        //interfaceCore.restful_submitDeviceLocation(returnHash,hash);
    }
        break;
    case restfulId_resetPassword:{
        //提交设备通道地理位置
        //interfaceCore.restful_resetPassword(returnHash,hash);
    }
        break;
    case restfulId_getMyDealCaseList:{
        //interfaceCore.restful_getMyDealCaseList(returnHash,hash);
    }
        break;
    case restfulId_applyDealCase:{
        //interfaceCore.restful_applyDealCase(returnHash,hash);
    }
        break;
    case restfulId_giveupDealCase:{
        //interfaceCore.restful_giveupDealCase(returnHash,hash);
    }
        break;
    case restfulId_pauseDealCase:{
        //interfaceCore.restful_pauseDealCase(returnHash,hash);
    }
        break;
    case restfulId_getUserCurrentLocation:{
        //interfaceCore.restful_getUserCurrentLocation(returnHash,hash);
    }
        break;
    case restfulId_getUserTrack:{
        //interfaceCore.restful_getUserTrack(returnHash,hash);
    }
        break;
    case restfulId_getMobileAlarmHistoryList:{
        //interfaceCore.restful_getMobileAlarmHistoryList(returnHash,hash);
    }
        break;
    case restfulId_getAlarmType:{
        //interfaceCore.restful_getAlarmType(returnHash,hash);
    }
        break;
    case restfulId_startTimingAlarm:{
        //interfaceCore.restful_startTimingAlarm(returnHash,hash);
    }
        break;
    case restfulId_cancelTimingAlarm:{
        //interfaceCore.restful_cancelTimingAlarm(returnHash,hash);
    }
        break;
    case restfulId_getMydealAlarmHistoryCaseList:{
        //interfaceCore.restful_getMyDealAlarmHistoryCaseList(returnHash,hash);
    }
        break;
    case restfulId_getMySendAlarmHistoryCaseList:{
        //interfaceCore.restful_getMySendAlarmHistoryCaseList(returnHash,hash);
        testDatabase entity;
        entity.test_restful_getMySendAlarmHistoryCaseList(returnHash,hash);
    }
        break;
    case restfulId_getCircleRegionCaseLocation:{
        //interfaceCore.restful_getCircleRegionCaseLocation(returnHash,hash);
    }
        break;
    case restfulId_confirmToRelease:{
        //interfaceCore.restful_confirmToRelease(returnHash,hash);
    }
        break;
    case restfulId_getBannerList:{
        //interfaceCore.restful_getBannerList(returnHash,hash);
        break;
    }
    case restfulId_getWebPortalsInfo:{
        //interfaceCore.restful_getWebPortalsInfo(returnHash,hash);
        break;
    }
    case restfulId_getUserCapacitySet:{
        //interfaceCore.restful_getUserCapacitySet(returnHash,hash);
        break;
    }
    case restfulId_releaseAlarm:{
        //interfaceCore.restful_releaseAlarm(returnHash,hash);
        break;
    }
    case restfulId_getGuardLoacationByCaseId:{
        //interfaceCore.restful_getGuardLoacationByCaseId(returnHash,hash);
        break;
    }
    case restfulId_getFreeCaseList:{
        //interfaceCore.restful_getFreeCaseList(returnHash,hash);
        break;
    }
    default:{
        returnHash.insert("errorId", 10033);
        returnHash.insert("detail",    QString("functionId 没有找到匹对的值"));
        returnHash.insert("snId",   0);
        returnHash.insert("data",   QVariantHash());

        _return = jsonTohash.AnalysisHashToJSON(returnHash).toStdString();
        qDebug()<<__func__<<__LINE__<<QString::fromUtf8(content.c_str())<<"functionId 没有找到匹对的值";
    }
        break;
    }
}
