#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>

/*
 * The Process Control Block is used to store information about a process.
 */
struct Pcb {
    int pid;
    int priority;
};

/* TODO: Implement */
/*
 * The Resource Control Block is used to store information about a resource.
 */
struct Rcb {
	int rid;
	int status;
};

/*
 * Doubly linked list that stores different control blocks.
 */
template <typename ControlBlock>
struct Queue {
	Queue *next;
	Queue *prev;

	ControlBlock controlBlock;
};

/*
 * Simulated kernel with different process operations.
 */
class Kernel {
public:
	Kernel() {
		/* Start with empty queues. */
		this->systemQueueHead = nullptr;
		this->userQueueHead = nullptr;
		this->resourceQueueHead = nullptr;
	}

	Queue<Rcb> *getResourceQueueHead() {
		return this->resourceQueueHead;
	}

	void setResourceQueueHead(Queue<Rcb> *queueHead) {
		this->resourceQueueHead = queueHead;
	}

	Queue<Pcb> *getUserQueueHead() {
		return this->userQueueHead;
	}

	void setUserQueueHead(Queue<Pcb> *queueHead) {
		this->userQueueHead = queueHead;
	}

	Queue<Pcb> *getSystemQueueHead() {
		return this->systemQueueHead;
	}

	void setSystemQueueHead(Queue<Pcb> *queueHead) {
		this->systemQueueHead = queueHead;
	}

	/*
	 * Push the process control block to the given queue.
	 */
	Queue<Pcb> *push(Queue<Pcb> *queueHead, Pcb pcb) {
		Queue<Pcb> *newNode = nullptr;
		newNode = new Queue<Pcb>;
		newNode->controlBlock = pcb;

		if (queueHead == nullptr) {
			newNode->next = nullptr;
			newNode->prev = nullptr;

			return newNode;
		} else {
			Queue<Pcb> *current = queueHead;

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = newNode;
			newNode->prev = current;
			newNode->next = nullptr;
		}

		return queueHead;
	}

	/*
	 * Pop the process control block from the given queue.
	 */
	Queue<Pcb> *pop(Queue<Pcb> *queueHead) {
		if (queueHead == nullptr) {
			return nullptr;
		} else if (queueHead->next == nullptr) {
			delete queueHead;

			return nullptr;
		}

		Queue<Pcb> *current = queueHead;

		current = current->next;
		current->prev = nullptr;
		delete queueHead;

		return current;
	}

	/*
	 * Iterates over the given queue to display each process control block.
	 */
	void display(Queue<Pcb> *queueHead) {
		if (queueHead == nullptr) {
			std::cout << "The queue is empty" << std::endl;

			return;
		}

		Queue<Pcb> *current = queueHead;

		while (current != nullptr) {
			std::cout << std::string(this->LINE_WIDTH, this->LINE_CHAR) << std::endl;
			std::cout << "PID: " << current->controlBlock.pid << std::endl;
			std::cout << "Priority: " << current->controlBlock.priority << std::endl;

			current = current->next;
		}

		std::cout << std::string(this->LINE_WIDTH, '-') << std::endl;

		return;
	}

private:
	/* Width of lines to be used for display. */
	static const int LINE_WIDTH = 20;
	/* Character to be used for displaying lines. */
	static const char LINE_CHAR = '-';

	Queue<Pcb> *userQueueHead;
	/* TODO: Implement */
	Queue<Pcb> *systemQueueHead;
	/* TODO: Implement */
	Queue<Rcb> *resourceQueueHead;

};

#endif
