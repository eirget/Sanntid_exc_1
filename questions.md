Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
> Using concurrency, you are not actually executing taks at the same exact moment in time but you manage several taks at the same time by rapidly switching between them so that one does not have to execute before the other. This can all be done on the same cpu core, but it looks like parallelism.  Parallelism means actually executing tasks at the same time, in parallel, by using several CPUs or cores at the same time. The actual tasks are split into smaller subtasks that can be run in parallel without issues.

What is the difference between a *race condition* and a *data race*? 
> A race contidion is when the time at which an event occurs affects the result of the exeution, two threads that try to access the same resource at the same time. Data race is when one thread accesses an object that another thread is writing to, a read as the same time as a write. 
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> Scheduling is "the action of assigning resources to perform tasks." It manages which thread should get the CPU.


### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
> We use multiple threads so that different tasks can be executed at the same time. This can be done by rapidly switching between taks so that one task does not have to finish before the next is started, or by actually having several cores working in parallel on different tasks. In real-time systems multiple threads are very useful, since they make it so that you can deal with nre incoming tasks without interrupting what you were already doing.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> Coroutines are (at least in go) lightweight threads, green threads are threads that are managed by the application (runtime in go) instead of the operating system. They are a bit faster scince they work in a way that makes a lot of the steps in regular threads unneccesary.

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> Many problems are easier to solve with concurrency, it can be hard to learn it at first but after that it is a great resource. You get improved performance and the possibility to keep track of several real-time signals, but concurrent programs can also have non-deterministic behaviour and you can get bugs that are very difficult to solve.

What do you think is best - *shared variables* or *message passing*?
> It depends on what important considerations ypu need to take in your program. If safety is important you should use message passing, but if not it is probably faster to use shared variables for example.


Thinking about elevators

Responsiveness
