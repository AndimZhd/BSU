dat <- read.table(file="text.txt", dec=",")
a<-table(dat)
result<-as.data.frame(a)
result[,3]<- 100*a/(sum(a))
result[,4]<- cumsum(result[,2])
result[,5]<- cumsum(result[,3])
colnames(result)<-c("value", "frequency", "frequence", "accum.frequency", "accumulated frequence")
plot(a,type="l",main="frequency polygon",xlab="value", ylab="frequency") 

d<-dat[,1]
v<-sort(d)
x<-unique(v)
y<-as.numeric(result[,4])
plot(x,y,type="l",xlab="value",ylab="accumulated frequency", main= "absolute frequency cumulation")

z<-as.numeric(result[,5]/100)
plot(x, z, type = "l", xlab = "value", ylab = "accumulated frequence", main = "relative frequency cumylation")

result
