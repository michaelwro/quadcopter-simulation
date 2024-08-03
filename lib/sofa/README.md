# Standards of Fundamental Astronomy (SOFA)

**DISCLAIMER:** Developers of this project _shall **not** modify the SOFA source code._ SOFA is a third party library developed by the International Astronomical Union (IAU). The sources in this project were directly sourced from the SOFA project's [download page](http://www.iausofa.org/2023_1011_C.html), unmodifyed.

## How to set up SOFA

Download the C source code's tarball for release **2023-10-11** at [THIS LINK](http://www.iausofa.org/2023_1011_C.html).

```shell
wget http://www.iausofa.org/2023_1011_C/sofa_c-20231011.tar.gz
```

In the same directory of this README, unzip the tarball you downloaded. It will extract into a folder named `sofa/`.

```shell
tar -xzvf sofa_c-20231011.tar.gz
```

## CMake Integration

The CMake file included here builds all the SOFA sources into a static library `libsofa.a`. This CMake file is called by the parent project `add_subdirectory(lib/sofa/)` and uses the `sofa` target as a dependency.

The `${sofa_INCLUDE_DIRECTORY}` variable is used by the parent project to get the main SOFA header. Code would include SOFA as:

```c
#include "sofa.h"
```

**NOTE:** SOFA already has the `#ifdef __cplusplus` and `extern "C" {` statements in `#include "sofa.h"`.
