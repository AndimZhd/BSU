
f<-read.table("data.txt")

mediumlevel<-mean(f[,1])
mediumlevel
result<-numeric()
for(i in 1:length(f[,1])) {
  if(f[i,1]>mediumlevel) result<-c(result, 1)
  if(f[i,1]<mediumlevel) result<-c(result, 0)
}
y<-f[,1]
result
numberofseries<-1
var<-result[1]
for(i in 2:length(result)) {
  if(result[i]!=var) {
    numberofseries<-numberofseries+1
    var<-result[i]
  }
}

numberofseries
leftpart<-as.integer((length(result)+1)/2-2*sqrt(length(result)-1)/2)
leftpart
rightpart<-as.integer((length(result)+1)/2+2*sqrt(length(result)-1)/2)
rightpart
if(leftpart<=numberofseries & numberofseries<=rightpart) {
  answer<-"There is a trend"
} else {
  answer<-"There is no trend"
}
answer

#?????????????????????? 3-?????????????????? ????????????????????
smoothed<-numeric()
smoothed<-c(smoothed, (5*y[1]+2*y[2]-y[3])/6)
for(i in 2:(length(f[,1])-1)) {
  smoothed<-c(smoothed, (y[i-1]+y[i]+y[i+1])/3)
}
smoothed<-c(smoothed, (5*y[length(f[,1])-1]+2*y[length(f[,1])-2]-y[length(f[,1])-3])/6)
smoothed

#?????????????????????? ???????? ????????????????
t<-numeric()
var<-((-1)*as.integer(length(y)/2))
as.integer(length(y)/2)
for(i in 1:length(y)) {
  t<-c(t, var)
  var<-var+1
}
f[,2]<-t
f[,3]<-t*t
f[,4]<-f[,1]*f[,2]
colnames(f)<-c("Course", "t", "t^2", "y*t")
f

a0<-sum(f[,1]/length(f[,1]))
a1<-sum(f[,4])/sum(f[,3])
equation<-paste("y(t)=", a0, "+", a1, "*t")
equation


analyticsmoothed<-numeric()
for(i in 1:length(f[,1])) {
  analyticsmoothed<-c(analyticsmoothed, a0+a1*(i-as.integer(length(y)/2)))
}
ynext<-a0+a1*(max(t)+1)
ynext
fun1<-function(x) f[,1]
fun2<-function(x) smoothed
fun3<-function(x) analyticsmoothed
matplot(cbind(fun1(x),fun2(x), fun3(x)),type="l",col=c("blue","red", "green"), xlab="time", ylab="BYN to RUB course", main="Graphs")
legend(x="top", legend=c("first", "smoothed", "analytic smoothed"), lty=c(1,1,1), lwd=c(2.5,2.5,2.5), col=c("blue", "red", "green"))