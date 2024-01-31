#include <iostream>
#include <taskflow/taskflow.hpp> 
#include "thread_header.h"
using namespace std;

int main()
{
tf::Executor executor; 
tf::Taskflow taskflow;
auto [A, B, C, D] = taskflow.emplace( // create tasks 
[] () { thread th1(loadData);
th1.join();},
[] () { thread th2(getKMeans);
th2.join(); },
[] () { thread th3(getKNN);
th3.join(); },
[] () { thread th4(predictCluster); 
th4.join(); }
);
A.precede(B); // Task A is executed before Task B 
B.precede(C); // Task B is executed before Task C 
C.precede(D); // Task C is executed before Task D
executor.run(taskflow).wait(); // executes the tasks
}
