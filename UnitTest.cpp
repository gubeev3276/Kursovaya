#include <UnitTest++/UnitTest++.h>
#include "mdfile.h"
using namespace std;

struct things_fixture{
    Server * pointer;
    things_fixture(){
        pointer = new Server();
    }
    ~things_fixture(){
        delete pointer;
    }
};

struct brauth{
	auth * a;
	brauth(){
 	a = new auth();
 	}
 	~brauth(){
 	delete a;
 	}
};

SUITE(serv)
{

    TEST_FIXTURE(things_fixture, Auth){
        pointer->port = 33333;
        pointer->file_name = "base.txt";
		pointer->error_name = "error";
        CHECK(true);
    }
    TEST_FIXTURE(things_fixture, Acces){
        CHECK(true);}

	TEST_FIXTURE(things_fixture, Wrong_SA_I){
        pointer->port = 33333;
		pointer->file_error = "error.txt";
        CHECK_THROW(pointer->self_addr("123y", "error.tx",  213123142),error_server);
    }
	TEST_FIXTURE(things_fixture, Wrong_Sock){
		pointer->file_error = "error.txt";
 		CHECK_THROW(pointer->client_addr(-2, "err", "error.txt"),error_server);
 	}  
 	TEST_FIXTURE(things_fixture, Wrong_Sock2){
		pointer->file_error = "error.txt";
 		CHECK_THROW(pointer->client_addr(-2, "error #2", "error.txt"),error_server);
 	}  
 
}

SUITE(auth){
TEST_FIXTURE(brauth, Wrong_BD){
		a->file_name = "base.txt";
		a->file_error = "error.txt";
		a->work_sock = -1;
        CHECK_THROW(a->autorized(-1, "base.txt",  "error.txt"),error_server);
    }
TEST_FIXTURE(brauth, Wrong_BD1){
		a->file_name = "base.txt";
		a->file_error = "error.txt";
		a->work_sock = -1;
        CHECK_THROW(a->autorized(2, "bwwase.txt",  "error.txt"),error_server);
    }
TEST_FIXTURE(brauth, Wrong_BD2){
		a->file_name = "base.txt";
		a->file_error = "error.txt";
		a->work_sock = -1;
        CHECK_THROW(a->autorized(2, "base.txt",  "errsdor.txt"),error_server);
}
}	
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
/*
g++ -Wall -Ofast UnitTest.cpp mdfile.cpp -o Test -lcrypto++ -lUnitTest++

g++ -Wall -Ofast main.cpp mdfile.cpp  -o main -lcrypto++*/
