#include <cstddef>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utility>

class MyThread
{
#define CHECK(func) \
	if ((func) == -1) \
	{\
		std::cout << __LINE__ <<std::endl; \
		throw std::system_error(errno, std::generic_category()); \
	}

private:
	pid_t id = -1;
	char* child_stack = nullptr;
	size_t stack_size = 1024*1024;

public:
	MyThread() = default;

	MyThread(MyThread&& other)
	{
		swap(other);
	}

	explicit MyThread(int(*f)(void*))
	{
		child_stack = new char[stack_size];
		id = clone(f, child_stack + stack_size, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD, 0);
		CHECK(id);
	}

	MyThread(const MyThread&) = delete;

	~MyThread()
	{
		if(id != -1)
			kill(id, SIGTERM);
		delete[] child_stack;
	}

	MyThread& operator=(const MyThread&) = delete;

	MyThread& operator=(MyThread&& other)
	{
		swap(other);
		return *this;
	}

	void join()
	{
		CHECK(waitpid(id, NULL, 0));
	}

	void swap(MyThread& other)
	{
		std::swap(id, other.id);
		std::swap(child_stack, other.child_stack);
		std::swap(stack_size, other.stack_size);
	}

	bool joinable() const
	{
		return kill(id, 0) == 0;		
	}

	pid_t get_id() const
	{
		return id;
	}

};


