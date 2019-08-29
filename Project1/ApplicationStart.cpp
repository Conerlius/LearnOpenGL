#include <iostream>
#include "OpenGL_Session1.h"
using namespace std;
string Sessions[] = { "OpenGL_Session1", "OpenGL_Session2" };

int main() {
	OpenGL_Session1* session = new OpenGL_Session1();
	return session->Start();
}