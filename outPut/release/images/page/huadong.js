scale=function (btn,bar,title){
	this.btn=document.getElementById(btn);
	this.bar=document.getElementById(bar);
	this.title=document.getElementById(title);
	this.step=this.bar.getElementsByTagName("DIV")[0];
	this.init();
};
var currentValue
var historyValue
scale.prototype={
	init:function (){
		var f=this,g=document,b=window,m=Math;
		f.btn.onmousedown=function (e){
			var x=(e||b.event).clientX;
			var l=this.offsetLeft;
			var max=f.bar.offsetWidth-this.offsetWidth;
			g.onmousemove=function (e){
				var thisX=(e||b.event).clientX;
				var to=m.min(max,m.max(-2,l+(thisX-x)));
				f.btn.style.left=to+'px';
				f.ondrag(m.round(m.max(0,to/max)*100),to);
				b.getSelection ? b.getSelection().removeAllRanges() : g.selection.empty();

			};
			//g.onmouseup=new Function('this.onmousemove=null');
			g.onmouseup=function(e){
				this.onmousemove="null"
				console.log(currentValue)
				console.log(historyValue)
				if (currentValue!=historyValue) {
						historyValue=currentValue
						var data={"caseId":caseId,"radius":currentValue}
						var datafunction={"functionId":"10000","data":data}
						console.log(datafunction)
						var jsonstr=JSON.stringify(datafunction)
						console.log(jsonstr)
						viewplugin.dataFromJs(jsonstr);
						console.log(caseId)
				}

			}

		};
	},
	ondrag:function (pos,x){
		this.step.style.width=Math.max(0,x)+'px';
		console.log(Math.max(0,x))
		this.title.innerHTML=pos*10+'米';
		currentValue=pos*10
	}

}
new scale('btn','bar','title');