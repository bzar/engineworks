EngineWorks
===========

EngineWorks is a structural framework for applications geared toward games design-wise. 
It is not an entire application framework nor a game engine, but provides a structure for creating them.


Concepts
--------

EngineWorks (EW from now on) is conceptually divided into the *Engine*, *States*, *Phases*, *Roles* and *Interceptors*.

A *role* is simply an interface an application entity implements. This can be any interface and has no requirements.

*States* provide a role registration service for application entities and usually manage them. 
Each state has a sequence of phases that are executed in order each time the state is processed.
States subclass `ew::State`.

*Phases* are the functional units of EW, and are usually tied to entities with specific roles. 
A typical phase requests application entities that have registered specific roles and work on them using
the role's interface. Phases can do other things as well, like managing a game world or handling I/O.
Phases subclass `ew::Phase`.

The *engine* manages the state machine and application-wide state. Each time the engine is advanced by the application, 
the engine first runs before-methods for each interceptor in insertion order, then processes the current state,
and finally runs the after-methods for each interceptor in reverse insertion order. 
The engine is provided as `ew::Engine`.

*Interceptors* are simply objects that implement the interceptor interface `ew::Interceptor`.

Example
-------

A simplish example application making use of EW and some of its builtin modules can be found 
[here](https://github.com/bzar/rectcollider/).
