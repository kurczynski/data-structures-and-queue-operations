# data-structures-and-queue-operations

#### CS 433: Operating Systems

Every kernel and higher-level object in the Operating System (OS) is normally
represented by a data structure containing it basic state, identification,
accounting and other information. Thus there are data structures for each active
object, such as a process or thread. For this part of the kernel you will
implement the data structures and queue operations to simulate how the various
processes are represented by the operating system.

Each process is represented by a data structure called the process control block
(PCB), the following data structures are needed for the process control block
PCB:
* PID is a unique process identifier by which the process may be referred to by other processes.
* Resources jointly represents all resources that have been requested by and currently allocated to that process, implemented as a linked list.
* Status consists of two subfields, Type and List. Type is one of ready, running or blocked. The field List points to either the Ready Lists or one of the Waiting Lists, depending on the process. This field intended as a place holder for now, which will be used later.
* Creation_Tree also consists of two subfields, Parent and Child. The parent of any process is recorded in the Parent field.  The Child field identifies all direct offspring of a process, by pointing to a linked list of their PCB’s. This filed is also is also intended as a place holder for now, which will be used later.
* Priority is the process priority and is used by the Scheduler to decide which process should be running next. The priority is represented by an in integer and is static.

Each resource that a process can use is represented by a data structure called the resource control block (RCB). Examples of these resources are printers, terminals, disk units and other devices. All resources can only be used by one process at a time. An RCB consists of the following fields:
* RID a unique resource identifier by which the resource may be referred to by a process.
* Status indicates the resource is currently free or allocated to another process.
* Waiting_List is a list of processes blocked on this resource. These are all the processes that have requested the resource but could not obtain it because it is currently being used by another process.
