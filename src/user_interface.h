#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>
#include <string>

#include "kernel.h"

/*
 * Handles everything for user input and output.
 */
class UserInterface {
public:
	void prompt() {
		std::string option = "";

		do {
			std::cout
				<< "\n"
				<< "Select an option\n"
				<< "1) Add user process\n"
				<< "2) Remove user process\n"
				<< "3) Display user processes\n"
				<< "4) Exit\n"
				<< std::endl;

			std::cout << "Option: ";
			std::cin >> option;

			switch (std::stoi(option)) {
				case 1:
					this->addUserProcess();
					std::cout << "Added process" << std::endl;

					break;
				case 2:
					this->removeUserProcess();
					std::cout << "Removed process" << std::endl;

					break;
				case 3:
					this->displayUserProcesses();

					break;
				case 4:
					std::cout << "Exiting..." << std::endl;
					break;

				default:
					std::cerr << "Invalid selection" << std::endl;
			}
		} while (option != "4");
	}

private:
	Kernel kernel;

	/* Prompt the user for the information needed in the process control block. */
	Pcb promptPcb() {
		Pcb pcb;
		std::string inputBuffer;

		std::cout << "PID: ";
		std::cin >> inputBuffer;
		pcb.pid = std::stoi(inputBuffer);

		std::cout << "Priority: ";
		std::cin >> inputBuffer;
		pcb.priority = std::stoi(inputBuffer);

		return pcb;
	}

	/* Add a process to the user queue. */
	void addUserProcess() {
		Pcb pcb = this->promptPcb();

		Queue<Pcb> *userQueueHead = this->kernel.getUserQueueHead();
		userQueueHead = this->kernel.push(userQueueHead, pcb);
		this->kernel.setUserQueueHead(userQueueHead);
	}

	/* Remove a process from the user queue. */
	void removeUserProcess() {
		Queue<Pcb> *userQueueHead = this->kernel.getUserQueueHead();
		userQueueHead = this->kernel.pop(userQueueHead);
		this->kernel.setUserQueueHead(userQueueHead);
	}

	/* Display the processes in the user queue. */
	void displayUserProcesses() {
		this->kernel.display(this->kernel.getUserQueueHead());
	}
};

#endif
