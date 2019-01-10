#include <cstddef>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <utility>

class MyThread
{
private:
	pid_t id;
	char* child_stack;
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
		id = clone(f, child_stack + stack_size, CLONE_NEWUTS | CLONE_NEWUSER | SIGCHLD, 0);
	       	if (id == -1)
			exit(EXIT_FAILURE);
	}

	MyThread(const MyThread&) = delete;

	~MyThread()
	{
		if(joinable() == true)
			kill(id, SIGTERM);
		delete[] child_stack;
	}

	MyThread& operator=(const MyThread&) = delete;

	MyThread& operator=(MyThread&& other)
	{
		if(joinable())
			kill(id, SIGTERM);	
		swap(other);
		return *this;
	}

	void join()
	{
		waitpid(id, NULL, 0);
		if (joinable() == false)
			exit(EXIT_FAILURE);
		else
			kill(id, SIGTERM);
		id = 0;
	}

	void swap(MyThread& other)
	{
		std::swap(id, other.id);
		std::swap(child_stack, other.child_stack);
		std::swap(stack_size, other.stack_size);
	}

	bool joinable() const
	{
		return !(id == 0);
	}

	pid_t get_id() const
	{
		return id;
	}

};


