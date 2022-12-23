class FFT:
    LENGTH_32: int
    LENGTH_64: int
    LENGTH_128: int
    LENGTH_256: int
    LENGTH_512: int
    # LENGTH_1024: int
    # LENGTH_2048: int
    # LENGTH_4096: int
    def __init__(self): ...
    def rfft(self, inputList: list, length: int) -> list: ...


class Complex:
    def mag(self, inputList: list, num: int) -> list: ...


class Hamming:
    def getFactors(self, N: int) -> list: ...

