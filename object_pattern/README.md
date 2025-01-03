# Object Pattern

Context is passed as paramter. 
- We use `self` parameter to access all data that belongs to the 
object upon which a function operates.

Data is never access globally
- any global or singleton data is never accessed directly but 
instead is accessed through singleton methods.

Functions do not have static data. 
- All data is part of the object being operated on. There is no 
static stata in object methods. Data is either part of the object.

Data flows along call path. 
- This is an important feature that ensures we have clear boundaries 
between methods that use particular data. This is incredibly useful 
for multi-threaded environments because it makes data locking very 
straightforward when needed.

## Use Cases
The object pattern is useful in ALL casses but below are COMMON
use cases to give us a concrete idea of its usage.
1. Grouping data
2. Singleton
3. Abstract interfaces
4. Multi threaded design
5. Opaque handles

## Rules
1. Functions 'act' on objects
Each function needs to act on an object pointed to be a "self" argument.
Any additional parameter passed to the function are there to `modify` the
behaviour being done upon the self object. The self object is the
primary object being changed and also the place where results are stored.
Any output variables can be passed as arguments and such data is considered
exported from the object and becomes the responsibility of the caller
once the function returns.
2. Functions are prefixed with object name
Each function that operates on an object should be prefixed with the type
name of that object and also placed in a file with the same name (Though
this is not a strict rule). This is for clean organization and clarity
when reading the code. 

## Reentrancy
This means we can call the function that is reentrant in multiple threads
and we can expect that the function safely produces the same result 
provided that the function is passed the same input arguments. To achieve
reentrancy in functions, the following must be true:
1. No global static data access
2. No self-modifiable code
3. No contamination

## Benefits
1. Clear scope
2. Reentrancy
3. Easy locking
4. Simplified testing
5. Clear data flow

## Drawbacks
1. No ability to hide implementation
Struct private fields are exposes. This adds dependencies to the code using
our struct. We can only hide implementation by using an extension of this
pattern such as the singleton pattern or heap object pattern
2. Can result in high memory consumption
Sometimes it is necessary to declare static structures inside a C file - for
example when you need to share some data between all instances of a particular
object. This warrants occasional mix of the object pattern with singleton 
pattern internally where a part of the object implementation is in fact a
singleton.

## Extern variables
If you see extern variables, it is very bad code that is poorly designed. 
Any function that uses the extern variable is not reentrant and should not
be used in multithreaded environments.
