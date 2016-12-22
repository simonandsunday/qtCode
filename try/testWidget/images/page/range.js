    // 定义一个控件类,即function
  function ZoomControl(){
    // 默认停靠位置和偏移量
    this.defaultAnchor = BMAP_ANCHOR_TOP_LEFT;
    this.defaultOffset = new BMap.Size(10, 10);
  }

  // 通过JavaScript的prototype属通过JavaScript的prototype属性继承于BMap性继承于BMap.Control
  ZoomControl.prototype = new BMap.Control();

  // 自定义控件必须实现自己的initialize方法,并且将控件的DOM元素返回
  // 在本方法中创建个div元素作为控件的容器,并将其添加到地图容器中
  ZoomControl.prototype.initialize = function(map){
    // 创建一个DOM元素
    var div = document.createElement("div");
    // 添加文字说明
    var testNode=document.createTextNode("获取更大范围的监控点")
    div.appendChild(testNode);
    // 设置样式 

    div.style.cursor = "pointer";
    div.style.border = "1px solid gray";
    div.style.backgroundColor = "white";
    // 绑定事件,点击一次放大两级
    div.onclick = function(e){
    map.setZoom(map.getZoom() - 2);

    console.log(caseId)

    }
    // 添加DOM元素到地图中
    map.getContainer().appendChild(div);
    // 将DOM元素返回
    return div;
  }
  // 创建控件
  var myZoomCtrl = new ZoomControl();
  // 添加到地图当中
  map.addControl(myZoomCtrl);