#include <string>
#include <iostream>
#include <memory>  // Required for smart pointers
#include <vector>

using namespace std;

class Resource {
private:
    string name;
public:
    Resource(string n) : name(n) {
        cout << "Allocated Resource: " << name << endl;
    }
    ~Resource() {
        cout << "Deallocated Resource: " << name << endl;
    }
    void sayHello() const {
        cout << "Resource " << name << " says hello!" << endl;
    }
};

int main() 
{
    // Raw Pointer
    cout << "Testing Raw Pointer" << endl;
    // Allocation must be done manually using 'new'
    Resource* rawPtr = new Resource("Raw_OldSchool");
    rawPtr->sayHello();

    // Raw pointers can be copied implicitly without any warnings
    Resource* rawPtrCopy = rawPtr;
    rawPtrCopy->sayHello();

    // CRITICAL DANGER 1: If we forget to call 'delete', the memory leaks forever!
    cout << "Manually deleting raw pointer" << endl;
    delete rawPtr;
    cout << endl;
    // unique_ptr

    cout << "1. Testing unique_ptr" << endl;
    {
        // Allocation using make_unique
        unique_ptr<Resource> res1 = make_unique<Resource>("Unique_A");
        res1->sayHello();

        // unique_ptr<Resource> res2 = res1; // ERROR! Compilation fails. Cannot be copied.

        // We can transfer ownership using move semantics:
        unique_ptr<Resource> res2 = move(res1);

        if (res1 == nullptr) {
            cout << "res1 is now empty/nullptr because ownership moved to res2." << endl;
        }
        res2->sayHello();
    }
    // Block ends here. res2 goes out of scope and "Unique_A" is automatically deleted.
    cout << "Outside unique_ptr scope block.\n" << endl;

    // shared_ptr
    cout << "2. Testing shared_ptr" << endl;
    shared_ptr<Resource> globalShared;
    {
        cout << "Entering inner shared block..." << endl;
        shared_ptr<Resource> localShared = make_shared<Resource>("Shared_B");

        globalShared = localShared; // Ownership is explicitly SHARED via copying

        cout << "Exiting inner shared block..." << endl;
    } // localShared dies here

    cout << "Outside inner block. References to Shared_B: " << endl;
    globalShared->sayHello();

    cout << "Resetting globalShared..." << endl;
    globalShared.reset(); // Memory is finally freed right here!
    cout << endl;
    // weak_ptr
    cout << "3. Testing weak_ptr" << endl;
    weak_ptr<Resource> observer;

    {
        shared_ptr<Resource> tempShared = make_shared<Resource>("Weak_C");
        observer = tempShared; // Points to Weak_C

        // To use a weak_ptr, you must upgrade it to a shared_ptr temporarily using .lock()
        if (shared_ptr<Resource> activePointer = observer.lock()) {
            cout << "Observer status: Resource is alive!" << endl;
            activePointer->sayHello();
        }
        cout << "Exiting tempShared block..." << endl;
    } // tempShared dies, ref count drops to 0, "Weak_C" is immediately destroyed.

    // Let's check the observer again now that the owner is dead
    if (shared_ptr<Resource> activePointer = observer.lock()) {
        // This code will not execute
    }
    else {
        cout << "Observer status: Resource is dead. Pointer safely invalidated without crashing." << endl;
    }

    return 0;
}