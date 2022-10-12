# Oopsilon

*"Object-Oriented Programming System Intended for Local Or Networked systems"*

Oopsilon is an object-oriented programming environment which can run either
directly on 64-bit PCs, or hosted as an app atop GNU/Linux or BSD systems.

Its programming language is Valutron - a Smalltalk dialect. Valutron belongs
genetically to the LittleSmalltalk family by its descent from LittleSmalltalk
V3, and the image is based on it, but the virtual machine is mostly novel,
taking the form of a register machine modified with an accumulator to act as the
implicit operand and destination of instructions. The Ravenbrook Memory Pool
System is used to manage the object memory and provide tracing garbage
collection.


### Repository Structure

- `vmm/` - Virtual Machine Manager - the kernel written in C++. Includes the
  Valutron interpreter.
    - `vmm/$arch` - architecture-specific code (arch can = amd64 or hosted)
    - `vmm/mps` - the Ravenbrook memory pool system