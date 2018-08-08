# Abstract-VM
## Project from C++ branch in school 42
### Abstract-VM is the virtual machine that can interpret programs written in a basic assembly language.
That programme is just do the arithmetic and some compare operations with two first values on the stack. Seems like a **UNIX command dc**.

## Assemply language
### Very simple assembler language that a virtual machine understands. Otherwise, the programme will throw an exception.
| Instruction  |  Details |
|---|---|
| **push _value_**  | Pushes the value at the top of the stack. The _value_ must have one of the following form: <ul><li>int8(n) : Creates an 8-bit integer with value n.</li><li>int16(n) : Creates a 16-bit integer with value n.</li><li>int32(n) : Creates a 32-bit integer with value n.</li><li>float(z) : Creates a float with value z.</li><li>double(z) : Creates a double with value z.</li></ul>|
| **pop**  | Unstacks the value from the top of the stack. |
|  **dump**  |  Displays each value of the stack, from the most recent one to the oldest one. |
| **assert _value_** |  Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction. |
| **more _value_** |  Asserts that the value at the top of the stack is less to the one passed as parameter for this instruction. |
| **less _value_** |  Asserts that the value at the top of the stack is more to the one passed as parameter for this instruction. |
| **add**  |  Unstacks the first two values on the stack, adds them together and stacks the result. |
| **sub** |  Unstacks the first two values on the stack, subtracts them, then stacks the result. |
| **mul** |  Unstacks the first two values on the stack, multiplies them, then stacks the result. |
| **div** |  Unstacks the first two values on the stack, divides them, then stacks the result. |
| **mod** | Unstacks the first two values on the stack, calculates the modulus, then stacks the result. |
| **print** | Asserts that the value at the top of the stack is an 8-bit integer. (If not, exception will be thrown), then interprets it as an ASCII value and displays the corresponding character on the standard output. |
| **max** | Prints the maximum value on the stack. |
| **min** | Prints the minimum value on the stack. |
| **debug** | Prints the information about how many and which types on the stack. |
| **exit** | Terminate the execution of the current program. |
| **Some additional comments** | Comments start with a ’;’ and finish with a newline. |

## Usage Examples
### Read from standard input. To end input enter - ’;;’ special symbol.
![](https://thumbs.gfycat.com/LinearRareIndochinahogdeer-size_restricted.gif)
***
### Read from file.
![](https://thumbs.gfycat.com/ColorfulNaturalElectriceel-size_restricted.gif)

[more info](https://github.com/prippa/Abstract-VM/blob/master/abstract-vm.en.pdf)
