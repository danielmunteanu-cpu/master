#include"Global.h"
std::mutex mtx;

void task(const std::string& threadName)
{
    for (int i = 0; i < 5; i++)
    {
        std::lock_guard<std::mutex> lock(mtx);

        // Read
        int temp = global_variable;

        // Modify
        temp++;

        // Write
        global_variable = temp;

        // Print
        std::cout << threadName
            << " -> global variable = "
            << global_variable << std::endl;
    }
}

int main()
{
    std::thread t1(task, "Thread 1");
    std::thread t2(task, "Thread 2");

    t1.join();
    t2.join();

    std::cout << "\nFinal value: "
        << global_variable << std::endl;

    return 0;
}