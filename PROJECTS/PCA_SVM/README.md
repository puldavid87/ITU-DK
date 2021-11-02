# ML implementation in Arduino environment
## PCA and SVM algorithms are exported from python to compile in Arduino

### Dataset:

 This dataset presents an intelligent electronic system to detect a person's posture when sitting in a wheelchair. The primary use of the proposed system is to warn an improper posture to prevent major health issues. Available in:
[Wheelchair human position](https://ieee-dataport.org/open-access/data-set-wheelchair-sensors).
Main python library and more information in: [Eloquentarduino] (https://eloquentarduino.github.io/)

### First steps:
Please, read and follow the python code in this repositorie.

### Python code: 
```
#Libraries
from micromlgen import port
```
# ML Arduino code

Follow this repositorie:
[Supervised ML algorithms](https://github.com/puldavid87/ITU-DK/tree/main/SUPERVISED%20MACHINE%20LEARNING)

Before to deploy ML algorithms, normalize the income data
* y = (x – min) / (max – min)

PCA.h and SVM are export models
