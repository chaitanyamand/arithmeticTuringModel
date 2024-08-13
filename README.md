# Large Number Arithmetic Turing Machine

## Project Overview

This project implements a Turing machine capable of performing arithmetic operations, specifically multiplication and factorial calculations, on large numbers that exceed the computational limits of traditional computer arithmetic logic units (ALUs). The system demonstrates the theoretical capabilities of Turing machines in handling computations that might be intractable for conventional computers due to processing power constraints.

## Key Components

1. **User Input and Tokenization**: Accepts and tokenizes arithmetic expressions.
2. **Parsing and Grammar Validation**: Processes tokenized input using an operator precedence parser.
3. **Evaluation and Computation**: Evaluates expressions following operator precedence rules.
4. **Turing Machine Implementation**: Core component for unary arithmetic calculations.

## Features

- Handles multiplication (*) and factorial (!) operations
- Processes arbitrarily large integers
- Implements an operator precedence parser
- Utilizes a Turing machine for computations

## Advantages

1. **Unlimited Precision**: Handles numbers of any size without overflow or precision loss.
2. **Theoretical Completeness**: Demonstrates the computational universality of Turing machines.
3. **Practical Application of Theoretical Concepts**: Showcases the power of theoretical computing models.

## Installation

1. Clone the repository:
`git clone https://github.com/chaitanyamand/arithmeticTuringModel.git`

2. Navigate to the project directory:
`cd arithmeticTuringModel`

## Usage

1. Navigate to the `code` folder:
`cd code`
2. Create an `input.txt` file in the `code` folder and input your arithmetic expression.
3. Compile and run the C++ code:
g++ index.cpp -o arithmetic_turing_machine
./arithmetic_turing_machine


## Grammar

The project uses the following grammar:

G = ( {S}, { intlit, *, !, (, ) }, { S->intlit, S->(S), S->S!, S->S*S }, S)

Where:
- S is the start symbol
- intlit represents integer literals
- *, !, (, ) are terminals representing multiplication, factorial, and parentheses respectively
- The production rules are:
  - S -> intlit
  - S -> (S)
  - S -> S!
  - S -> S*S

## Implementation Details

### Turing Machine

The Turing machine implementation uses an infinite tape divided into cells, each containing a symbol from a finite alphabet. It manipulates these symbols based on a set of rules to perform unary arithmetic calculations.

### Parsing Algorithm

The operator precedence parser analyzes the expression's structure and validates it against the predefined grammar. It then evaluates the expression by following the rules of operator precedence.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or feature requests.
