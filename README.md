# AnyHLS
High-Level Synthesis with Partial Evaluation

## Prerequisites ##
Anyhls requires a working AnyDSL installation. A script to build the [impala](https://github.com/AnyDSL/impala) frontend and [thorin](https://github.com/AnyDSL/thorin) backend as well as the [runtime](https://github.com/AnyDSL/runtime) component is provided by the [anydsl metaproject](https://github.com/AnyDSL/anydsl) (setup.sh). This script will also checkout AnyHLS's sources and configure a build directory.

## Building ##
The setup.sh configures AnyHLS and sets all required paths. The backend for code generation will be set to ```aocl```. This can be changed via CMake:
* ```BACKEND``` : defines the backend to generate code for (supported values: ```aocl```, ```hls```)

Example:
```bash
cd anydsl/anyhls/build
cmake -DBACKEND=aocl ..
make
```
