#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace filesystem;

string projectName;

void directories();
void createMain();
void createMakefile();

int main(int argc, char** argv){

	//code
	
	cout << "-----------------------------------" << endl;
	cout << "ASPM - A Simple Project Maker (C++)" << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "Enter project name: ";
	cin >>	projectName;
	cout << endl;

	cout << "Creating directories.." << endl;
	cout << "----------------------" << endl;
	cout << endl;
	directories();
	cout << endl;

	cout << "Creating main.cpp file" << endl;
	cout << "----------------------" << endl;	
	cout << endl;
	createMain();

	cout << "Creating Makfile" << endl;
	cout << "----------------" << endl;
	cout << endl;
	createMakefile();	
	cout << endl;

	cout << "Successfully initialized " << projectName << " project!" << endl;
	cout << endl; 

	return EXIT_SUCCESS;
}

void directories(){
	//var
	string srcPath = projectName + "/src";
	string incPath = projectName + "/include";

	//create Project directory
	create_directory(projectName);

	//create src directory
	create_directory(srcPath);
	cout << "Created: " <<srcPath << endl;

	//create include directory
	create_directory(incPath);
	cout << "Created: " << incPath << endl;
}


void createMain(){
	//var
	string mainPath = projectName + "/main.cpp";

	string code =
	"#include <iostream>"
	"\n"
	"\n"
	"using namespace std;"
	"\n"
	"\n"
	"int main(int argc, char** argv){"
	"\n"
	"	return EXIT_SUCCESS;"
	"\n"
	"}";

	ofstream mainFile(mainPath);

	//code
	if(mainFile.is_open()){
		mainFile << code;
		mainFile.close();
	}

	else{
		cerr << "Error creating file!" << endl;
	}
}


void createMakefile(){
	//var
	string makePath = projectName + "/Makefile";

	string code =
	"libs := \n"
	"\n"
	"compile:\n"
	"	g++ -I include -c src/*.cpp $(libs)\n"
	"	g++ -I include -c main.cpp $(libs) -o main.o\n"
	"	g++ $(libs) -o " + projectName + " *.o\n"
	"	rm *.o\n"
	"\n"
	"run:\n"
	"	./" + projectName + "\n"
	"\n"
	"debug:\n"
	"	make compile\n"
	"	make run\n"
	"\n"
	"remove:\n"
	"	rm " + projectName + "\n"
	"	clear\n"
	"\n"
	"clean:\n"
	"	rm *.o\n"
	"	clear\n";

	ofstream makeFile(makePath);

	//code
	if(makeFile.is_open()){
		makeFile << code;
		makeFile.close();
	}

	else{
		cerr << "Error creating Makefile" << endl;
	}
}
