template <class Function>
class MyThread
{
	//size_t stack_size = 1024*1024;
//	char* child_stack;
//	char* child_stack_end;
	class id
	{
		int threadId;
public:
		id() : threadId() { }

		explicit id(int _id)
		{
			threadId = _id;
		}

private:
		friend class MyThread;

		friend bool operator==(MyThread::id _x, MyThread::id _y)
		{
			return _x.threadId == _y.ThreadId;
		}

		friend bool operator<(MyThread::id _x, MyThread::id _y)
		{
			return _x.threadId < _y.threadId;
		}
	};

private:
	id thread_id;

public:
	MyThread() = default;

	MyThread(MyThread&& other)
	{
		swap(other);
	}

	explicit MyThread(Function&& f)
	{
		//TODO:
		thread_id = clone(f, child_stack_end, SIGCHLD, 0);
	       	if (thread_id == -1)
		       //TODO: define exit code
		       exit(EXIT_FAILURE);
	       	if(waitpid(thread_id, NULL, 0) == -1)
			       exit(EXIT_FAILURE);
	//       	exit(EXIT_SUCCESS);
	}

	MyThread(const MyThread&) = delete;

	~MyThread()
	{
		if(joinable() == true)
			std::terminate();
	}

	MyThread& operator=(const thread&) = delete;

	MyThread& operator=(MyThread&& other)
	{
		if(joinable())
			std::terminate;
		swap(other);
		return *this;
	}

	void join()
	{
		if (joinable() == false)
			exit(EXIT_FAILURE);
	}

	void swap(MyThread& other)
	{
		//TODO
		std::swap(thread_id, othrer.get_id());
	}

	bool joinable() const
	{
		return !(get_id() == MyThread::id());
	}

	MyThread::id get_id() const
	{
		return thread_id;
	}

};


