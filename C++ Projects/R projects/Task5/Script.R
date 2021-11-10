table <- read.table ("data.txt")
t<-scale(table)
plot(t,type="p",main="Scatter diagram",xlab="X", ylab="Y")
cl1 <- kmeans(t,2)
table(cl1$cluster)
cl1$centers

plot(t,col=c("blue", "green")[cl1$cluster])
legend("topright",legend=c("1","2"),fill=c("blue","green"))

plot(t,pch=(1:2)[cl1$cluster])
legend("topright",legend=c("1","2"),pch=c(1,2))

cl2<-kmeans(t,3)
table(cl2$cluster)
cl2$centers

plot(t,col=c("blue", "green", "red")[cl2$cluster])
legend("topright",legend=c("1","2", "3"),fill=c("blue","green", "red"))

plot(t,pch=(1:3)[cl2$cluster])
legend("topright",legend=c("1","2","3"),pch=c(1,2,3))