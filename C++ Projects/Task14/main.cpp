#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mutex1;
double pi = 0;
int amountOfThreads = 0;
int counter = 1;

void countPi(int startNumber){
    double localPi = 0;
    for(int i = startNumber; i<10000000; i+=amountOfThreads) {
        auto result = (4. / (8 * i + 1) - 2. / (8 * i + 4) - 1. / (8 * i + 5) - 1. / (8 * i + 6)) / pow(16, i);
        localPi += result;
    }
    std::unique_lock<std::mutex> lock(mutex1, std::defer_lock);
    lock.lock();
    pi+=localPi;
    lock.unlock();
}

void countPi2(int startNumber){
    double localPi = 0;
    std::unique_lock<std::mutex> lock(mutex1, std::defer_lock);
    for(int i = (startNumber+1)*2-1; i<1000000000; i+=amountOfThreads*2){
        int multiplier = i%4 ==1 ? 1: -1;
        localPi+=multiplier*1./i;
    }
    pi+=4*localPi;
}

void countPi3(){
    std::unique_lock<std::mutex> lock(mutex1,std::defer_lock);
    double localPi=0;int step=10000;
    while(counter<1000000000){lock.lock();
                  int start = counter;counter+=step;
        lock.unlock();
        for(int i = start; i<start+step;i+=2){int multiplier=i%4 == 1 ? 1 : -1;
        localPi+=multiplier*1./i;}
       }
    lock.lock();pi+=4*localPi;
    lock.unlock();
}

void countPi4() {
    std::unique_lock<std::mutex> lock(mutex1, std::defer_lock);
    double localPi = 0;
    int step = 1000;
    while (counter < 10000000) {
        lock.lock();
        int start = counter;
        counter += step;
        lock.unlock();
        for (int i = start; i < start + step; i++) {
            auto result = (4. / (8 * i + 1) - 2. / (8 * i + 4) - 1. / (8 * i + 5) - 1. / (8 * i + 6)) / pow(16, i);
            localPi += result;
        }
    }
    lock.lock();
    pi += localPi;
    lock.unlock();
}

int main(){
    std::vector<std::thread> threadDB;
    std::cout<<"Enter the amount of threads(1 to 10): ";
    std::cin>>amountOfThreads;
    if(amountOfThreads<1 ||amountOfThreads>10){
        std::cout<<"Wrong thread amount!!!"<<std::endl;
        return 0;
    }
    auto startTime = std::chrono::system_clock::now();
    for (int i = 0; i < amountOfThreads; i++)
        threadDB.emplace_back(std::thread(countPi3));
    for(int i = 0; i < amountOfThreads; i++)
        threadDB[i].join();
    auto endTime = std::chrono::system_clock::now();
    std::cout<<std::setprecision(16)<<pi<<" "<<std::chrono::duration_cast<std::chrono::milliseconds>
            (endTime-startTime).count();
    //std::cout<<std::endl<<std::thread::hardware_concurrency();
    return 0;
}