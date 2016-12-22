  var map = new BMap.Map("allmap",{enableMapClick:false});
  var point = new BMap.Point(114.477675, 23.306361);
  map.centerAndZoom(point, 20);
  var marker = new BMap.Marker(point);  // 创建标注
  //map.addOverlay(marker);               // 将标注添加到地图中
  //marker.setAnimation(BMAP_ANIMATION_BOUNCE); //跳动的动画
	map.enableScrollWheelZoom(true);
  var menu= new BMap.ContextMenu();
  var caseId;
  var trackPointObj={};
  trackPointObj.marker=new Array();
  var txtMenuItem = [
    {
      text:'显示报警人轨迹',
      callback:function(){

        map.removeOverlay(trackPointObj.polyline);
        for (var i = 0; i < trackPointObj.marker.length; i++) {
            map.removeOverlay(trackPointObj.marker[i]);
        }

        var data={"caseId":caseId}
        var datafunction={"functionId":"10001","data":data}
        var jsonstr=JSON.stringify(datafunction)
        viewplugin.dataFromJs(jsonstr);
        console.log(jsonstr)
      }
    },
    {
      text:'清除报警人轨迹',
      callback:function(){
        console.log("test")
        var data={"caseId":caseId}
        var datafunction={"functionId":"10002","data":data}
        var jsonstr=JSON.stringify(datafunction)
        viewplugin.dataFromJs(jsonstr);
        map.removeOverlay(trackPointObj.polyline);
        for (var i = 0; i < trackPointObj.marker.length; i++) {
            map.removeOverlay(trackPointObj.marker[i]);
        }
        console.log(jsonstr)
      }
    }
  ];
  for(var i=0; i < txtMenuItem.length; i++){
    menu.addItem(new BMap.MenuItem(txtMenuItem[i].text,txtMenuItem[i].callback,100));
  }
  map.addContextMenu(menu);

  map.addEventListener("tilesloaded",function(){

  })
//type 0:报案人，1：游客，2：案件处理人，3：保安员，4：摄像头，5：案件地点
var locationPic = [[0,"报案人","pages/alarmReport.png"],
	[1,"游客","pages/currentLocation.png"],
	[2,"案件处理人","pages/police.png"],
	[3,"保安员","pages/guard.png"],
	[4,"摄像头","pages/normalDevice.png"],
	[5,"案件地点","pages/normalDevice.png"],
  [6,"point","pages/trackpoint.png"],
  [7,"startpoint","pages/startPoint.png"],
  [8,"endpoint","pages/endPoint.png"]
];


    function dataDistribute( dataString){
      var datajson=JSON.parse(dataString);
      var functionId=datajson.functionId
      console.log(functionId)
      console.log(datajson)
      var data = datajson.data
      if(functionId==10000){
        console.log("10000")
        function_10000(data)
      }else if (functionId==10001) {
        function_10001(data)
      }
      else{
          console.log("else")
      }
    }
    function function_10001(data){
        //显示轨迹
        console.log(data);
        var startPoint=data.startPoint;
        var endPoint=data.endPoint;
        var userName=data.userName;
        var userType=data.userType;
        var userPic;
        var pointsData=data.points;
        if(userType==0){
           // userPic = new BMap.Icon(locationPic[0][2], new BMap.Size(20,30));
        }else if (userType==1) {
            //userPic = new BMap.Icon(locationPic[4][2], new BMap.Size(20,30));
        }
        addStartTrackPoint(startPoint,userName,userPic);
        addEndTrackPoint(endPoint,userName,userPic);
        addTrackLine(pointsData,userType,userName);
    }
    function addTrackLine(pointsData,userType,userName){

       var points=[];
        for (var i = 0; i < pointsData.length; i++) {
            var lon=pointsData[i].LONGITUDE;
            var dim=pointsData[i].LATITUDE;
            var loc_time=pointsData[i].LOC_TIME;
            var point =[new BMap.Point(lon,dim)]
            points=points.concat(point)
            if(i!=0&&i!=pointsData.length-1){
                userPic = new BMap.Icon(locationPic[6][2], new BMap.Size(10,14));
                var type=0;
                addpointToMap(lon,dim,loc_time,userName,userPic,type);
            }

        }      
         var polyline = new BMap.Polyline(points,{strokeColor:"blue", strokeWeight:3, strokeOpacity:0.5}); 
         polyline.setStrokeStyle("dashed");
         trackPointObj.polyline=polyline;
          map.addOverlay(polyline);
    }
    function addStartTrackPoint(startPoint,userName,userPic){
        console.log(startPoint)
        var lon=startPoint.LONGITUDE;
        var dim=startPoint.LATITUDE;
        var time=startPoint.LOC_TIME;
        var type=1;
        userPic = new BMap.Icon(locationPic[7][2], new BMap.Size(26,30));
        addpointToMap(lon,dim,time,userName,userPic,type);
    }
    function addEndTrackPoint(endPoint,userName,userPic){
        console.log(endPoint);
        var lon=endPoint.LONGITUDE;
        var dim=endPoint.LATITUDE;
        var time=endPoint.LOC_TIME;
        var type=2;
        userPic = new BMap.Icon(locationPic[8][2], new BMap.Size(26,30));
        addpointToMap(lon,dim,time,userName,userPic,type);
    }
    function getTimeFromUnix(unixTime, timeOBJ){
        var date=new Date(unixTime*1000);
        var y=date.getFullYear()+"-";
        M = (date.getMonth()+1 < 10 ? '0'+(date.getMonth()+1) : date.getMonth()+1) + '-';
        D = date.getDate() + ' ';
        h = date.getHours() + ':';
        m = date.getMinutes() + ':';
        s = date.getSeconds(); 
        timeOBJ.message=y+M+D+h+m+s;
    }
    function  addpointToMap(lon,dim,time,userName,userPic,type){
        console.log(lon);
        console.log(dim);
        var point = new BMap.Point(lon, dim);
        var marker = new BMap.Marker(point,{icon:userPic});  // 创建标注
        map.addOverlay(marker);               // 将标注添加到地图中
        trackPointObj.marker.push(marker);
        var timeOBJ={};
        getTimeFromUnix(time,timeOBJ);
        addClickHandler("pointId",timeOBJ.message,6,marker)
    }
    function function_10000(data){    
        var datajson=data.data
        console.log(datajson)
        var i
        map.clearOverlays()
        for(i=0;i<datajson.length;i++){
            var baidulon=datajson[i].baidulon;
            var baidudim=datajson[i].baidudim
            var id=datajson[i].id
            var type=datajson[i].type
            var name=datajson[i].name
            var location=datajson[i].location
            var showMessage=datajson[i].showMessage
            var radius=datajson[i].radius
            console.log(radius)
            console.log(showMessage)
            if (type==5) {
              loadCenterPoint(id,type,name,location,baidulon,baidudim,showMessage,radius)
            }else if (type==4) {
                loadDevicePoint(id,type,name,location,baidulon,baidudim,showMessage);
            }else if (type==3) {
                loadGuardPoint(id,type,name,location,baidulon,baidudim,showMessage)
            }else if (type==2) {
                loadHandlerPoint(id,type,name,location,baidulon,baidudim,showMessage);
            }
            else if (type==1) {
                loadVistorPoint(id,type,name,location,baidulon,baidudim,showMessage);
            }else if (type==0) {
                loadCaseReporter(id,type,name,location,baidulon,baidudim,showMessage);
            }
            }

    }
    function loadCenterPoint(id,type,name,location,baidulon,baidudim,showMessage,radius){
            console.log(name)
            console.log(radius)
            caseId=id;
            map.panTo(new BMap.Point(baidulon,baidudim))
            var point = new BMap.Point(baidulon, baidudim);
            var marker = new BMap.Marker(point);  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            marker.setAnimation(BMAP_ANIMATION_BOUNCE); //跳动的动画
            addClickHandler(id,showMessage,type,marker)
            caseId=id
            this.title.innerHTML=radius+'米';
            this.btn.style.left=radius/2-radius/125+'px';
            var circle = new BMap.Circle(point,radius,{fillColor:"blue", strokeWeight: 1 ,fillOpacity: 0.1, strokeOpacity: 0.9});
            map.addOverlay(circle);
    }
    function loadDevicePoint(id,type,name,location,baidulon,baidudim,showMessage){
            console.log(name)
            var point = new BMap.Point(baidulon, baidudim);
            var myIcon = new BMap.Icon(locationPic[4][2], new BMap.Size(20,30));
            //var marker2 = new BMap.Marker(pt,{icon:myIcon});  // 创建标注
            var marker = new BMap.Marker(point,{icon:myIcon});  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            addClickHandler(id,showMessage,type,marker)
    }
    function loadGuardPoint(id,type,name,location,baidulon,baidudim,showMessage){
            console.log(name)
            var point = new BMap.Point(baidulon, baidudim);
            var myIcon = new BMap.Icon(locationPic[2][2], new BMap.Size(20,30));
            //var marker2 = new BMap.Marker(pt,{icon:myIcon});  // 创建标注
            var marker = new BMap.Marker(point,{icon:myIcon});  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            addClickHandler(id,showMessage,type,marker)
    }
    function loadHandlerPoint(id,type,name,location,baidulon,baidudim,showMessage){
            console.log(name)
            var point = new BMap.Point(baidulon, baidudim);
            var myIcon = new BMap.Icon(locationPic[3][2], new BMap.Size(20,30));
            //var marker2 = new BMap.Marker(pt,{icon:myIcon});  // 创建标注
            var marker = new BMap.Marker(point,{icon:myIcon});  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            addClickHandler(id,showMessage,type,marker)
    }
    function loadVistorPoint(id,type,name,location,baidulon,baidudim,showMessage){
            console.log(name)
            var point = new BMap.Point(baidulon, baidudim);
            var marker = new BMap.Marker(point);  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            addClickHandler(id,showMessage,type,marker)

    }
    function loadCaseReporter(id,type,name,location,baidulon,baidudim,showMessage){
              console.log(name)
              console.log(id)
            var point = new BMap.Point(baidulon, baidudim);
            var myIcon = new BMap.Icon(locationPic[0][2], new BMap.Size(20,30));
            var marker = new BMap.Marker(point,{icon:myIcon});  // 创建标注
            map.addOverlay(marker);               // 将标注添加到地图中
            addClickHandler(id,showMessage,type,marker)

    }
    function attribute(e){
    var p = e.target;
    alert("marker的位置是" + p.getPosition().lng + "," + p.getPosition().lat);    
  }
  function addClickHandler(id,showMessage,type,marker){
      marker.addEventListener("mouseover",function(e){
        openInfo(id,showMessage,type,e)
      });
  }
  var useropts={
        width:250,
        height:80,
        title:"用户信息",
        enableMessage:true
  };
  var caseopts={
        width:250,
        height:100,
        title:"案件信息",
        enableMessage:true
  };
    var trackPointopts={
        width:100,
        height:30,
        title:"当前时间：",
        enableMessage:true
  };
  function openInfo(id,showMessage,type,e){
    var p = e.target;
    var point = new BMap.Point(p.getPosition().lng, p.getPosition().lat);
    var opts;
    if (type==0) {
      //用户
      opts=useropts;
    }else if (type==5) {
      opts=caseopts;
    }else if (type==6) {
      opts=trackPointopts;
    }
    var infoWindow = new BMap.InfoWindow(showMessage,opts);  // 创建信息窗口对象 
    map.openInfoWindow(infoWindow,point); //开启信息窗口
  }


