#include <iostream>
#include <string>

#include "kernel.h"
#include "user_interface.h"

int main(int argc, char *argv[]) {
	UserInterface userInterface;

	userInterface.prompt();

	return 0;
}
