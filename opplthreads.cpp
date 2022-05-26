//Futures, async, Packaged tasks, Promises


#include <iostream>
#include <future>


//MUTEX
#include <mutex>

int value = 0;
std::mutex mutex;

void setValue(int v) {
  mutex.lock();
  //  std::lock_guard<std::mutex> g(mutex); It works by locking the provided Mutex on creation and unlocking it on it’s destructor (when it goes out of scope).
  value = v;
  mutex.unlock();
}


//
int addNumbers(int a, int b) {
  return a + b;
}

int dupNumbers(int a, int b) {
  return a * b;
}
int main() {

    //Futures, async,

  std::cout << "Start of the program\n";
  std::future<int> fut = std::async(addNumbers, 1, 2); //auto
  auto fut2 = std::async(dupNumbers, 3, 2);
  std::cout << "Calculating the sum asynchronously\n";
  std::cout << "The result is: " << fut2.get() << "\n";
  std::cout << "End of the program\n";

    //Packaged tasks

  std::packaged_task<int(int, int)> pt(addNumbers);
  std::cout << "Created the packaged_task\n";

  std::future<int> fut3 = pt.get_future();
  std::cout << "Got the future, but haven't executed the task\n";

  std::thread t(std::move(pt), 6, 2);
  t.join();
  std::cout << "Started the task in a thread\n";

  std::cout << "The result is: " << fut3.get() << "\n";

  std::cout << "End of the program\n";

    //Promises


  std::cout << "Start of the program\n";
  std::promise<int> pr;
  std::cout << "Created the promise\n";

  std::future<int> fut = pr.get_future();
  std::cout << "Got the future\n";

  std::thread t(addNumbers, 1, 2, std::move(pr));
  t.join();
  std::cout << "Executing in thread\n";

  std::cout << "The result is: " << fut.get() << "\n";

  std::cout << "End of the program\n";



//MUTEX 


std::thread t1(setValue, 1);
std::thread t2(setValue, 2);

t1.join();
t2.join();

std::cout << value << "\n";


}

//מה זה Apache בהקשר של לא לבזז קורים של מעבד ?