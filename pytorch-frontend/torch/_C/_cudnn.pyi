from enum import Enum

from torch.types import Tuple, Number, _bool

# Defined in torch/csrc/cuda/shared/cudnn.cpp
is_cuda: _bool

def getRuntimeVersion() -> Tuple[int, int, int]: ...
def getCompileVersion() -> Tuple[int, int, int]: ...
def getVersionInt() -> int: ...

class RNNMode(int, Enum):
    value: int
    rnn_relu = ...
    rnn_tanh = ...
    lstm = ...
    gru = ...