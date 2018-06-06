
//======================================<br />
**Outline** <br />
//======================================<br />


Links | 
------------- |------
https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/common_runtime/direct_session.cc  |
https://github.com/tensorflow/tensorflow/blob/master/tensorflow/core/common_runtime/executor.cc |


Good projects |       
------------- |-----
tensorflow |


Structure     |
------------- |----
core/ contains the main C++ code and runtimes. | 
core/ops/ contains the "signatures" of the operations |
core/kernels/ contains the "implementations" of the operations (including CPU and CUDA kernels) |
core/framework/ contains the main abstract graph computation and other useful libraries | 
core/platform/ contains code that abstracts away the platform and other imported libraries (protobuf, etc) | 
TensorFlow relies heavily on the Eigen library for both CPU and GPU calculations.  Though some GPU kernels are implemented directly with CUDA code. | 
bazel builds certain C++ code using gcc/clang, and certain CUDA code (files with extension .cu.cc) with nvcc. |
python/ops/ contain the core python interface |
python/kernel_tests/ contain the unit tests and lots of example code |
python/framework/ contains the python abstractions of graph, etc, a lot of which get serialized down to proto and/or get passed to swigged session calls. |
python/platform/ is similar to the C++ platform, adding lightweight wrappers for python I/O, unit testing, etc. |
contrib/*/ directories generally mimic the root tensorflow path (i.e., they have core/ops/, etc) |




