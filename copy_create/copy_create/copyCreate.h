#ifndef copyCreate
#define copyCreate
#include <string>

class Student {

	private:
		int sID;
		std::string sName;
	public:
		Student(int id,const char* name);
		Student(const Student& obj);
		void show();
};


#endif
