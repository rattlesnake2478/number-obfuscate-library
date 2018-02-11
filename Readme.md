# Number Obfuscator library
This library obfuscates integer numbers with using predefined value and unknown variable.

## Requirements
  - Ubuntu system (built on Ubuntu 17.10)
  - make
  - cmake > 3.9
  - gcc > 7.2.0
  - libmatheval
  - libboost
  
## Installation
  - git clone https://github.com/rattlesnake2478/number-obfuscate-library.git
  - cd number-obfuscate-library/build && cmake .. && make
  - make test
  - make install (optional)
  
## Using
By default library is built as shared object. Just include library header and link library to the executable.
Then construct library object and call generateStrin method with required value.  
`auto numberObfuscate = new RSnake::NumberObfuscate();`   
`std::cout << numberObfuscate->generateString(64)<< ";" << std::endl;`  
You can also pass some configuration into library constructor. See examples folder for additional information.